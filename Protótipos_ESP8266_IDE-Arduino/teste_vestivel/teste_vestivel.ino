#define led 0

void setup() {
  pinMode(led, OUTPUT);
  
}

void loop() {
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(2000);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(3000);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(300);
  digitalWrite(led, HIGH);
  delay(200);
}
