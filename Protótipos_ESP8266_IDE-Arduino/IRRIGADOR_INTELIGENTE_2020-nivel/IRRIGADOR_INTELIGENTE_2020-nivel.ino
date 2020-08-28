#include "ESP8266WiFi.h"
#include "SSD1306.h" // incluindo a biblioteca do oled`
SSD1306 display(0x3c, D2, D1); // definindo o endereco e os pinos sda D2 e cls ou sck D1
#include "DHTesp.h"


#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

#define SensorSolo_1 A0
#define SensorSolo_2 D0
#define Bombagua D3
#define Nivel_Agua D4
#define Temp_Umidade D5

DHTesp dht;

//int pino_SensorSolo_1 = 0; //Pino ligado ao A0 do sensor do solo 1
//int pino_SensorSolo_2 = 0; // Pino ligado ao sensor solo 2
int nivel = 0; //Armazena o valor lido do pino digital
int temperatura = 0; //Armazena o valor lido do pino analogico

void setup() {
Serial.begin(115200);//PORTA SERIAL
display.init(); // iniciando o display oled
display.flipScreenVertically(); //orientacao do texto
dht.setup(D5, DHTesp::DHT22);

// DEFINE OS PINOS DO SENSOR efine os pinosCOMO ENTRADA DO SENSOR DE ÁGUA
  pinMode(SensorSolo_1, INPUT);
  pinMode(SensorSolo_2, INPUT);
  pinMode(Bombagua, OUTPUT);
  pinMode(Nivel_Agua, INPUT);
  pinMode(Temp_Umidade, INPUT);

}

void loop() {
  //SENSOR NÍVEL DA ÁGUA
  nivel = digitalRead(Nivel_Agua);
  temperatura = analogRead(Temp_Umidade);

  //DHT11
  
   delay(dht.getMinimumSamplingPeriod());

   float humidity = dht.getHumidity();
   float temperature = dht.getTemperature();

  // SENSOR DE SOLO
  int pino_SensorSolo_1 = analogRead(SensorSolo_1);
  Serial.print(" VALOR DO SENSOR DO SOLO : " +   pino_SensorSolo_1);

   
        Serial.println("SITUAÇÃO NÍVEL DA ÁGUA RESERVATÓRIO : ");
        if (nivel == 0) {
          Serial.println( "ÁGUA NO RESERVATÓRIO" );
          display.clear();//LIMPA O BUFFER PARA O DISPLAY
          display.display();//ENVIA UM BUFFER PARA O DISPLAY
          display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
          display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
          display.drawString(0, 0, "RESERVATÓRIO"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
          display.drawString(10, 14,"COM Á G U A"); 
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(28, 30,"IRRIGAÇÃO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
          display.drawString(0, 42,"INTELIGÊNCIA ARTIFICIAL");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 54,"PET-ALUNO MAKER DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
          display.display();
          delay(2000);
        }else if (nivel == 1) {
          Serial.println("REABASTECER ÁGUA");
          display.clear();//LIMPA O BUFFER PARA O DISPLAY
          display.display();//ENVIA UM BUFFER PARA O DISPLAY
          display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
          display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
          display.drawString(0, 0, "RESERVATÓRIO"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
          display.drawString(12, 14, "SEM Á G U A"); 
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(28, 30,"IRRIGAÇÃO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
          display.drawString(0, 42,"INTELIGÊNCIA ARTIFICIAL");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 54, "PET-ALUNO MAKER DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
          display.display();
          delay(2000);
        } 
        //CONDIÇÃO PARA IMPRIMIR A TEMPERATURA E UMIDADE DO AR
        if ( temperature >= 0 || humidity >= 0 ) {
          Serial.println("temperatura e Umidade do ar " + String(humidity) +  String(temperature));
          display.clear();//LIMPA O BUFFER PARA O DISPLAY
          display.display();//ENVIA UM BUFFER PARA O DISPLAY
          display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
          display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
          display.drawString(0, 0,"TEMP:"+String(temperature)+" °C"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
          display.drawString(0, 14,"UMID AR:"+String(humidity)+" %"); 
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(28, 30,"IRRIGAÇÃO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
          display.drawString(0, 42,"INTELIGÊNCIA ARTIFICIAL");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 54, "PET-ALUNO MAKER DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
          display.display(); 
          delay(1500); 
        } else {
          
        }
        if (pino_SensorSolo_1 > 900) {
          Serial.println("LIGANDO A BOMBA");
          Serial.println(pino_SensorSolo_1);
          display.clear();//LIMPA O BUFFER PARA O DISPLAY
          display.display();//ENVIA UM BUFFER PARA O DISPLAY
          display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
          display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
          display.drawString(0, 0, "IRRIGANDO"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
          display.drawString(12, 14, "SOLO 1"); 
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(28, 30,"IRRIGAÇÃO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
          display.drawString(0, 42,"INTELIGÊNCIA ARTIFICIAL");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 54, "PET-ALUNO MAKER DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
          display.display();
          delay(2000);
        }else {
          Serial.println("DESLIGANDO A BOMBA");
          display.clear();//LIMPA O BUFFER PARA O DISPLAY
          display.display();//ENVIA UM BUFFER PARA O DISPLAY
          display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
          display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
          display.drawString(0, 0, "SOLO 1"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
          display.drawString(12, 14, "IRRIGADO"); 
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(28, 30,"IRRIGAÇÃO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
          display.drawString(0, 42,"INTELIGÊNCIA ARTIFICIAL");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
          display.setTextAlignment(TEXT_ALIGN_LEFT);
          display.setFont(ArialMT_Plain_10);
          display.drawString(0, 54, "PET-ALUNO MAKER DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
          display.display();
          delay(2000);
        }
        
}

        

  
  
    

  //SOLO
 
