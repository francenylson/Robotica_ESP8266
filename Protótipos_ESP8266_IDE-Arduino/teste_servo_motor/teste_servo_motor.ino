
#include <Servo.h>

Servo pescoco;   //Chamar o servo motor.
              
int pos = 1;   

void setup() {

  pescoco.attach(D8); 
  Serial.begin(115200); 
  //servo pescoco config init   
  pescoco.write(20);
  delay (3000);
}



void loop() {
  pescoco.write(0);
  delay(3000);
  pescoco.write(90);
  delay(3000);
  pescoco.write(0);
  delay(3000);
  pescoco.write(180);
  delay(3000);

  
}
