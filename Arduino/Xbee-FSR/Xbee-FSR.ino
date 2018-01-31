
void setup() {
Serial.begin(9600); //Velocidad de comunicacion Xbee
}

void loop() {
  if(Serial.available() > 21){ //Inicio de programa Xbee
    if(Serial.read() == 0x7E){ //Frame de inicio
      for(int i=1;i<19;i++){
      byte discardByte=Serial.read();
      }

    int analogMSB0=Serial.read(); //Bit mas significativo
    int analogLSB0=Serial.read(); //Bit menos significativo0
delay(50);
    //int analogMSB1=Serial.read(); //Bit mas significativo1
    //int analogLSB1=Serial.read(); //Bit menos significativo1
  //delay(50);
  /*  int analogMSB2=Serial.read(); //Bit mas significativo2
    int analogLSB2=Serial.read(); //Bit menos significativo2
   // delay(1000);
    int analogMSB3=Serial.read(); //Bit mas significativo3
    int analogLSB3=Serial.read(); //Bit menos significativo3
   // delay(1000);*/
    
    float analogReading0=analogLSB0+(analogMSB0*256); //Escala 0-1023
    //float analogReading1=analogLSB1+(analogMSB1*256); //Escala 0-1023
  /*  float analogReading2=analogLSB2+(analogMSB2*256); //Escala 0-1023
    float analogReading3=analogLSB3+(analogMSB3*256); //Escala 0-1023*/

  // Serial.println(analogReading0); 
   analogReading0 = map(analogReading0, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs
  // analogReading1 = map(analogReading1, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs
  /* analogReading2 = map(analogReading2, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs
   analogReading3 = map(analogReading3, 0, 1023, 21.0, 0.0); //Mapeo a 22 lbs*/

    //No usar delay en IDE, el tiempo de muestra se programa desde XCTU en HEX
    
  /*  Serial.print(analogReading0);
    Serial.println("-ADC0");

   // Serial.print(analogReading1);
    Serial.println("-ADC1");

    Serial.print(analogReading2);
    Serial.println("-ADC2");

    Serial.print(analogReading3);
    Serial.println("-ADC3");*/
    
  // Sensor 1
   if(analogReading0 == 0){
      Serial.print("Sensor1-");
      Serial.print(analogReading0); //Imprime en monitor serial el peso
      Serial.println("-OK");
    } 
    
    if(analogReading0 >= 1 && analogReading0 <= 8){
      Serial.print("Sensor1-");
      Serial.print(analogReading0);
      Serial.println("-lbs (Impacto bajo)");
    }
      if(analogReading0 >= 9 && analogReading0 <= 17){
      Serial.print("Sensor1-");
      Serial.print(analogReading0);
      Serial.println("-lbs (Impacto Medio)");
    }
      if(analogReading0 >= 18){
      Serial.print("Sensor1-");
      Serial.print(analogReading0);
      Serial.println("-lbs (Impacto Alto)");
    }
/*   // Sensor 2 
    if(analogReading1 == 0){
      Serial.print("Sensor2-");
      Serial.print(analogReading1); //Imprime en monitor serial el peso
      Serial.println("-OK");
    } 
    
    if(analogReading1 >= 1 && analogReading1 <= 8){
      Serial.print("Sensor2-");
      Serial.print(analogReading1);
      Serial.println("-lbs (Impacto bajo)");
    }
      if(analogReading1 >= 9 && analogReading1 <= 17){
      Serial.print("Sensor2-");
      Serial.print(analogReading1);
      Serial.println("-lbs (Impacto Medio)");
    }
      if(analogReading1 >= 18){
      Serial.print("Sensor2-");
      Serial.print(analogReading1);
      Serial.println("-lbs (Impacto Alto)");
    }
   /*  // Sensor 2
   if(analogReading2 == 0){
      Serial.print("Sensor3-");
      Serial.print(analogReading2); //Imprime en monitor serial el peso
      Serial.println("-OK");
    } 
    
    if(analogReading2 >= 1 && analogReading2 <= 8){
      Serial.print("Sensor3-");
      Serial.print(analogReading2);
      Serial.println("-lbs (Impacto bajo)");
    }
      if(analogReading2 >= 9 && analogReading2 <= 17){
      Serial.print("Sensor3-");
      Serial.print(analogReading2);
      Serial.println("-lbs (Impacto Medio)");
    }
      if(analogReading2 >= 18){
      Serial.print("Sensor3-");
      Serial.print(analogReading2);
      Serial.println("-lbs (Impacto Alto)");
    }
     // Sensor 3
 /*  if(analogReading3 == 0){
      Serial.print("Sensor4-");
      Serial.print(analogReading3); //Imprime en monitor serial el peso
      Serial.println("-OK");
    } 
    
    if(analogReading3 >= 1 && analogReading3 <= 8){
      Serial.print("Sensor4-");
      Serial.print(analogReading3);
      Serial.println("-lbs (Impacto bajo)");
    }
      if(analogReading3 >= 9 && analogReading3 <= 17){
      Serial.print("Sensor4-");
      Serial.print(analogReading3);
      Serial.println("-lbs (Impacto Medio)");
    }
      if(analogReading3 >= 18){
      Serial.print("Sensor4-");
      Serial.print(analogReading3);
      Serial.println("-lbs (Impacto Alto)");
    }
    */
    }
   }    
  }

  

