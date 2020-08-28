#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  myservo.attach(D2);  // attaches the servo on GIO2 to the servo object
  myservo.write(90);
  
}

void loop() {
  myservo.write(90);//fica para frente
  delay(2000);//espera 2 segundos
  myservo.write(50);//fica para frente
  delay(2000);
  myservo.write(90);//fica para frente
  delay(2000);//espera 2 segundos
  myservo.write(130);//vira para esquerda
  delay(2000);
}
