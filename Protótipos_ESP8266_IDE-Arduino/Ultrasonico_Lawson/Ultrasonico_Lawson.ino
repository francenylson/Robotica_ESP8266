#define trigPin D3
#define echoPin D4
#define ledyellow D5
#define ledred D6
#define buzzy D7

void setup() {

  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(buzzy, OUTPUT);
  digitalWrite(trigPin, LOW);
}

long duracao;
float distancia, aux;

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(trigPin, LOW);
  digitalWrite(ledyellow, LOW);
  digitalWrite(ledred, LOW);
  digitalWrite(buzzy, LOW);

  duracao = pulseIn(echoPin, HIGH , 1000000);
  aux = duracao;
  distancia = (aux * 340 / 10000) / 2;
  Serial.print("Distancia: ");
  Serial.println(distancia);
  Serial.println("--------o--------");
  //Serial.print("Duracao: ");
  //Serial.println(duracao);

  

  if (distancia >= 100) {
    Serial.print("Obstáculo DISTANTE");
    Serial.println(distancia);
    digitalWrite(ledyellow, HIGH);
    delay(500);
    

    
  } else if (distancia <= 99 && distancia > 50) {
    Serial.print("Vá devagar");
    Serial.println(distancia);
    digitalWrite(ledred, HIGH);
    delay(1000);

  } else if (distancia <= 49 && distancia > 30) {
    Serial.print("Está bem próximo");
    Serial.println(distancia);
    digitalWrite(buzzy, HIGH);
    delay(250);
    digitalWrite(buzzy, LOW);
    delay(250);
    digitalWrite(buzzy, HIGH);
    delay(250);
    digitalWrite(buzzy, LOW);
    delay(250);
    digitalWrite(buzzy, HIGH);
    delay(250);
    digitalWrite(buzzy, LOW);
    delay(250);
    
  } if (distancia <= 29 && distancia > 10) {
    Serial.print("Vai bater!!!!!!!!");
    Serial.println(distancia);
    digitalWrite(buzzy, HIGH);
    delay(60);
  }
  

}
