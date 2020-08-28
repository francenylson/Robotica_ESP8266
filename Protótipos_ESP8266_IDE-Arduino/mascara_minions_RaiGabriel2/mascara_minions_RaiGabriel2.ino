#define led_1 D1 //amarelo
#define led_2 D2 //amarelo
#define led_3 D3 //amarelo
#define led_4 D0 //azul
#define led_5 D5 //azul

#include <Servo.h>

Servo pescoco;   //Chamar o servo motor.
              
int pos = 0;   

void setup() {

  pescoco.attach(D8); 
  Serial.begin(115200);
  //leds olhos
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  
  //servo pescoco config init   
  pescoco.write(0);
  delay (2000);
}



void loop() {
  //primeiro bloco vai para direita
  int pos;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   
  
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  delay(2310);

   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }  
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  delay(2310);    
}
