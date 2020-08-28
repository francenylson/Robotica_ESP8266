// Programa : Teste sensor de chuva
// Autor : Arduino e Cia

int pino_d = D0; //Pino ligado ao D0 do sensor
int pino_a = A0; //Pino ligado ao A0 do sensor
int val_d = 0; //Armazena o valor lido do pino digital
int val_a = 0; //Armazena o valor lido do pino analogico

// Portas ligadas aos leds
int pino_led_verde = D5;
int pino_led_amarelo = D6;
int pino_led_vermelho = D7;

void setup()
{
  // Define os pinos do sensor como entrada
  pinMode(pino_d, INPUT);
  pinMode(pino_a, INPUT);

  // Define os pinos dos leds como saida
  pinMode(pino_led_verde, OUTPUT);
  pinMode(pino_led_amarelo, OUTPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //Le e arnazena o valor do pino digital
  val_d = digitalRead(pino_d);
  //Le e armazena o valor do pino analogico
  val_a = analogRead(pino_a);
  //Envia as informacoes para o serial monitor
  Serial.print("Valor digital : ");
  Serial.print(val_d);
  Serial.print(" - Valor analogico : ");
  Serial.println(val_a);
 
  // Acende o led de acordo com a intensidade 
  if (val_a >900 && val_a <1024)
  {
    // Acende led verde - intensidade baixa
    digitalWrite(pino_led_verde, HIGH);
    digitalWrite(pino_led_amarelo, LOW);
    digitalWrite(pino_led_vermelho, LOW);
  }
  if (val_a >400 && val_a <900)
  {
    // Acende led amarelo - intensidade moderada
    digitalWrite(pino_led_verde, LOW);
    digitalWrite(pino_led_amarelo, HIGH);
    digitalWrite(pino_led_vermelho, LOW);
  }
  if (val_a > 0 && val_a <400)
  {
    // Acende led vermelho - intensidade alta
    digitalWrite(pino_led_verde, LOW);
    digitalWrite(pino_led_amarelo, LOW);
    digitalWrite(pino_led_vermelho, HIGH);
  }
  delay(1000);
}
