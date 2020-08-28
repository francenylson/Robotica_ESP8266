#define led_1 D1   
#define led_2 D2   
#define led_3 D3
#define led_4 D4
#define led_5 D5

#include <Servo.h>

Servo pescoco;   // Chamar o servo motor.
              
int pos = 0;   

void setup() {

  pescoco.attach(D7); 
  Serial.begin(115200);
  //leds olhos
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  
  //servo pescoco config init   
  pescoco.attach(D0);
  pescoco.write(90);
  delay (2000);
}



void loop() {

  int pos;
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 
  
  //primeiro giro para direita
  digitalWrite(led_1, HIGH);
  delay(500);
  digitalWrite(led_2, HIGH);
  delay(500);
  digitalWrite(led_3, HIGH);
  delay(500);
  digitalWrite(led_4, HIGH);
  delay(500);
  digitalWrite(led_5, HIGH);
  delay(200);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  delay(510);
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);

  //segundo bloco centro
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  delay(510);
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  delay(1000);

  //terceiro bloco esquerda  
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    pescoco.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  delay(510);
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  delay(1000);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  delay(1310);

  
}
