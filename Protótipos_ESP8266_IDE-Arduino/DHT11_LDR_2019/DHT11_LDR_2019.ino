#include "ESP8266WiFi.h"
#include <dht.h>

#include "SSD1306.h" // incluindo a biblioteca do oled`
SSD1306 display(0x3c, D2, D1); // definindo o endereco e os pinos

dht DHT;

#define DHT11_PIN D5
#define sensor Ldr A0



void setup() {
Serial.begin(115200);//PORTA SERIAL
display.init(); // iniciando o display oled
display.flipScreenVertically(); //orientacao do texto
pinMode(sensorLdr, INPUT);



}
void loop() {

  int sensorLdrStatus = analogRead(sensorLdr);

  //mostrar no monitor
  Serial.println(sensorLdrStatus);

  if (sensorLdrStatus <= 400) {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, HIGH);
    digitalWrite(ledPinBlue, HIGH); 
    delay(1000);
    digitalWrite(ledPinRed, HIGH);
     
  }
  else if (sensorLdrStatus >= 401 & sensorLdrStatus <= 800) {
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinBlue, HIGH); 
    delay(1000);
    digitalWrite(ledPinGreen, HIGH);
    
  }
  else if(sensorLdrStatus >= 801) {
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinGreen, HIGH);
    digitalWrite(ledPinBlue, LOW); 
    delay(1000);
    digitalWrite(ledPinBlue, HIGH);
    
  }
  
//SOBRE O DISPLAY
display.clear();//LIMPA O BUFFER PARA O DISPLAY
display.display();//ENVIA UM BUFFER PARA O DISPLAY
display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
display.drawString(5, 0, " ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
display.drawString(2, 3, "_____________________"); 
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(1, 23, "ESTUFA ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
display.drawString(5, 35, "ALUNO MAKER DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.drawString(5, 50, "PROF FRANCENYLSON");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(3000);

int chk = DHT.read11(DHT11_PIN);
int f1 = DHT.temperature;
int f2 = DHT.humidity
// oled com graficos
//drawLines();
//  delay(1500);
//  display.clear();
  
drawCircle();
  delay(500);
  display.clear();

display.clear();//LIMPA O BUFFER PARA O DISPLAY
display.display();//ENVIA UM BUFFER PARA O DISPLAY
display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
display.drawString(5, 0, " ROBÓTICA PET"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
display.drawString(2, 3, "_____________________"); 
display.setTextAlignment(TEXT_ALIGN_LEFT);
display.setFont(ArialMT_Plain_10);
display.drawString(1, 23, "ESTUFA ALUNOS EC 401");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
display.drawString(5, 35, f1);// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
display.drawString(5, 50, f2");// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
display.display();
delay(3000);

/*fillRect();
  delay(1500);
  display.clear();
  */

  
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
