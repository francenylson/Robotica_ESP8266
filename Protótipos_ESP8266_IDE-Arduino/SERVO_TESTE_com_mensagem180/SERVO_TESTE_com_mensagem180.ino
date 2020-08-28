#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  myservo.attach(D7);  // attaches the servo on GIO2 to the servo object
  myservo.write(90);
  Serial.begin(9600);
}

void loop() {
  myservo.write(90);//vira para direita
  Serial.println("POSIÇÃO : 0 GRAUS");
  delay(2000);//espera 2 segundos
  myservo.write(0);//vira para direita
  Serial.println("POSIÇÃO : 180 GRAUS");
  delay(2000);//espera 2 segundos
  
  }
