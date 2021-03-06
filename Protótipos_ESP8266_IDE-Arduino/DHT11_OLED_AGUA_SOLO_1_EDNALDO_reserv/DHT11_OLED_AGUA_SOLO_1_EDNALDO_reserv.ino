#include "ESP8266WiFi.h"
#include "SSD1306.h" // incluindo a biblioteca do oled`
SSD1306 display(0x3c, D2, D1); // definindo o endereco e os pinos sda D2 e cls ou sck D1
#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

#define pinSensorSolo D0
#define bombagua D3

DHTesp dht;

//int pino_d = D0; //Pino ligado ao D0 do sensor
int pino_a = A0; //Pino ligado ao A0 do sensor reservatorio
int val_d = 0; //Armazena o valor lido do pino digital
int val_a = 0; //Armazena o valor lido do pino analogico

void setup() {
Serial.begin(115200);//PORTA SERIAL
display.init(); // iniciando o display oled
display.flipScreenVertically(); //orientacao do texto
dht.setup(D5, DHTesp::DHT11);

// DEFINE OS PINOS DO SENSOR efine os pinosCOMO ENTRADA DO SENSOR DE ÁGUA
 // pinMode(pino_d, INPUT);
  pinMode(pino_a, INPUT);
  pinMode(pinSensorSolo, INPUT);
  pinMode(bombagua, OUTPUT);

}
void loop() {
  //SENSOR CHUVA
  //val_d = digitalRead(pino_d);
  val_a = analogRead(pino_a);
  Serial.print("Valor digital : ");
  Serial.print(val_d);
  Serial.print(" - Valor analogico : ");
  Serial.println(val_a);

  //DHT11
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  //SOLO
  int val = digitalRead(pinSensorSolo);
  int umidadeSolo = val;
  int reservatorio = val_a;
  Serial.println(umidadeSolo);
  Serial.println(reservatorio);

 
  if (val_a >701 && val_a <1025)
  {
      Serial.print(val_a+"sensor reservatorio");
      // IMPRIME SITUAÇÃO DO RESERVATORIO
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(5, 36, "!! SEM ÁGUA " );// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      digitalWrite(bombagua, HIGH);//LIGANDO BOMBA
      delay(1000);
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(5, 36, "!! SEM ÁGUA");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      delay(2000);
      //DHT11
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "Temper. "+String(temperature)+"°C");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(5, 36, "Umid.  "+String(humidity)+" %");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      delay(2000);
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "Temper. "+String(temperature)+"°C");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(5, 36, "Umid.  "+String(humidity)+" %");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      delay(2000);
      
      
  }
  
  else
  {
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(2, 36, "COM ÁGUA " );// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      digitalWrite(bombagua, LOW);//DESLIGANDO BOMBA
      delay(2000);
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(2, 36, "COM ÁGUA");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      
      delay(2000);
      //DHT11
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "Temper. "+String(temperature)+"°C");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(5, 36, "Umid.  "+String(humidity)+" %");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      delay(2000);
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "Temper. "+String(temperature)+"°C");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(5, 36, "Umid.  "+String(humidity)+" %");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      delay(2000);
      
  }
  if (umidadeSolo==1)
  {
    //SOLO
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "SOLO S/ÁGUA");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(0, 36, "IRRIGANDO");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      // comentario
      delay(2000);
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "SOLO S/ ÁGUA");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(1, 36, "IRRIGANDO");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      delay(2000);
  } 
  
  else if (umidadeSolo==0)
   {
    //SOLO
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "SOLO ÚMIDO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(0, 36, "SEM IRRIGAR");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      //comentario
      delay(2000);
      display.clear();//LIMPA O BUFFER PARA O DISPLAY
      display.display();//ENVIA UM BUFFER PARA O DISPLAY
      display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
      display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
      display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
      display.drawString(2, 10, " "); 
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_16);
      display.drawString(0, 19, "SOLO ÚMIDO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
      display.drawString(0, 36, "SEM IRRIGAR");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);
      display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
      display.display();
      
      delay(2000);
   }
   else
      Serial.print("DEU CERTO");

}
