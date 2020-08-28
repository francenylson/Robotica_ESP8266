#define trigPin D3
#define echoPin D4
#define ledred D6
#define buzzer D7

void setup() {

  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  digitalWrite(ledred, OUTPUT);
  digitalWrite(buzzer, OUTPUT);
}


long duracao;
float distancia, aux;

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  

  duracao = pulseIn(echoPin, HIGH , 1000000);
  aux = duracao;
  distancia = (aux * 340 / 10000) / 2;
  Serial.print("Distancia: ");
  Serial.println(distancia);
  Serial.println("--------o--------");
  //Serial.print("Duracao: ");
  //Serial.println(duracao);

  if (distancia <= 99 && distancia > 50) {
    Serial.print("Obstáculo DISTANTE"); 
    Serial.println(distancia);
    digitalWrite(buzzer, HIGH);
    delay(500);
        
    } else if (distancia <= 49 && distancia > 20) {
    Serial.print("Obstáculo a menos de 1,5 metros até 1,00 metro");
    Serial.println(distancia);
    digitalWrite(ledred, HIGH);
    delay(500);
    

  } /*if (distancia < 70 && distancia <90 ) {
    Serial.print("Vai bater!!!!!!!!");
    Serial.println(distancia);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(ledRed, HIGH);
    delay(606);
  }*/

}
