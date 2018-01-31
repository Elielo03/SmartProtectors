
void setup() {
Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 21){
    if(Serial.read() == 0x7E){
      for(int i=1;i<19;i++){
        byte discardByte=Serial.read();
      }
    int analogMSB=Serial.read();
    int analogLSB=Serial.read();
    int analogReading=analogLSB+(analogMSB*256);
    float Lecturafinal = map(analogReading, 0, 1023, 0, 10);
    if(analogReading = 10){
      Serial.print(analogReading"-OK");
    }
      if(analogReading = 9 || analogReading = 8){
      Serial.print(analogReading+"-Impacto Bajo");
    }
      if(analogReading = 7 || analogReading = 6 || analogReading = 5){
      Serial.print(analogReading+"-Impacto Medio");
    }
      if(analogReading <= 4){
      Serial.print(analogReading+"-Impacto Alto");
    }
    
  Serial.println(analogReading);
    }
  }
}
