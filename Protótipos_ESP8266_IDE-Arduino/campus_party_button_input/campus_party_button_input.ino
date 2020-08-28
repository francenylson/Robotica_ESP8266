

void setup() {
  // put your setup code here, to run once:
  pinMode(13, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13) == 0) {
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
    
  } else {
    digitalWrite(8, LOW);
    delay(1000);
    digitalWrite(8, HIGH);
    delay(1000);

  }
   
  
}
