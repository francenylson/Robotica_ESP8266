

void setup() {
  // put your setup code here, to run once:
  pinMode(13, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13) == 0) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
   
  
}
