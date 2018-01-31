/*
Takes an input on the AtTiny85 from the VERY TRICKY analogue input pin 2 (as labeled in HLT tutorial)

and outputs these with Software serial to the arduino uno, or Duemillanove

Hookup
ATTINY85 pin 3 -> Arduino Uno pin 0
ATTINY85 pin 4 -> Arduino Uno pin 1

*/


// Definitions
#define rxPin 3
#define txPin 4

//SoftwareSerial mySerial(rxPin, txPin);
NewSoftSerial mySerial(rxPin, txPin);

int sensorPin = 1; //7 PB2 Ain1
int sensorVal = -1;

boolean switchFans = 0;

// the setup routine runs once when you press reset:
void setup() {
pinMode(sensorPin, INPUT);
mySerial.begin(9600);
}

// the loop routine runs over and over asensorpingain forever:
void loop() {

sensorVal = analogRead(sensorPin);
mySerial.print("Input ");
mySerial.print(sensorVal);
mySerial.println();
}
