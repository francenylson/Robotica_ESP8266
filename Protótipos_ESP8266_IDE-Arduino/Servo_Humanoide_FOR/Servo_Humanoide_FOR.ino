#include <Servo.h>

Servo pescoco;   //Chamar o servo motor.
              
int pos = 0;   

void setup() {

  pescoco.attach(D0); 
  Serial.begin(115200);
   
  //servo pescoco config init   
  pescoco.write(90);
  delay (4000);
}



void loop() {
  //primeiro bloco vai para direita
  int pos;
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15ms for the servo to reach the position
  }
   
    delay(2310);

   for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 150ms for the servo to reach the position
  }  
  
   delay(3310); 

     for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 150ms for the servo to reach the position
  }  

   delay(2310); 

     for (pos = 0; pos >= 90; pos += 1) { // goes from 180 degrees to 0 degrees
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 150ms for the servo to reach the position
  }  
  
  delay(3310);
}
