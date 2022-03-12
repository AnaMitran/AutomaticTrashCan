import serial
import time
import os

ser = serial.Serial('COM4', 9600)

f = open("file.txt", "r")
if f.read() == 'H':
    print("high" )
else:
    print("nothing")

def led_on_off():
    f = open("file.txt", "r")
    if f.read() == 'H':
        print("on...")
        time.sleep(1) 
        ser.write(b'H') 
        led_on_off()
    else:
        print("off...")
        time.sleep(1)
        ser.write(b'L')
        led_on_off()

time.sleep(2) # se asteapta initializarea

led_on_off()