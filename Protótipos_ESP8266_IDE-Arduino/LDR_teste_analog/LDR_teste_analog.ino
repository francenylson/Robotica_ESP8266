#define sensorLdr A0
#define led_verde D1
#define sensorLDR_dig D0

void setup() {
  pinMode(sensorLdr, INPUT);
  pinMode(sensorLDR_dig, INPUT);
  pinMode(led_verde, OUTPUT);
  Serial.begin(115200);     //PORTA SERIAL
}
void loop() {
  int sensorLdrStatus = analogRead(sensorLdr);
  int sensorLDR_digStatus = digitalRead(sensorLDR_dig);
  Serial.println("valores analogicos" + sensorLdrStatus);
  Serial.println("valores digitais" + sensorLDR_digStatus);
  delay(1000);
  Serial.println("valores analogicos",+ sensorLdrStatus);
  Serial.println("valores digitais", + sensorLDR_digStatus);

  //CONDIÇÕES DEFINIDAS
  
  if (sensorLdrStatus <= 200)
  {
    digitalWrite(led_verde, HIGH);
  }
  else if (sensorLdrStatus > 201)
  {
    digitalWrite(led_verde, LOW);
  }

}
