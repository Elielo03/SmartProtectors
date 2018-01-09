

#!/usr/bin/python
import serial
import time
from xbee import ZigBee
import urllib.error  
from urllib.error import HTTPError,URLError
from tkinter import *
from tkinter import font
from tkinter import messagebox
from tkinter import ttk
from tkinter import font  as tkfont # python 3
import urllib.request
import geocoder
import threading
import asyncio
import pynmea2

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
                #print(msg.latitude)
                #print(msg.longitude)
                return lat,lon
        except ValueError:
            print('catched')
     

def message_received(data):
      
    #Lectura de datos
     source=str(data['source_addr_long'])
     sensor1=data['samples'][0]['adc-0']
     sensor2=data['samples'][0]['adc-1']
     sensor3=data['samples'][0]['adc-2']
     sensor4=data['samples'][0]['adc-3']
     #geo = geocoder.ip('me')
     #latitude,longitude = getLocation()
     #longitude = geo.latlng[1]

     print("Running")   
     #Sensor 1
     if (sensor1>=200 and sensor1<=350):    
          medida='bajo'
          latitude,longitude = getLocation()
          upIncidence(str(source+"\\x01"),medida,sensor1,latitude,longitude)
     elif (sensor1>350 and sensor1<=700):          
           medida='medio'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x01"),medida,sensor1,latitude,longitude)
     elif(sensor1>700):         
           medida='alto'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x01"),medida,sensor1,latitude,longitude)

    #Sensor 2 
     if (sensor2>=200 and sensor2<=350):        
          medida='bajo'
          latitude,longitude = getLocation()
          upIncidence(str(source+"\\x02"),medida,sensor2,latitude,longitude)
     elif (sensor2>350 and sensor2<=700):        
           medida='medio'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x02"),medida,sensor2,latitude,longitude)
     elif(sensor2>700):           
           medida='alto'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x02"),medida,sensor2,latitude,longitude)
            
     #Sensor 3
     if (sensor3>=200 and sensor3<=350):
          medida='bajo'
          latitude,longitude = getLocation()
          upIncidence(str(source+"\\x03"),medida,sensor3,latitude,longitude)
     elif (sensor3>350 and sensor3<=700):
           medida='medio'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x03"),medida,sensor3,latitude,longitude)
     elif(sensor3>700):
           medida='alto'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x03"),medida,sensor3,latitude,longitude)
                   
     #Sensor 4
     if (sensor4>=200 and sensor4<=350):
          medida='bajo'
          latitude,longitude = getLocation()
          upIncidence(str(source+"\\x04"),medida,sensor4,latitude,longitude)
     elif (sensor4>350 and sensor4<=700):
           medida='medio'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x04"),medida,sensor4,latitude,longitude)
     elif(sensor4>700):
           medida='alto'
           latitude,longitude = getLocation()
           upIncidence(str(source+"\\x04"),medida,sensor4,latitude,longitude)
          
     
def upIncidence(keyNode,clasification,sensor,lat,lon):
          
     try:
        keyNode_str=keyNode.encode('unicode-escape')
        query_args = {'clasification':clasification,'keyNode_str':keyNode_str,'measure_n':sensor,'lat':lat,'lon':lon}
        url = 'http://smarthprotectors.com/php/Controller/ControllerIncidence.php?OPC=1'
        data = urllib.parse.urlencode(query_args).encode('utf-8')
        request = urllib.request.Request(url,data)
        response = urllib.request.urlopen(request).read()
          
        print (response.decode('utf-8'))

     except HTTPError as e:
          print('The server couldn\'t fulfill the request.')
          print('Error code: ', e.code)
     except URLError as e:
          print('We failed to reach a server.')
          print('Reason: ', e.reason)
     
serial_port = serial.Serial(
               port='/dev/ttyAMA0',
               baudrate = 9600,
               parity=serial.PARITY_NONE,
               stopbits=serial.STOPBITS_ONE,
               bytesize=serial.EIGHTBITS,
               timeout=1)     
zb = ZigBee(serial_port, callback=message_received)



# Do other stuff in the main thread

while True:
    try:
        time.sleep(0.01)
    except KeyboardInterrupt:
        break

# halt() must be called before closing the serial
# port in order to ensure proper thread shutdown
zb.halt()
serial_port.close()



