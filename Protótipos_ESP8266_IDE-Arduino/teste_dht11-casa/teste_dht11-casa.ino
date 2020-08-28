#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

DHTesp dht11;

void setup() {
Serial.begin(9600);//PORTA SERIAL
dht11.setup(D3, DHTesp::DHT11);

}
void loop() {
  //DHT11
  delay(dht11.getMinimumSamplingPeriod());

  float humidity = dht11.getHumidity();
  float temperature = dht11.getTemperature();

  Serial.println("TEMPERATURA");
  Serial.println(temperature);
}
