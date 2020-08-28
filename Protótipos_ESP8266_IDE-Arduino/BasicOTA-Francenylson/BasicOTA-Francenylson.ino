//******************NÃO ALTERAR OU APAGAR ESSES CODIGOS**********************************
//INICIO DOS PROCEDIMENTOS DE BIBLIOTECAS PARA COMUNICAÇÃO/GRAVAÇÃO NO MICROCONTROLADOR
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
const char* ssid = "Nossa Rede 2016";
const char* password = "r68888031120r";
//FIM DOS PROCEDIMENTOS DE BIBLIOTECAS PARA COMUNICAÇÃO/GRAVAÇÃO NO MICROCONTROLADOR
//************************************************************************************


//INICIO DA SUA PROGRAMAÇÃO

#include "ESP8266WiFi.h"      
#include "SSD1306.h"
SSD1306 display(0x3c, D2, D1);
#define trigPin D3
#define echoPin D4
#define buzzerPin D7

// FIM DA SUA PROGRAMAÇÃO


void setup() {

  //INICIO DA SUA PROGRAMACAO DE CONFIGUTAÇÃO AQUI - OPÇÃO 1

  display.init();
  display.flipScreenVertically(); //orientacao do texto
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(trigPin, LOW);


  //FIM DA SUA PROGRAMAÇÃO DE CONFIGURAÇÃO AQUI

 
  //******************NÃO ALTERAR OU APAGAR ESSES CODIGOS**********************************
  //INICIO DOS PROCEDIMENTOS DE CONFIGURAÇÃOS PARA COMUNICAÇÃO/GRAVAÇÃO NO MICROCONTROLADOR
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  //FIM DOS PROCEDIMENTOS DE CONFIGURAÇÃOS PARA COMUNICAÇÃO/GRAVAÇÃO NO MICROCONTROLADOR
  //*************************************************************************************



   //INICIO DA SUA PROGRAMACAO DE CONFIGUTAÇÃO AQUI - OPÇÃO 2




  //FIM DA SUA PROGRAMAÇÃO DE CONFIGURAÇÃO AQUI
    
  }

  
  
  //******************NÃO ALTERAR OU APAGAR ESSES CODIGOS**********************************
  //INICIO DOS PROCEDIMENTOS PARA COMUNICAÇÃO/GRAVAÇÃO NO MICROCONTROLADOR
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
  //FIM DOS PROCEDIMENTOS PARA COMUNICAÇÃO/GRAVAÇÃO NO MICROCONTROLADOR
  //********************************************************************

  long duracao;
  float distancia, aux;

void loop() {


  //INICIO DA SUA PROGRAMACAO DE CONFIGUTAÇÃO AQUI - OPÇÃO 1

digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //digitalWrite(buzzerPin, HIGH);

  duracao = pulseIn(echoPin, HIGH ,1000000);
  aux = duracao;
  distancia = (aux*340/10000)/2;
  //Serial.print("Distancia: ");
  //Serial.println(distancia);

  //Serial.print("Duracao: ");
  //Serial.println(duracao);

  if (distancia >= 250) {
    Serial.print("Obstáculo DISTANTE");
    digitalWrite(buzzerPin, LOW);
    display.clear();
    display.display();3
    
    ;display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(10, 0, "FITA METRICA ELETRONICA");
    display.drawString(5, 15,  "  ALUNOS:Mariana,Evelyn,Julianna e Samuel ");
    display.drawString(0, 30, " SEM OBTÁCULO ");
    display.drawString(0, 45, " CAMINHO LIVRE ");
    display.display();
        
  } else if (distancia <= 150 && distancia > 100) {
    Serial.print("Obstáculo a menos 2,0 metros até 0 metro");
    display.clear();
    display.display();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(10, 0, "FITA METRICA ELETRONICA");
    display.drawString(5, 15, " Alunos:Mariana,Evelyn,Julianna e Samuel ");
    display.drawString(0, 30, "OBTÁCULO -a menos de 2,0 até 0 metro");
    display.drawString(20, 45, " ATENÇÃO ");
    display.display();
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    
  } else if (distancia <= 99 && distancia > 50) {
    Serial.print("Obstáculo a menos de 2,0 metro até 0 metro");
    display.clear();
    display.display();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(10, 0, "FITA METRICA ELETRONICA");
    display.drawString(5, 15, " Alunos:Mari,Evelyn,Jú e Samu ");
    display.drawString(0, 30, "a menos de 2,0 até 0 metro");
    display.drawString(20, 45, " ATENÇÃO ");
    display.display();
    digitalWrite(buzzerPin, HIGH);
    delay(250);
    digitalWrite(buzzerPin, LOW);
    delay(150);
  } if (distancia <= 49 && distancia > 10) {
    Serial.print("Obstáculo a menos de 2,0 até 0 metros");
    display.clear();
    display.display();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(10, 0, "FITA METRICA ELETRONICA");
    display.drawString(5, 15, "Alunos:Mari,Evelyn,Jú e Samu");
    display.drawString(0, 30, "OBTÁCULO - a menos de 2,0 até 0 metro");
    display.drawString(20, 45, " ATENÇÃO ");
    display.display();
    digitalWrite(buzzerPin, HIGH);
    delay(70);
    digitalWrite(buzzerPin, LOW);
    delay(40);
  }


  //FIM DA SUA PROGRAMAÇÃO DE CONFIGURAÇÃO AQUI

  
  
  //******************NÃO ALTERAR OU APAGAR ESSES CODIGOS**********************************
  //INICIO DO PROTOCOLO PARA COMUNICAÇÃO/GRAVAÇÃO COM O MICROCONTROLADOR
  ArduinoOTA.handle();
  //FIM DO PROTOCOLO PARA COMUNICAÇÃO/GRAVAÇÃO COM O MICROCONTROLADOR
  //***************************************************************************************


  //INICIO DA SUA PROGRAMACAO DE CONFIGUTAÇÃO AQUI - OPÇÃO 2




  //FIM DA SUA PROGRAMAÇÃO DE CONFIGURAÇÃO AQUI
  
}
