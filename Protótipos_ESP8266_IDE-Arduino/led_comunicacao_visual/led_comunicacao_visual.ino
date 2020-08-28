#define Led_Green D0
#define Led_Blue D2
#define Led_Red D1


void setup() {
    pinMode(Led_Green, OUTPUT);
    pinMode(Led_Blue, OUTPUT);
    pinMode(Led_Red, OUTPUT);
}

void loop() {
    digitalWrite(Led_Green, HIGH);
    digitalWrite(Led_Blue, HIGH);
    digitalWrite(Led_Red, HIGH);
    delay(2000);
    digitalWrite(Led_Green, LOW);
    digitalWrite(Led_Blue, LOW);
    digitalWrite(Led_Red, LOW);
    delay(2000);
}
