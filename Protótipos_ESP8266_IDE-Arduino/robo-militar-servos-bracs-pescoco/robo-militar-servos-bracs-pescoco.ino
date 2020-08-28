#include <Servo.h>

Servo pescoco;   // Chamar o servo motor pescoco
             
int pos = 0;   

void setup() {

  pescoco.attach(D0);
  Serial.begin(115200);
  
  //servo pescoco config init 
  pescoco.write(0);  
  delay (2000);
}



void loop() {

  int pos;
  for (pos = 0; pos <= 100; pos += 1) { 
  pescoco.write(pos);              
  delay(30);                     
  }
  
  //segundo bloco centro
  for (pos = 100; pos >= 0; pos -= 1) { 
  pescoco.write(pos);        
  delay(30);                       
  }
  
  
}
