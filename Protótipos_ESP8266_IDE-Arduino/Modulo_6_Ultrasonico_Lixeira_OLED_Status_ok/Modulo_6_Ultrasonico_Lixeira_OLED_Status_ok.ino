#include "ESP8266WiFi.h"

#include "SSD1306.h" // alias for `
#include "SSD1306Wire.h"`
SSD1306 display(0x3c, D2, D1);

#include <Servo.h>
#define trigPin D3
#define echoPin D4

Servo meuservo;  // instância chamada meuservo
// se utilizar mais servos criar mais instâncias


void setup() {
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically(); //orientacao do texto
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);

  meuservo.attach(D7);  // anexando o pino D4 do NodeMcu ao meuservo
}

long duracao;
float distancia, aux;

void loop() {

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  meuservo.write(180);              // escreve posicao em meuservo
  

  duracao = pulseIn(echoPin, HIGH ,1000000);
  aux = duracao;
  distancia = (aux*340/10000)/2;
  Serial.print("Distancia: ");
  Serial.println(distancia);

  Serial.print("Duracao: ");
  Serial.println(duracao);

  if (distancia < 20) {
    //Serial.print("Ligar Servo Motor");
    meuservo.write(50);              // escreve posicao em meuservo
    display.clear();
    display.display();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(10, 0, "PROJETO PET i");
    display.drawString(5, 15, " ALUNO MAKER DIGITAL ");
    display.drawString(10, 30, " LIXEIRA DIGITAL ");
    display.drawString(0, 45, "STATUS :  A B E  R T A");
    display.display();
    delay(3000);
        
    meuservo.write(110);
    delay(500);
    meuservo.write(130);
    delay(500);
    meuservo.write(180);
        

  } else  {
    meuservo.write(180);
    //Serial.print("Desligar Servo Motor e lixeira fechada");
    display.clear();
    display.display();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(10, 0, "PROJETO PET i");
    display.drawString(5, 15, " ALUNO MAKER DIGITAL ");
    display.drawString(10, 30, " LIXEIRA DIGITAL ");
    display.drawString(0, 45, "STATUS :  F E C H A D A");
    display.display();
  }
}
