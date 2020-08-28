#include "ESP8266WiFi.h"
#include "SSD1306.h" // incluindo a biblioteca do oled`
SSD1306 display(0x3c, D2, D1); // definindo o endereco e os pinos
#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

DHTesp dht;

//DECLARAÇÕES SOBRE SENSOR DE CHUVA
int pino_d = D0; //Pino ligado ao D0 do sensor
int pino_a = A0; //Pino ligado ao A0 do sensor
int val_d = 0; //Armazena o valor lido do pino digital
int val_a = 0; //Armazena o valor lido do pino analogico

void setup() {
Serial.begin(9600);//PORTA SERIAL
display.init(); // iniciando o display oled
display.flipScreenVertically(); //orientacao do texto
dht.setup(D5, DHTesp::DHT11);

// DEFINE OS PINOS DO SENSOR efine os pinosCOMO ENTRADA DO SENSOR DE ÁGUA
  pinMode(pino_d, INPUT);
  pinMode(pino_a, INPUT);

}
void loop() {

//INFORMAÇÕES SOBRE O NÍBEL DE ÁGUA DO RESERVATÓRIO
//Le e arnazena o valor do pino digital
  val_d = digitalRead(pino_d);
  //Le e armazena o valor do pino analogico
  val_a = analogRead(pino_a);
  //Envia as informacoes para o serial monitor
  Serial.print("Valor digital : ");
  Serial.print(val_d);
  Serial.print(" - Valor analogico : ");
  Serial.println(val_a);
 
  // Acende o led de acordo com a intensidade 
  if (val_a >900 && val_a <1024)
  {
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
display.drawString(5, 36, " COM ÁGUA " );// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(5000);
display.clear();//LIMPA O BUFFER PARA O DISPLAY
display.display();//ENVIA UM BUFFER PARA O DISPLAY
display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
display.drawString(2, 10, " "); 
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_16);
display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
display.drawString(5, 36, "COM ÁGUA");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(5000);
  }
  if (val_a >400 && val_a <900)
  {
    // IMPRIME SITUAÇÃO DO RESERVATORIO 50%
display.clear();//LIMPA O BUFFER PARA O DISPLAY
display.display();//ENVIA UM BUFFER PARA O DISPLAY
display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
display.drawString(2, 10, " "); 
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_16);
display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
display.drawString(2, 36, " COM 50 % DE ÁGUA " );// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(5000);
display.clear();//LIMPA O BUFFER PARA O DISPLAY
display.display();//ENVIA UM BUFFER PARA O DISPLAY
display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
display.drawString(2, 10, " "); 
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_16);
display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
display.drawString(2, 36, "COM 50 % DE ÁGUA");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(5000);
  }
  if (val_a > 0 && val_a <400)
  {
    // IMPRIME SITUAÇÃO DO RESERVATORIO 50%
display.clear();//LIMPA O BUFFER PARA O DISPLAY
display.display();//ENVIA UM BUFFER PARA O DISPLAY
display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
display.drawString(2, 10, " "); 
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_16);
display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
display.drawString(2, 36, " PRECISA DE ÁGUA " );// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(5, 54, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(5000);
display.clear();//LIMPA O BUFFER PARA O DISPLAY
display.display();//ENVIA UM BUFFER PARA O DISPLAY
display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
display.drawString(0, 0, "ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
display.drawString(2, 10, " "); 
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_16);
display.drawString(0, 19, "RESERVATÓRIO");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
display.drawString(2, 36, "PRECISA DE ÁGUA");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(10, 54, " ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(5000);
  }
 

  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

//SOBRE O DISPLAY
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
delay(5000);
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
delay(5000);

}
