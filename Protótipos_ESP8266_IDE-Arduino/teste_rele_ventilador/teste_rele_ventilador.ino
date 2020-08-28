#define ventilador D2

void setup() {
  pinMode(ventilador, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ventilador, HIGH);
  Serial.println("LIGANDO VENTILADOR");
  delay(6000);
  digitalWrite(ventilador, LOW);
  Serial.println("DESLIGANDO VENTILADOR");
  delay(5000);
}
