#define sensorLdr A0
#define led_verde D1

void setup() {
  pinMode(sensorLdr, INPUT);
  pinMode(led_verde, OUTPUT);
  Serial.begin(115200);     //PORTA SERIAL
}
void loop() {
  int sensorLdrStatus = analogRead(sensorLdr);
  Serial.println(sensorLdrStatus);
  delay(1000);
  Serial.println(sensorLdrStatus);

  if (sensorLdrStatus <= 200)
  {
    digitalWrite(led_verde, HIGH);
  }
  else if (sensorLdrStatus > 201)
  {
    digitalWrite(led_verde, LOW);
  }

}
