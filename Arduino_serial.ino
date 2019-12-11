#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial serial(5,6);  // (Rx, Tx)
 
void setup() {
serial.begin(9600);
}

void enviarDatos(){
  StaticJsonBuffer<1000> jsonBuffer;
 JsonObject& Objetojson = jsonBuffer.createObject();
  Objetojson["humedad"] = 35.5;
  Objetojson["temperatura"] = 143.4;
  if(serial.available()>0){
 Objetojson.printTo(serial);
 } 
}

void loop() {
  enviarDatos();
  delay(1500);
}
/*D6 ---6
 *D5 ---5 
 */
