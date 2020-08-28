

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  digitalWrite(2, LOW);
  delay(500);
  
}
