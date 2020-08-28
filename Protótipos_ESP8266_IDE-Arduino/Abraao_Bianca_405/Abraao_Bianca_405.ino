#define Led_Vermelho D1
#define Led_Amarelo D4
#define Led_Verde D5
#define Buzina D6
#define Pedestre1 D2
#define Pedrestre2 D7

void setup() {
  pinMode(Led_Vermelho, OUTPUT);
  pinMode(Led_Amarelo, OUTPUT);
  pinMode(Led_Verde, OUTPUT);
  pinMode(Buzina, OUTPUT);
  pinMode(Pedestre1, OUTPUT);
  pinMode(Pedrestre2, OUTPUT);
}
void loop() {
  digitalWrite(Led_Vermelho, HIGH);
  digitalWrite(Led_Amarelo, LOW);
  digitalWrite(Led_Verde, LOW);
  digitalWrite(Buzina, HIGH);
  digitalWrite(Pedestre1, HIGH);
  digitalWrite(Pedrestre2, LOW);
  delay(3000);
  digitalWrite(Led_Vermelho, LOW);
  digitalWrite(Led_Amarelo, LOW);
  digitalWrite(Led_Verde, HIGH);
  digitalWrite(Buzina, LOW);
  digitalWrite(Pedestre1, LOW);
  digitalWrite(Pedrestre2, HIGH);
  delay(3000);
  digitalWrite(Led_Vermelho, LOW);
  digitalWrite(Led_Amarelo, HIGH);
  digitalWrite(Led_Verde, LOW);
  digitalWrite(Buzina, HIGH);
  digitalWrite(Pedestre1, HIGH);
  digitalWrite(Pedrestre2, LOW);
  delay(1500);

}
