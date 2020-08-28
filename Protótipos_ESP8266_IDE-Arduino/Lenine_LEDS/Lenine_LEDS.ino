#define Led_1 D2
#define Led_2 D3

void setup() {
  pinMode(Led_1, OUTPUT);
}
void loop() {
  digitalWrite(Led_1, HIGH);
  delay(500);
  digitalWrite(Led_1, LOW);
  delay(500);
}
