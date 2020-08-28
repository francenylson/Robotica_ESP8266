#include <Servo.h>

Servo p;   //Chamar o servo motor.
              
int pos = 0;   

void setup()
{
  p.attach(D8); 
  p.write(80);
  delay (2000);
}



void loop() {
 p.write(20);
 delay(1000);
 p.write(60);
 delay(1000);
 p.write(80);
 delay(1000);
}
