#define trigPin D3
#define echoPin D4
#define LedRed D6
#define Buzzer D7
void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  digitalWrite(LedRed, OUTPUT);
  digitalWrite(Buzzer, OUTPUT);
}
long duracao;
float distancia, aux;
void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(trigPin, LOW);
  
  

  duracao = pulseIn(echoPin, HIGH , 1000000);
  aux = duracao;
  distancia = (aux * 340 / 10000) / 2;
  Serial.print("Distancia: ");
  Serial.println(distancia);
  Serial.println("--------o--------");
  //Serial.print("Duracao: ");
  //Serial.println(duracao);

  if (distancia <= 50 && distancia >= 2) {
    Serial.print("Obstáculo DISTANTE"); 
    Serial.println(distancia);
    digitalWrite(Buzzer, HIGH);
    delay(500);
        
    } else if (distancia >= 51 && distancia <= 75) {
    Serial.print("Obstáculo a menos de 1,5 metros até 1,00 metro");
    Serial.println(distancia);
    digitalWrite(LedRed, HIGH);
    delay(500);
    

  } if (distancia >= 76 && distancia <=95 ) {
    Serial.print("Vai bater!!!!!!!!");
    Serial.println(distancia);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(LedRed, HIGH);
    delay(606);
  }
}
