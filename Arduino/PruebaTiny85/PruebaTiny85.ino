void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  delay(100);
   int sensorValue = analogRead(5);

   if (sensorValue <= 1000) {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  delay(3000);
   }
//  float voltage = sensorValue * (5.0 / 1023.0);
 // Serial.println(voltage);
}
