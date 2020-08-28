//descomentar a biblioteca de acordo com seu chip ESP
#include <ESP8266WiFi.h>  //ESP8266
//#include <WiFi.h>         //ESP32

/* Nome da rede e senha */
const char *ssid = "ESP8266";
const char *password = "r68888031120r";
const int channel = 4;

/* Endereços para configuração da rede */
IPAddress ip(192, 168, 0, 2);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);


void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* Você pode remover o parâmetro "password", se quiser que sua rede seja aberta. */
  /* Wifi.softAP(ssid, password, channel); */
  WiFi.softAP(ssid, password, channel);
 
  /* configurações da rede */
  WiFi.softAPConfig(ip, gateway, subnet);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

}

void loop() {
}
