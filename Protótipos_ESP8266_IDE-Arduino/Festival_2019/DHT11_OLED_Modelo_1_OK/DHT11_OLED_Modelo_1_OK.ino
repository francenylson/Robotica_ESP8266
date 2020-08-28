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
Serial.begin(115200);//PORTA SERIAL
display.init(); // iniciando o display oled
display.flipScreenVertically(); //orientacao do texto
dht.setup(D5, DHTesp::DHT11);

// DEFINE OS PINOS DO SENSOR efine os pinosCOMO ENTRADA DO SENSOR DE ÁGUA
  pinMode(pino_d, INPUT);
  pinMode(pino_a, INPUT);

}
void loop() {

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

//efeito visual
fillRect();
  delay(1500);
  display.clear();
// oled com graficos
//drawLines();
//  delay(1500);
//  display.clear();
  
//drawCircle();
//  delay(500);
//  display.clear();


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
delay(1000);


  
}

void drawLines() {
  for (int16_t i=0; i<DISPLAY_WIDTH; i+=4) {
    display.drawLine(0, 0, i, DISPLAY_HEIGHT-1);
    display.display();
    delay(10);
  }
  for (int16_t i=0; i<DISPLAY_HEIGHT; i+=4) {
    display.drawLine(0, 0, DISPLAY_WIDTH-1, i);
    display.display();
    delay(10);
  }
  delay(250);

  display.clear();
  for (int16_t i=0; i<DISPLAY_WIDTH; i+=4) {
    display.drawLine(0, DISPLAY_HEIGHT-1, i, 0);
    display.display();
    delay(10);
  }
  for (int16_t i=DISPLAY_HEIGHT-1; i>=0; i-=4) {
    display.drawLine(0, DISPLAY_HEIGHT-1, DISPLAY_WIDTH-1, i);
    display.display();
    delay(10);
  }
  delay(250);

  display.clear();
  for (int16_t i=DISPLAY_WIDTH-1; i>=0; i-=4) {
    display.drawLine(DISPLAY_WIDTH-1, DISPLAY_HEIGHT-1, i, 0);
    display.display();
    delay(10);
  }
  for (int16_t i=DISPLAY_HEIGHT-1; i>=0; i-=4) {
    display.drawLine(DISPLAY_WIDTH-1, DISPLAY_HEIGHT-1, 0, i);
    display.display();
    delay(10);
  }
  delay(250);
  display.clear();
  for (int16_t i=0; i<DISPLAY_HEIGHT; i+=4) {
    display.drawLine(DISPLAY_WIDTH-1, 0, 0, i);
    display.display();
    delay(10);
  }
  for (int16_t i=0; i<DISPLAY_WIDTH; i+=4) {
    display.drawLine(DISPLAY_WIDTH-1, 0, i, DISPLAY_HEIGHT-1);
    display.display();
    delay(10);
  }
  delay(250);
}
void drawCircle(void) {
  for (int16_t i=0; i<DISPLAY_HEIGHT; i+=2) {
    display.drawCircle(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, i);
    display.display();
    delay(10);
  }
  delay(1000);
  display.clear();

  // This will draw the part of the circel in quadrant 1
  // Quadrants are numberd like this:
  //   0010 | 0001
  //  ------|-----
  //   0100 | 1000
  //
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00000001);
  display.display();
  delay(200);
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00000011);
  display.display();
  delay(200);
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00000111);
  display.display();
  delay(200);
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00001111);
  display.display();
}

void fillRect(void) {
  uint8_t color = 1;
  for (int16_t i=0; i<DISPLAY_HEIGHT/2; i+=3) {
    display.setColor((color % 2 == 0) ? BLACK : WHITE); // alternate colors
    display.fillRect(i, i, DISPLAY_WIDTH - i*2, DISPLAY_HEIGHT - i*2);
    display.display();
    delay(10);
    color++;
  }
  // Reset back to WHITE
  display.setColor(WHITE);
}
