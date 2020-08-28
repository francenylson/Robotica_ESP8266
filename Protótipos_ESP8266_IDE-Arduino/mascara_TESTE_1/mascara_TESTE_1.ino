#define trigPinE D1   
#define echoPinE D2   

#define trigPinD D3
#define echoPinD D4

#include <Servo.h>

Servo aranha;   // Chamar o servo motor.
              
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
  delay (5000);
}



void loop() {


  //Esquerdo
  
  digitalWrite(trigPinE, HIGH);
  delayMicroseconds(200);
  digitalWrite(trigPinE, LOW);

  duracaoE = pulseIn(echoPinE, HIGH , 1000000);
  aux = duracaoE;
  distanciaE = (aux * 340 / 10000) / 2;
  Serial.print("Distancia: ");
  Serial.println(distanciaE);
  Serial.println("--------o--------");

  if (distanciaE <= 60 && distanciaD > 60) {
    Serial.print("Observar a esquerda");
    aranha.write(0);
    Serial.println(distanciaE);
    delay(200);
    } 
    
    else if (distanciaE > 60 && distanciaD > 60) {
    Serial.print("Ninguém a esquerda");
    aranha.write(90);
    Serial.println(distanciaE);
    delay(200);
    } 

   
  
  //Direito
    
  digitalWrite(trigPinD, HIGH);
  delayMicroseconds(200);
  digitalWrite(trigPinD, LOW);


  duracaoD = pulseIn(echoPinD, HIGH , 1000000);
  auxi = duracaoD;
  distanciaD = (auxi * 340 / 10000) / 2;
  Serial.print("Distancia: ");
  Serial.println(distanciaD);
  Serial.println("--------o--------");
    
    
   if (distanciaD <= 60 && distanciaE > 60) {
    Serial.print("Observar a Direita");
    aranha.write(180);
    Serial.println(distanciaD);
    delay(200);
    } 

    else if (distanciaD > 60 && distanciaE > 60) {
    Serial.print("Ninguém a direita");
    aranha.write(90);
    Serial.println(distanciaD);
    delay(200);
    }
   
  else if (distanciaD < 60 && distanciaE < 60) {
    Serial.print("Ninguém a direita e nem na esquerda");
    aranha.write(90);
    Serial.println(distanciaD);
    delay(200);
    }

}
