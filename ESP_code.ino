/**
   ESP_code.ino
   SmartProtectors
   Este código se carga al modulo ESP8266, que trabaja con un Arduino conectado y corriendo el programa TxAutodiag.ino
   Desarrollado por:
   Ing. Eliel Rodriguez
   Ing. Alejandro Valdes

   Para cargar el código, hacer las siguientes conexiones en un Arduino Uno:

                                              +-----+
                 +----[PWR]-------------------| USB |--+
                 |                            +-----+  |
                 |         GND/RST2  [ ][ ]            |
                 |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |
                 |          5V/MISO2 [ ][ ]  A4/SDA[ ] |
                 |                             AREF[ ] |
                 |                              GND[ ] |
                 | [ ]N/C                    SCK/13[ ] |
                 | [ ]IOREF                 MISO/12[ ] |
      RST to GND | [ ]RST                   MOSI/11[ ]~|
                 | [ ]3V3    +---+               10[ ]~|
     Vcc & CH_PD | [ ]5v    -| A |-               9[ ]~|
                 | [ ]GND   -| R |-               8[ ] |
     GND & GPIO0 | [ ]GND   -| D |-                    |
                 | [ ]Vin   -| U |-               7[ ] |
                 |          -| I |-               6[ ]~|
                 | [ ]A0    -| N |-               5[ ]~|
                 | [ ]A1    -| O |-               4[ ] |
                 | [ ]A2     +---+           INT1/3[ ]~|
                 | [ ]A3                     INT0/2[ ] |
                 | [ ]A4/SDA  RST SCK MISO     TX>1[ ] | TX
                 | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] | RX
                 |            [ ] [ ] [ ]              |
                 |  UNO_R3    GND MOSI 5V  ____________/
                  \_______________________/

  Estas conexiones deben hacerse antes de conectar el Arduino a la computadora
  En Arduino IDE:
  Archivo>>Preferencias>>Gestor de URLs adicionales de tarjetas:http://arduino.esp8266.com/versions/2.4.1/package_esp8266com_index.json
  Reiniciar Arduino IDE
  Herramientas>>Placa>>ESP8266
  Compilar y cargar a Arduino
  Si se hace una modificacion, se debe conectar y desconectar de la PC o mostrara la falla"error:espcomm_upload_mem failed"
  Una vez cargado, se conecta en la placa de SmartProtector


    Creado el: 19.04.2018
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;

int variable1 = 364;
float variable2 = 3.14;
char mystr[8]; //Initialized variable to store recieved data
String mac = "";
String level = "";
String value = "";
int getdata = 0;
int idnodo1 = 9000;//Identificador Nodo 1
int idnodo2 = 7000;//Identificador Nodo 2
int idnodo3 = 5000;//Identificador Nodo 3
int idnodo4 = 3000;//Identificador Nodo 4
int Lowlevel_yellow = 10;//Limite bajo golpes bajos
int Highlevel_yellow = 50;//Limite alto golpes bajos
int Lowlevel_orange= 51;//Limite bajo golpes medios
int Highlevel_orange = 150;//Limite alto golpes medios
int Lowlevel_red= 151;//Limite bajo golpes altos
int Highlevel_red = 200;//Limite alto golpes altos


void setup() {
  USE_SERIAL.begin(115200);
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();
  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }
  WiFiMulti.addAP("SmartProtector_Net", "1234abcd");
}

void loop() {
 // USE_SERIAL.write("hereeeee");
  mac = WiFi.macAddress();
  Serial.println(mac);
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    if (USE_SERIAL.available() > 0) {
      USE_SERIAL.readBytes(mystr, 8); //Read the serial data and store in var
      USE_SERIAL.println("El val es: " + String(mystr));
      level = String(mystr);// string to hold input
      getdata = level.toInt();

      if (getdata >= 3010 && getdata <= 4500) {
        getdata = getdata - idnodo4; //Resta 3000 para identificar nodo 4
        value = String(getdata);
        mac = mac + ":04"; //Identifica Nodo 1 y lo escribe en la mac

        if (getdata >= Lowlevel_yellow && getdata <= Highlevel_yellow) {
          level = "bajo";
        }
        if (getdata >= Lowlevel_orange && getdata <= Highlevel_orange) {
          level = "medio";
        }
        if (getdata >= Lowlevel_red) {
          level = "alto";
        }
      }
      if (getdata >= 5010 && getdata <= 6500) {
        getdata = getdata - idnodo3; //Resta 5000 para identificar nodo 3
        value = String(getdata);
        mac = mac + ":03"; //Identifica Nodo 2 y lo escribe en la mac

        if (getdata >= 100 && getdata <= 350) {
          level = "bajo";
        }
        if (getdata >= 351 && getdata <= 700) {
          level = "medio";
        }
        if (getdata >= 701) {
          level = "alto";
        }
      }
      if (getdata >= 7010 && getdata <= 8500) {
        getdata = getdata - idnodo2; //Resta 7000 para identificar nodo 2
        value = String(getdata);
        mac = mac + ":02"; //Identifica Nodo 3 y lo escribe en la mac

        if (getdata >= 100 && getdata <= 350) {
          level = "bajo";
        }
        if (getdata >= 351 && getdata <= 700) {
          level = "medio";
        }
        if (getdata >= 701) {
          level = "alto";
        }
      }
      if (getdata >= 9010 && getdata <= 10500) {
        getdata = getdata - idnodo1; //Resta 9000 para identificar nodo 1
        value = String(getdata);
        mac = mac + ":01"; //Identifica Nodo 4 y lo escribe en la mac

        if (getdata >= 100 && getdata <= 350) {
          level = "bajo";
        }
        if (getdata >= 351 && getdata <= 700) {
          level = "medio";
        }
        if (getdata >= 701) {
          level = "alto";
        }
      }

      USE_SERIAL.print("[HTTP] begin...\n");
      // configure traged server and url
      //http.begin("https://192.168.1.12/test.html", "7a 9c f4 db 40 d3 62 5a 6e 21 bc 5c cc 66 c8 3e a1 45 59 38"); //HTTPS
      http.begin("http://www.smarthprotectors.com/php/Controller/ControllerIncidence.php?OPC=1&measure_n=" + value + "&keyNode_str=" + mac + "&clasification=" + level + "&idGroup=1"); //HTTP
      USE_SERIAL.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();
      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);
        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          USE_SERIAL.println(payload);
        }
      } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
    mac = "";
    delay(50);
  }
}

