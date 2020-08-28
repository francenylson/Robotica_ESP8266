#include <Servo.h>

Servo francenylson, france2; //criando o "objeto" servo francenylson

void setup() {
  francenylson.attach(D5);  //servo francenylson está no pino D5
  francenylson.write(0); //inicializar o chip em o grau
}
void loop() {
 myservo.write(90);
}
