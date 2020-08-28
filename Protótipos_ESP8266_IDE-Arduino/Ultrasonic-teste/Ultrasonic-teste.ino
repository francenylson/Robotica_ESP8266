#include "Ultrasonic.h"

Ultrasonic ultrasonic_direita(D0, D1);
Ultrasonic ultrasonic_esquerda(D3, D8);

void setup() {
Serial.begin(115200);
}

void loop()
{
  Serial.println("DISTÂNCIA MEDIDA EM CM");
  Serial.print(" sensor da DIREITA : ");
  Serial.println(ultrasonic_direita.Ranging(CM));
  Serial.println("***************************____________**************************");
  Serial.print(" sensor da ESQUERDA : ");
  Serial.println(ultrasonic_esquerda.Ranging(CM));
  delay(1000);
}
