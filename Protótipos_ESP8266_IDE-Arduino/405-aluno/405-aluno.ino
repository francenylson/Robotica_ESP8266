#define Led_1 D1
#define Led_2 D4
#define Buzina D6

void setup() {
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Buzina, OUTPUT);
}
void loop() {
  digitalWrite(Led_1, HIGH);
  digitalWrite(Led_2, HIGH);
  digitalWrite(Buzina, HIGH);
  delay(2000);
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, LOW);
  digitalWrite(Buzina, LOW);
  delay(2000);


}
