#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = D6;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200);
}

void loop() {
  // start working...
  int temp = dht11.read();
  Serial.println("=================================");
  Serial.println("TEMPERATURA DHT11...");
  Serial.println(temp);
  
  delay(1500);
}
