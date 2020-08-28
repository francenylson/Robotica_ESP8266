#include "Ultrasonic.h"

#define azul D0
#define vermelho D1


Ultrasonic ultrasonic(D7,D8);

void setup() {
Serial.begin(9600);

  pinMode(azul, OUTPUT);
  pinMode(vermelho, OUTPUT);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
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
    
  } else if (distancia >= 71) {
    digitalWrite(azul, LOW);
    digitalWrite(vermelho, HIGH);
  }

}
