/*====================================================
                        Baú da Eletrônica Componentes Eletrônicos
                              www.baudaeletronica.com.br
 Pinagem
 * ---------------------    
 * | HC-SC04 | NodeMCU |   
 * ---------------------   
 * |   Vcc   |   5V    |     
 * |   Trig  |   D7    | 
 * |   Echo  |   D8    |   
 * |   Gnd   |   GND   |   */

#include <Ultrasonic.h> // Declaração de biblioteca

Ultrasonic ultrasonic(D7, D8); // Instância chamada ultrasonic com parâmetros (trig,echo)

void setup() { 
  Serial.begin(9600); // Inicio da comunicação serial
}

void loop() {
  int distancia = ultrasonic.distanceRead();
  
  Serial.print("Distancia: "); // Escreve texto na tela
  Serial.print(ultrasonic.distanceRead(CM));// distância medida em cm
  Serial.println("cm"); // escreve texto na tela e pula uma linha
  Serial.println("AQUIIIIIIII");
  //Serial.println(distancia);
  
  delay(1000); // aguarda 1s 
}
