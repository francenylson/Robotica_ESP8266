#define Led_Vermelho D1
#define Led_Amarelo D4
#define Led_Verde D5
#define Buzina D7


void setup() {
  pinMode(Led_Vermelho, OUTPUT);
  pinMode(Led_Amarelo, OUTPUT);  
  pinMode(Led_Verde, OUTPUT);
  pinMode(Buzina, OUTPUT);
}
void loop() {
  digitalWrite(Led_Vermelho, HIGH);
  digitalWrite(Led_Amarelo, LOW);
  digitalWrite(Led_Verde, LOW);
  digitalWrite(Buzina, HIGH);
  delay(2000);
  digitalWrite(Led_Vermelho, HIGH);
  digitalWrite(Led_Amarelo, LOW);
  digitalWrite(Led_Verde, LOW);
  digitalWrite(Buzina, HIGH);
  delay(2000);
  digitalWrite(Led_Vermelho, HIGH);
  digitalWrite(Led_Amarelo, LOW);
  digitalWrite(Led_Verde, LOW);
  digitalWrite(Buzina, HIGH);
  delay(2000);
  
}
