/*==========================================================================
                Baú da Eletrônica Componentes Eletrônicos
                        www.baudaeletronica.com.br
             Aprenda a controlar seu micro servo com NodeMcu
==========================================================================*/

#include <Servo.h>

Servo meuservo;  // instância chamada meuservo
// se utilizar mais servos criar mais instâncias

int pos = 0;    // variável de posição iniciada em zero

void setup() {
  meuservo.attach(D4);  // anexando o pino D4 do NodeMcu ao meuservo
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // movimento de 0 a 180º
    // crescente
    meuservo.write(pos);              // escreve posicao em meuservo
    delay(35);                       // aguarda 35ms
  }
  for (pos = 180; pos >= 0; pos -= 1) { // movimento de 180º a 0
    // descrescente
    meuservo.write(pos);              // escreve posicao em meuservo
    delay(35);                       // aguarda 35ms
  }
}
