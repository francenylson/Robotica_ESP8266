#include <Servo.h>

Servo bolhas;   //Chamar o servo motor.
              
int pos = 0;   

void setup() {
  bolhas.attach(D8);   //servo pescoco config init   
  bolhas.write(0);
  Serial.begin(115200);
 }

void loop() {
  bolhas.write(0);
  delay(3000);
  bolhas.write(180);
  delay(3000);
  }
