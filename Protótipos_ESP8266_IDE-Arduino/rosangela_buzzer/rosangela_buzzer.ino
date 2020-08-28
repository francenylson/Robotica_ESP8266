#include "Ultrasonic.h"

#define azul D0
#define vermelho D1
#define buzzer D4


Ultrasonic ultrasonic(D7,D8);

void setup() {
Serial.begin(9600);

  pinMode(azul, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(buzzer, LOW);
}

void loop()
{
  
  Serial.println(ultrasonic.Ranging(CM));
  Serial.println("cm");
    delay(100);
  

  Serial.println("outra medição");
  Serial.println(ultrasonic.Ranging(CM));

  int distancia = ultrasonic.Ranging(CM);

  if (distancia <= 50) {
    digitalWrite(azul, HIGH);
    digitalWrite(vermelho, LOW);
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(600);
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(600);
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(600);
    
  } else if (distancia >= 71) {
    digitalWrite(azul, LOW);
    digitalWrite(vermelho, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }

}
