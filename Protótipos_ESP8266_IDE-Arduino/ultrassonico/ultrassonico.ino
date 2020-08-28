#include <ESP8266WiFi.h>
#include "UbidotsMicroESP8266.h"

#define ID_ULTRASOM "5882a7ca7625421e8a50cf6d"
#define TOKEN "Lt2yEE66p9BKSl3pwXMtZ9n5WrKqSf"

const char* ssid = "GVT-C61B";
const char* senha = "c116e0c64b";

Ubidots cliente(TOKEN);

float v=331.5+0.6*20;

void setup() {
  pinMode(12, INPUT); //pino que recebe o sinal 
  pinMode(13, OUTPUT); //pino que envia o sinal
 
  Serial.begin(115200);
  delay(10);
  Serial.print("Conectando a rede:");
  Serial.println(ssid);
  WiFi.begin(ssid, senha);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");
}
float distancia(){
  digitalWrite(13, LOW);
  delayMicroseconds(3);
  digitalWrite(13, HIGH);
  delayMicroseconds(5);
  digitalWrite(13, LOW);

  float tUs = pulseIn(12, HIGH); 
  float t = tUs /1000.0/1000.0/2; 
  float d = t*v; 
  return d*100;
}
void loop() {
  int d = distancia();
  //valor_presenca = 0;
  cliente.add(ID_ULTRASOM, d);  
  cliente.sendAll();
  Serial.print("distancia:");
  Serial.println(d);
  delay(100);
}
