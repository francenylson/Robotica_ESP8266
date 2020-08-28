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




// FIM DA SUA PROGRAMAÇÃO


void setup() {

  //INICIO DA SUA PROGRAMACAO DE CONFIGUTAÇÃO AQUI - OPÇÃO 1




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

  

void loop() {


  //INICIO DA SUA PROGRAMACAO DE CONFIGUTAÇÃO AQUI - OPÇÃO 1




  //FIM DA SUA PROGRAMAÇÃO DE CONFIGURAÇÃO AQUI

  
  
  //******************NÃO ALTERAR OU APAGAR ESSES CODIGOS**********************************
  //INICIO DO PROTOCOLO PARA COMUNICAÇÃO/GRAVAÇÃO COM O MICROCONTROLADOR
  ArduinoOTA.handle();
  //FIM DO PROTOCOLO PARA COMUNICAÇÃO/GRAVAÇÃO COM O MICROCONTROLADOR
  //***************************************************************************************


  //INICIO DA SUA PROGRAMACAO DE CONFIGUTAÇÃO AQUI - OPÇÃO 2




  //FIM DA SUA PROGRAMAÇÃO DE CONFIGURAÇÃO AQUI
  
}
