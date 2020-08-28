#define trigPinE D1
#define echoPinD D2

#define trigPinD D3
#define echoPinD D4

#include <Servo.h>

Servo aranha;

int pos = 0;

long duracaoE;
float distanciaE, aux;

long duracaoD;
float distanciaD, auxi;

void setup() {
  Serial.begin(115200);
  pinMode(trigPinE, OUTPUT);
  pinMode(echoPinE, INPUT);
  digitalWrite(trigPinE, LOW);

  pinMode(trigPinD, OUTPUT);
  pinMode(echoPinD, INPUT);
  digitalWrite(trigPinD, LOW);

  aranha.attach(D0);
  aranha.write(90);
  delay(2000);

}

void loop() {
  //esquerdo
  digitalWrite(trigPinE, HIGH);
  delay(200);
  digitalWrite(trigPinE, LOW);

  duracaoE = pulseIn(echoPinE, HIGH,  1000000);
  aux = duracaoE;
  distanciaE = (aux *340 / 10000) / 2;
  Serial.print("DISTANCIA : " );
  Serial.println(distanciaE);
  Serial.println("----------O----------");

  //direito
  digitalWrite(trigPinD, HIGH);
  delay(200);
  digitalWrite(trigpinD, LOW);

  duracaoD = (pulseIn(echoPinD, HIGH, 1000000);
  auxi = duracaoD;
  distanciaD = (auxi * 340 / 10000) / 2;
  Serial.print("DISTANCIA : ");
  Serial.println(distanciaD);
  Serial.println("--------------o--------------");

  
}
