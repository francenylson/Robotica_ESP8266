#include <Servo.h>

Servo meuservo;   // instância chamada meuservo
               // se utilizar mais servos criar mais instâncias

int pos = 0;    // variável de posição iniciada em zero

void setup() {
  meuservo.attach(D1);  // anexando o pino D4 do NodeMcu ao meuservo
  meuservo.write(0);
}

void loop() {
    meuservo.write(90);              // escreve posicao em meuservo
    delay(2000);
    meuservo.write(0);
    delay(2000);
    meuservo.write(180);
    delay(2000);
    meuservo.write(0);
    delay(2000);
    
  }

