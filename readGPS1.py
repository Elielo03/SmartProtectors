#!/usr/bin/python
import serial
from xbee import ZigBee
import urllib.request
import geocoder
import pynmea2
import threading
import time
import asyncio



class ThreadingExample(object):
    
    def __init__(self,interval=1):
        self.interval=interval
        thread=threading.Thread(target=self.run,args=())
        thread.daemon=True
        thread.start()

    def run(self):
        while True:
            print("Doing something important")
            getLocation()
            time.sleep(self.interval)


def getLocation():
    serial_port = serial.Serial(
               port='/dev/ttyUSB0',
               baudrate = 9600,
               parity=serial.PARITY_NONE,
               stopbits=serial.STOPBITS_ONE,
               bytesize=serial.EIGHTBITS,
               timeout=1)

    zb = ZigBee(serial_port)
    while 1:
        try:
            line = str(serial_port.readline().decode("utf-8"))
            line2=line.split("\n")
            line3=line.split(",")
        
            if(str(line3[0])=="$GPGGA"):
                msg = pynmea2.parse(line)
                lat=msg.latitude
                lon=msg.longitude
                print(msg.latitude)
                print(msg.longitude)
                return lat,lon
        except ValueError:
            print('catched')

#lat, lon = getLocation()
print("start")
example=ThreadingExample()
time.sleep(3)
print("checked")
time.sleep(2)
print('bye')
#loop=asyncio.get_event_loop()
#loop.run_until_complete(getLocation())
#loop.close()
