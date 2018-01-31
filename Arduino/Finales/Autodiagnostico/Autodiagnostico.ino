int nodo1 = 5;
int nodo2 = 6;
int nodo3 = 7;
int nodo4 = 8;
int indicador =13;
int push = 9;
int boton = 0;
int contador =0;

void setup() {
  pinMode(nodo1, OUTPUT);
  pinMode(nodo2, OUTPUT);
  pinMode(nodo3, OUTPUT);
  pinMode(nodo4, OUTPUT);
  pinMode(indicador,OUTPUT);
  pinMode(push, INPUT);
  Serial.begin(9600);
}
void loop() {
  
  digitalWrite(nodo1,LOW);
  digitalWrite(nodo2,LOW);
  digitalWrite(nodo3,LOW);
  digitalWrite(nodo4,LOW);
  digitalWrite(indicador,LOW);

  boton = digitalRead(push);
  
 if(boton == 1){
  digitalWrite(indicador,HIGH);
  contador = contador+1;
  for (contador == 1; contador >=500; contador++){
     int sensor1 = analogRead(A3);
     int sensor2 = analogRead(A2);
     int sensor3 = analogRead(A1);
     int sensor4 = analogRead(A0);
     if(sensor1 >=300){
      digitalWrite(nodo1,HIGH);
     }
     if(sensor2 >=300){
      digitalWrite(nodo2,HIGH);
     }
     if(sensor3 >=300){
      digitalWrite(nodo3,HIGH);
      }
     if(sensor4 >=300){
      digitalWrite(nodo4,HIGH);
      }
  }
 }
}
