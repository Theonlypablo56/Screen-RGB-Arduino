# Importing Libraries
import serial
import time
import pyautogui
import math

arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
# its uh time


def write(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.02)
    data = arduino.readline()
    return data


def tran(str):
    while len(str) < 3:
        if len(str) == 3:
            break
        str = ("0" + str)
    return str


while True:
    # getting the screen data
    im = pyautogui.screenshot()
    leftR = []
    leftG = []
    leftB = []
    rightR = []
    rightG = []
    rightB = []
    for y in range(215, 2150, 20):
        for x in range(639, 1917, 20):
            leftR.append((im.getpixel((x, y)))[0])
            leftG.append((im.getpixel((x, y)))[1])
            leftB.append((im.getpixel((x, y)))[2])
    for y in range(215, 2150, 215):
        for x in range(1917, 3834, 639):
            rightR.append((im.getpixel((x, y)))[0])
            rightG.append((im.getpixel((x, y)))[1])
            rightB.append((im.getpixel((x, y)))[2])

    def avg(ray):
        temp = 0
        for num in ray:
            temp += num
        return math.floor(temp/len(ray))
    RGBR = [avg(rightR), avg(rightG), avg(rightB)]
    RGBL = [avg(leftR), avg(leftG), avg(leftB)]
    # creating and sending over the 9 digits
    R = tran(str(RGBL[0]))
    G = tran(str(RGBL[1]))
    B = tran(str(RGBL[2]))
    num = (R + G + B)
    value = write(num)
    print(num)
    time.sleep(.002)
