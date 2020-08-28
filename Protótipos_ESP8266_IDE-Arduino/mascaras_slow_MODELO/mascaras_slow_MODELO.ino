
#include <Servo.h>

Servo pescoco;   //Chamar o servo motor.
              
int pos = 1;   

void setup() {

  pescoco.attach(D8); 
  Serial.begin(115200); 
  //servo pescoco config init   
  pescoco.write(130);
  delay (1000);
}



void loop() {
  //primeiro bloco vai para direita
  int pos;
  for (pos = 90; pos <= 90; pos += 1) { 
    pescoco.write(90);              
    delay(1000);                       
  }

  //segundo bloco volta para o centro
  for (pos = 90; pos >= 90; pos -= 1) { 
    pescoco.write(pos);              
    delay(1000);
  }  

  for (pos = 90; pos >= 90; pos += 1) { 
    pescoco.write(pos);              
    delay(1000);                       
  }
  //segundo bloco volta para o centro
  for (pos = 90; pos >= 90; pos -= 1) { 
    pescoco.write(pos);              
    delay(1000);
  }  

  
}
