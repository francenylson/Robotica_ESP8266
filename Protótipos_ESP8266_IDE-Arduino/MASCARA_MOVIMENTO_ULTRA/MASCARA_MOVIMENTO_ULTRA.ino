#include <Servo.h>
#define trigPin D2
#define echoPin D3 
#define trigPinDireito D5
#define echoPinDireito D6
 
Servo meuservo ;

int pos = 90;

void setup() {
    
    meuservo.attach(D4);
    
  //meuservo.write(0);
      Serial.begin(115200);
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      digitalWrite(trigPin, LOW);
    //direito
      pinMode(trigPinDireito, OUTPUT);
      pinMode(echoPinDireito, INPUT);
      digitalWrite(trigPinDireito, LOW);  
}
//variaveis ultra
long duracao, duracaoDireito;
float distancia, aux,  distanciaDireito, auxDireito;

void loop() {

      digitalWrite(trigPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(trigPin, LOW);

      duracao = pulseIn(echoPin, HIGH , 1000000);
      aux = duracao;
      distancia = (aux * 340 / 10000) / 2;
      Serial.print("Distancia: ");
      Serial.println(distancia);
      Serial.println("--------o--------");
    //Serial.print("Duracao: ");
    //Serial.println(duracao);

    if (distancia > 12) {
        Serial.print("Obstáculo esquerdo DISTANTE");
        Serial.println(distancia);
        meuservo.write(pos);
        delay(500);
      
     
  } else if (distancia <= 12 ) {
        Serial.print("Obstáculo esquerdo PROXIMO ");
        Serial.println(distancia);
        meuservo.write(180);
        delay(500);

     
  } 
  // direito ***************************
      digitalWrite(trigPinDireito, HIGH);
      delayMicroseconds(500);
      digitalWrite(trigPinDireito, LOW);

      duracaoDireito = pulseIn(echoPinDireito, HIGH , 1000000);
      auxDireito = duracaoDireito;
      distanciaDireito = (auxDireito * 340 / 10000) / 2;
      Serial.print("Distancia: ");
      Serial.println(distanciaDireito);
      Serial.println("--------x--------");
    //Serial.print("Duracao: ");
    //Serial.println(duracao);

    if (distanciaDireito > 12) {
        Serial.print("Obstáculo direito DISTANTE");
        Serial.println(distanciaDireito);
        meuservo.write(pos);
        delay(500);
      
     
  } else if (distanciaDireito <= 12 ) {
        Serial.print("Obstáculo direito PROXIMO ");
        Serial.println(distanciaDireito);
        meuservo.write(0);
        delay(500);

     
  }  
}
