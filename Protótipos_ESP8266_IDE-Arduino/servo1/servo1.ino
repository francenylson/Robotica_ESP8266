#include <Servo.h>

Servo myservo;  

void setup() {
  myservo.attach(2);  
}

void loop() {
  myservo.write(0);
}
