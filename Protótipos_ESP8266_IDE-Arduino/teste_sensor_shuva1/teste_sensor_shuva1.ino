#define pinv1 D1
#define pinv2 D2
#define pinv3 D3

void setup() {
  // put your setup code here, to run once:
  pinMode(pinv1, OUTPUT);
  pinMode(pinv2, OUTPUT);
  pinMode(pinv3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinv1, HIGH);
  digitalWrite(pinv2, HIGH);
  digitalWrite(pinv3, HIGH);
  delay(150);
  digitalWrite(pinv1, LOW);
  digitalWrite(pinv2, LOW);
  digitalWrite(pinv3, LOW);
  delay(1000);
  digitalWrite(pinv1, HIGH);
  digitalWrite(pinv2, HIGH);
  digitalWrite(pinv3, HIGH);
  delay(200);
  digitalWrite(pinv1, LOW);
  digitalWrite(pinv2, LOW);
  digitalWrite(pinv3, LOW);
  delay(500);
  
}
