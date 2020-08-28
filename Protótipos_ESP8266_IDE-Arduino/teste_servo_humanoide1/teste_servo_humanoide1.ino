
#include <Servo.h>

Servo pescoco;   //Chamar o servo motor.
              
int pos = 1;   

void setup() {

  pescoco.attach(D8); 
  Serial.begin(115200); 
  //servo pescoco config init   
  
}



void loop() {
  pescoco.write(90);
  delay(2000);
  pescoco.write(130);
  delay(2000);
  pescoco.write(90);
  delay(2000);
  pescoco.write(60);
  delay(2000);
 

  
}
