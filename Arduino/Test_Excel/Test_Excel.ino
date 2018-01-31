
void setup() {
Serial.begin(9600); //Velocidad de comunicacion Xbee
}

void loop() {
  if(Serial.available() > 21){ //Inicio de programa Xbee
    if(Serial.read() == 0x7E){ //Frame de inicio
      for(int i=1;i<19;i++){
        byte discardByte=Serial.read();
      }
    int analogMSB0=Serial.read(); //Bit mas significativo0
    int analogLSB0=Serial.read(); //Bit menos significativo0
    delay(50);
    int analogMSB1=Serial.read(); //Bit mas significativo1
    int analogLSB1=Serial.read(); //Bit menos significativo1
    delay(50);
    int analogMSB2=Serial.read(); //Bit mas significativo2
    int analogLSB2=Serial.read(); //Bit menos significativo2
    delay(50);
    int analogMSB3=Serial.read(); //Bit mas significativo3
    int analogLSB3=Serial.read(); //Bit menos significativo3
    delay(50);
    float analogReading0=analogLSB0+(analogMSB0*256); //Escala 0-1023
    float analogReading1=analogLSB1+(analogMSB1*256); //Escala 0-1023
    float analogReading2=analogLSB2+(analogMSB2*256); //Escala 0-1023
    float analogReading3=analogLSB3+(analogMSB3*256); //Escala 0-1023
    
   analogReading0 = map(analogReading0, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs
   analogReading1 = map(analogReading1, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs
   analogReading2 = map(analogReading2, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs
   analogReading3 = map(analogReading3, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs

    //No usar delay en IDE, el tiempo de muestra se programa desde XCTU en HEX
    
 Serial.print(analogReading0);
//  Serial.print(analogReading1);
  // Serial.print(analogReading2);
    //Serial.print(analogReading3);
    
    }
   }    
  }

  

