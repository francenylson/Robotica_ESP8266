#include <Ultrasonic.h>

#include <Ultrasonic.h>

/* Projeto final curso robótica
 *  Equipe Elvis, Marcos
 *  Casa inteligente com os seguintes sensores:
 *  - DHT11 ; - Ultrasonico ; - LDR ; - Servo ; - Sensor de agua ; - cooler ; Leds .
 *  = DHT11 vai acionar o cooler com 25°C e umidade 50 Umid
 *  = Ultrassonico quando chegar carro à 5cm abrir garagem
 *  = LDR acionar leds
 *  = Sensor chuva para acionar os servos para abrir as janelas
 */
#include <Ultrasonic.h> 
// Declaração de biblioteca
Ultrasonic ultrasonic(D7, D8); 
// Instância chamada ultrasonic com parâmetros (trig,echo)
 
void setup() {
Serial.begin(9600); 
// Inicio da comunicação serial
}
void loop() {
// TESTANDO O ULTRASONICO NO MONITOR SERIAL
Serial.print("Distancia: "); 
          // Escreve texto na tela
Serial.println(ultrasonic.Ranging(CM));
          // distância medida em cm
Serial.println("cm"); 
          // escreve texto na tela e pula uma linha
delay(1000); 

// CRIANDO UMA ROTINA PARA O ULTRASONICO

int distancia_portao ;//criando uma variável para receber a distancia
distancia_portao = ultrasonic.Ranging(CM);//comando para receber os valores da distancia
  if (distancia_portao <= 11) {
    Serial.println("Abrir portão");
   } else {
    Serial.println("Fechar portão");
   }

}
