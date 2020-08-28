#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

DHTesp dht;

void setup() {
Serial.begin(115200);//PORTA SERIAL
dht.setup(D3, DHTesp::DHT11);

}
void loop() {

  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  Serial.println("teste mostrar umidade");
  Serial.println(humidity);
  Serial.println("teste mostrar temperatura");
  Serial.println(temperature);
    
}
