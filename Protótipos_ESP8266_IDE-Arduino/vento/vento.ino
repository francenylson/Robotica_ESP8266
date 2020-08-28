#define vento D1

void setup() {
  pinMode(vento, OUTPUT);
}

void loop() {
  digitalWrite(vento, HIGH);
  delay(2000);
  digitalWrite(vento, LOW);
  delay(9000);
}
