#define FluxoAgua D6

void setup() {
  pinMode(FluxoAgua, OUTPUT);

}

void loop() {
  digitalWrite(FluxoAgua, HIGH);
  delay(3000);
  digitalWrite(FluxoAgua, LOW);
  delay(2000);

}
