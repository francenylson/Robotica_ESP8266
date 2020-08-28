#include <Servo.h>

//DEFINEINDO PINOS ULTRASSONICOS
#define trigPinEsquerda D0
#define trigPinDireita D1
#define echoPinEsquerda D2
#define echoPinDireita D3

Servo meuservo ;

int pos = 90;

void setup(){

  //meuservo.write(0);
   Serial.begin(115200);
   pinMode(trigPinEsquerda, OUTPUT);
   pinMode(echoPinEsquerda, INPUT);
   digitalWrite(trigPinEsquerda, LOW);
   
   //DIREITO
   Serial.begin(115200);
   pinMode(trigPinDireita, OUTPUT);
   pinMode(echoPinDireita, INPUT);
   digitalWrite(trigPinDireita, LOW);
}
//variaveis ultra
long duracao, duracaoDireito;
float distancia, aux, distanciaDireito, auxDireito;

void loop() {

  digitalWrite(trigPinEsquerda, HIGH);
  delayMicroseconds(500);
  digitalWrite(trigPinEsquerda, LOW);

  duracao = pulseIn(echoPinEsquerda, HIGH , 1000000);
  aux = duracao;
  distancia = (aux * 340 / 10000) / 2;
  Serial.print("Distancia: ");
  Serial.println(distancia);
  Serial.println("--------o--------");

  if (distancia > 12) {
  Serial.print("obstaculo esquerdo DISTANTE");
  Serial.println(distancia);
  meuservo.write(pos);
  delay(500);

}else if (distancia <= 12 ) {
  Serial.print("obstaculo esquerdo PROXIMO");
  Serial.println(distancia);
  meuservo.write(180);
  delay(500);
  
  }
   digitalWrite(trigPinDireita, HIGH);
   delayMicroseconds(500);
   digitalWrite(trigPinDireita, LOW);

   duracaoDireito = pulseIn(echoPinDireita, HIGH, 1000000);
   auxDireito = duracaoDireito;
   distanciaDireito = (auxDireito * 340 / 10000) / 2;
   Serial.print("Distancia: ");
   Serial.print(duracao);

   if (distanciaDireito > 12 ) 
   {
    Serial.print("Obstáculo");
    meuservo.write(pos);
    delay(500);
   }else if (distanciaDireito <= 12 )
   {
    Serial.print("Obstaculo");
    meuservo.write(0);
    delay(500);

   }
   
   }
