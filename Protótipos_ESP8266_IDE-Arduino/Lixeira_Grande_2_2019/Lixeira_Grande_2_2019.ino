#include <Servo.h>
#define trigPin D3
#define echoPin D4
#include "Ultrasonic.h"

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Ultrasonic ultrasonic(D3, D4);

void setup() {
  myservo.attach(D6);  // attaches the servo on GIO2 to the servo object
  myservo.write(90);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  
}

int duracao;
int distancia, aux;

void loop() {
  distancia = ultrasonic.Ranging(CM);
 
  Serial.print("Distancia: ");
  Serial.println(distancia);

  Serial.print("Duracao: ");
  Serial.println(duracao);

  if (distancia < 20) {
    //Serial.print("Ligar Servo Motor - Lixeira ABERTA");
    myservo.write(180);
    delay(3000);
    myservo.write(135);
    delay(1000);
    myservo.write(90);     

  } else  {
    myservo.write(90);
    //Serial.print("Desligar Servo Motor e lixeira fechada");

  }
}
