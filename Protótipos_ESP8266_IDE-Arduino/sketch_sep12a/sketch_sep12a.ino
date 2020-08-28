#define led_1 D0
#define buzzer D4
#define led_2 D2

void setup() {
  pinMode(led_1, OUTPUT);//definindo led_vermelho como saída
  pinMode(buzzer, OUTPUT);//definindo led_verde como saída
  pinMode(led_2, OUTPUT);//
   
}

void loop() {
  //1o. bloco
  digitalWrite(led_1, HIGH);
  digitalWrite(buzzer, HIGH);
  digitalWrite(led_2, LOW);
  delay(1000);
  //2o. bloco
  digitalWrite(led_1, HIGH);
  digitalWrite(buzzer, HIGH);
  digitalWrite(led_2, HIGH);
  delay(1000);
  //3o. bloco para bipar o buzzer
  digitalWrite(led_1, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(led_2, HIGH);
  delay(500);
  //4''o. bloco para bipar o buzzer
  digitalWrite(led_1, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(led_2, HIGH);
  delay(500);
}
