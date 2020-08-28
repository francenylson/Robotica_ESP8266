#define pinSensorSolo D0

void setup() {
  Serial.begin(115200);//PORTA SERIAL
  pinMode(pinSensorSolo, INPUT);
 
}
void loop() {
    //SOLO
  int val = digitalRead(pinSensorSolo);
  int umidadeSolo = val;
  Serial.println(umidadeSolo);
  delay(1000);
  Serial.println(umidadeSolo);

}
