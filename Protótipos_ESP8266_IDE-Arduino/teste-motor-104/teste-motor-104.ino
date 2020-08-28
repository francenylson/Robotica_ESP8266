// Programa: Controle de motor DC com ESP8266 NodeMCU
// Autor: Pedro Bertoleti
 
// Importa a Biblioteca ESP8266WiFi
#include <ESP8266WiFi.h> 
 

//defines - pinos aos quais estão ligados os drivers dos motores
#define MOTOR1_PINO D0
/*#define MOTOR2_PINO    D1
 
//defines - pinos que conterão os botões para 
//controlar o acionamento dos motores
#define BOTAO_ACIONA_MOTOR1   D2
#define BOTAO_ACIONA_MOTOR2   D3
 

 * Implementação das funções
 */
void setup() 
{
  //direção dos pinos
  pinMode(MOTOR1_PINO,OUTPUT);
 /* pinMode(MOTOR2_PINO,OUTPUT);
  pinMode(BOTAO_ACIONA_MOTOR1,INPUT);
  pinMode(BOTAO_ACIONA_MOTOR2,INPUT);*/
   
  //inicializações dos motores
  digitalWrite(MOTOR1_PINO,LOW);
  //digitalWrite(MOTOR2_PINO,LOW);
}
 
void loop() 
{
  digitalWrite(MOTOR1_PINO, HIGH);
  delay(1000);
  digitalWrite(MOTOR1_PINO, LOW);
  delay(1000);

  
   /* //verifica se deve ligar ou desligar motor 1
    if (digitalRead(BOTAO_ACIONA_MOTOR1) == LOW)
        digitalWrite(MOTOR1_PINO,HIGH);
    else
        digitalWrite(MOTOR1_PINO,LOW);
 
    //verifica se deve ligar ou desligar motor 2
    if (digitalRead(BOTAO_ACIONA_MOTOR2) == LOW)
        digitalWrite(MOTOR2_PINO,HIGH);
    else
        digitalWrite(MOTOR2_PINO,LOW);      
        */      
}
