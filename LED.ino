#include <string.h>
// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
String x;
int Num;
int NUm;
int NUM;
void setup() {
  Serial.begin(115200);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  Serial.setTimeout(3);
}
void setColor(int red, int green, int blue){
    analogWrite(REDPIN, 255-red);
    analogWrite(GREENPIN, 255-green);
    analogWrite(BLUEPIN, 255-blue);
}
int toenails(String numA, String numB, String numC){
  if (numA != "0" && numB != "0" && numC != "0"){
    Num = numA.toInt();
    NUm = numB.toInt();
    NUM = numC.toInt();
    return ((Num * 100) + (NUm * 10) + (NUM));
  } else if (numA == "0" && numB != "0" && numC != "0"){
    NUm = numB.toInt();
    NUM = numC.toInt();
    return ((NUm * 10) + (NUM));
  } else if (numA == "0" && numB == "0" && numC != "0"){
    NUM = numC.toInt();
    return NUM;
  }
}


void loop() {
String rA, rB, rC, gA, gB, gC, bA, bB, bC;
  int R, G, B;
  while (!Serial.available());
  x = Serial.readString();
  rA = x[0];
  rB = x[1];
  rC = x[2];
  R = toenails(rA, rB, rC);
  gA = x[3];
  gB = x[4];
  gC = x[5];
  G = toenails(gA, gB, gC);
  bA = x[6];
  bB = x[7];
  bC = x[8];
  B = toenails(bA, bB, bC);


setColor(R, G, B);
}
// Not outputting solid color and changing rn