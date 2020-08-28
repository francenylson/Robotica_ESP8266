

void setup() {
  Serial.begin(115200);//PORTA SERIAL
  pinMode(D7, INPUT);

}

void loop() {
  int ss2 = digitalRead(D7);
  Serial.println(ss2);

}
