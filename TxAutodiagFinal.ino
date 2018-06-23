#include <SoftwareSerial.h>

#define CONFIG_GPS_RXPIN 10
#define CONFIG_GPS_TXPIN 11
#define CONFIG_GPS_BAUDRATE 115200

SoftwareSerial ss(CONFIG_GPS_RXPIN, CONFIG_GPS_TXPIN);

String str;
String level = "";
int nodo1 = 5;
int nodo2 = 6;
int nodo3 = 7;
int nodo4 = 8;
int indicador = 13;
int push = 9;  //Se cambia de 9 a 11
int boton = 0;
int contador = 0;

void setup() {
  pinMode(nodo1, OUTPUT);
  pinMode(nodo2, OUTPUT);
  pinMode(nodo3, OUTPUT);
  pinMode(nodo4, OUTPUT);
  pinMode(indicador, OUTPUT);
  pinMode(push, INPUT);
  Serial.begin(CONFIG_GPS_BAUDRATE);
  ss.begin(CONFIG_GPS_BAUDRATE);
}

void loop() {

Serial.println("1");
  digitalWrite(nodo1, LOW);
  digitalWrite(nodo2, LOW);
  digitalWrite(nodo3, LOW);
  digitalWrite(nodo4, LOW);
  digitalWrite(indicador, LOW);

  boton = digitalRead(push);


  if (boton == 1) {
           contador = 0;
    digitalWrite(indicador, HIGH);
    contador = contador + 1;
   // Serial.println(contador);
    for (contador == 1; contador <= 30000; contador++) {
      //Serial.println(contador);
      int ADsensor1 = analogRead(A0);
      int ADsensor2 = analogRead(A1);
      int ADsensor3 = analogRead(A2);
      int ADsensor4 = analogRead(A3);
      if (ADsensor1 >= 300) {
        digitalWrite(nodo1, HIGH);
      }
      if (ADsensor2 >= 300) {
        digitalWrite(nodo2, HIGH);
      }
      if (ADsensor3 >= 300) {
        digitalWrite(nodo3, HIGH);
      }
      if (ADsensor4 >= 300) {
        digitalWrite(nodo4, HIGH);
      }

    }

  }
  Serial.println("2");

  Lecturasensores(A0, A1, A2, A3);
  //delay(350);
}


void Lecturasensores (int sen1, int sen2, int sen3, int sen4) {

  int idnodo1 = 3000;//Identificador Nodo 1
  int idnodo2 = 5000;//Identificador Nodo 2
  int idnodo3 = 7000;//Identificador Nodo 3
  int idnodo4 = 9000;//Identificador Nodo 4
  char lectura1[8]; //String data
  char lectura2[8]; //String data
  char lectura3[8]; //String data
  char lectura4[8]; //String data

  int sensor1 = analogRead(sen1);
  sensor1 = sensor1 + idnodo1; //Suma 3000 para identificar nodo 1
  int sensor2 = analogRead(sen2);
  sensor2 = sensor2 + idnodo2; //Suma 5000 para identificar nodo 2
  int sensor3 = analogRead(sen3);
  sensor3 = sensor3 + idnodo3; //Suma 7000 para identificar nodo 3
  int sensor4 = analogRead(sen4);
  sensor4 = sensor4 + idnodo4; //Suma 9000 para identificar nodo 4

  if (sensor1 >= 3010) {//Filtro de Nodo 1
    str = String(sensor1);
    str.toCharArray(lectura1, 8);
    ss.write(lectura1, 8); //Write the serial data
   // Serial.println(sensor1);
  }
  if (sensor2 >= 5010) {//Filtro de Nodo 2
    str = String(sensor2);
    str.toCharArray(lectura2, 8);
    ss.write(lectura2, 8); //Write the serial data
   // Serial.println(sensor2);
  }
  if (sensor3 >= 7010) {//Filtro de Nodo 3
    str = String(sensor3);
    str.toCharArray(lectura3, 8);
    ss.write(lectura3, 8); //Write the serial data
   // Serial.println(sensor3);
  }
  if (sensor4 >= 9010) {//Filtro de Nodo 4
    str = String(sensor4);
    str.toCharArray(lectura4, 8);
    ss.write(lectura4, 8); //Write the serial data
   // Serial.println(sensor4);
  }
}


