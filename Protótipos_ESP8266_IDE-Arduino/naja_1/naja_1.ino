/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 28 May 2015
  by Michael C. Miller
  modified 8 Nov 2013
  by Scott Fitzgerald

  http://arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include "Ultrasonic.h"

Ultrasonic ultrasonic_direita(D0, D1);
Ultrasonic ultrasonic_esquerda(D3, D8);

Servo myservo;  // create servo object to control a servo
Servo myservo2;


void setup() {
  Serial.begin(115200);
  myservo.attach(D6);  // attaches the servo on GIO2 to the servo object
  myservo2.attach(D7);
  myservo2.write(0);
  myservo.write(0);
  
}

void loop() {
  //imprimir informações 
  Serial.println("DISTÂNCIA MEDIDA EM CM");
  Serial.print(" sensor da DIREITA : ");
  Serial.println(ultrasonic_direita.Ranging(CM));
  Serial.println("***************************____________**************************");
  Serial.print(" sensor da ESQUERDA : ");
  Serial.println(ultrasonic_esquerda.Ranging(CM));
  delay(1000);

  int esquerda = ultrasonic_esquerda.Ranging(CM);
  int direita = ultrasonic_direita.Ranging(CM);

  if (esquerda <= 40 || direita <= 40 ) {
    Serial.print(esquerda);
    Serial.print(direita);
    myservo.write(180);
    myservo2.write(180);
    delay(150);
    myservo.write(0);
    myservo2.write(0);
    delay(150);
    myservo.write(180);
    myservo2.write(180);
    delay(150);
    myservo.write(0);
    myservo2.write(0);
    delay(150);
    myservo.write(180);
    myservo2.write(180);
    delay(100);
    myservo.write(0);
    myservo2.write(0);
    delay(100);
    myservo.write(180);
    myservo2.write(180);
    delay(150);
    myservo.write(0);
    myservo2.write(0);
    delay(150);
  
  } else {
    int pos;

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
  
  
  
}
