import serial
import time
from xbee import ZigBee

serial_port = serial.Serial(
               port='/dev/ttyAMA0',
               baudrate = 9600,
               parity=serial.PARITY_NONE,
               stopbits=serial.STOPBITS_ONE,
               bytesize=serial.EIGHTBITS,
               timeout=0.01)

def message_received(data):
     #print(" esto es "+data)
     
     
     source=str(data['source_addr_long'])


     #print (data)
     sensor1=data['samples'][0]['adc-0']
     sensor2=data['samples'][0]['adc-1']
     sensor3=data['samples'][0]['adc-2']
     sensor4=data['samples'][0]['adc-3']
     
#SENSOR 1 MONITOREO Resistencia de 270 ohms

   ##  if(source != 0):
         ## print("si hay conexion")
          
  ##   else:
          
    ##      print("source esta vacio")
     print (sensor1)
   
   ##  if (sensor1>=50 and sensor1<=350):
        ##  print ("Sensor 1:Bajo"+str(sensor1))

    ## elif (sensor1>350 and sensor1<=700):
   ##       print ('Sensor 1:Medio:'+str(sensor1))

   ##  elif(sensor1>700):
      ##    print ('Sensor 1:Alto:'+str(sensor1))

#SENSOR 2 MONITOREO Resistencia de 120 ohms
    
     #print ("Sensor 2:OK:"+str(sensor2))
   
  ##   if (sensor2>=50 and sensor2<=350):
        ##  print ("Sensor 2:Bajo:"+str(sensor2))

  ##   elif (sensor2>350 and sensor2<=700):
      ##    print ('Sensor 2:Medio:'+str(sensor2))

  ##   elif(sensor2>700):
     ##     print ('Sensor 2:Alto:'+str(sensor2))

#SENSOR 3 MONITOREO Resistencia de 33 ohms
     
     #print ("Sensor 3:OK:"+str(sensor3))
  
  ##   if (sensor3>=50 and sensor3<=350):
   ##       print ("Sensor 3:Bajo:"+str(sensor3))

   ##  elif (sensor3>350 and sensor3<=700):
   ##       print ('Sensor 3:Medio:'+str(sensor3))

   ##  elif(sensor3>700):
     ##     print ('Sensor 3:Alto:'+str(sensor3))

#SENSOR 4 MONITOREO
     
     #print ("Sensor 4:OK:"+str(sensor4))
        
   
   ##  if (sensor4>=50 and sensor4<=300):
     ##     print ("Sensor 4:Bajo:"+str(sensor4))
         

    ## elif (sensor4>300 and sensor4<=700):
     ##     print ('Sensor 4:Medio:'+str(sensor4))
         

     ##elif(sensor4>700):
      ##    print ('Sensor 4:Alto:'+str(sensor4))
          



zb = ZigBee(serial_port, callback=message_received)



# Do other stuff in the main thread
while True:
    try:
        time.sleep(1)
    except KeyboardInterrupt:
        break

# halt() must be called before closing the serial
# port in order to ensure proper thread shutdown
xbee.halt()
serial_port.close()
