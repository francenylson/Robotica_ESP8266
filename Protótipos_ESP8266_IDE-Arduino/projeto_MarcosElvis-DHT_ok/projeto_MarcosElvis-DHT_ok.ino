/* Projeto final curso robótica
 *  Equipe Elvis, Marcos e Geovane
 *  Casa inteligente com os seguintes sensores:
 *  - DHT11 ; - Ultrasonico ; - LDR ; - Servo ; - Sensor de agua ; - cooler ; Leds .
 *  = DHT11 vai acionar o cooler com 25°C e umidade 50 Umid
 *  = Ultrassonico quando chegar carro à 5cm abrir garagem
 *  = LDR acionar leds
 *  = Sensor chuva para acionar os servos para abrir as janelas
 */
 
#include <Ultrasonic.h>  // Declaração de biblioteca
#define Led_1 D1 //Definindo os pinos dos Leds da casa
#define Led_2 D3 //Definindo os pinos dos Leds da casa
#define SensordeLuz A0 //Definindo o pino do sensor de luminosidade
#define Ventilador D2 //Definindo o pino do ventilador
//#define Temp_Umidade D6 // Definindo o pino do sensor de temperatura
#define sensor_chuva D5 // Definindo o pino do sensor de chuva
#include <Servo.h>
//***************//Definições do sensor de temperatura e umidade
#include "DHTesp.h"
#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

Ultrasonic ultrasonic(D7, D8); //Criação do objeto ultrasonic com parâmetros (trig,echo)
DHTesp dht11;//Criando o objeto dht para temperatura
Servo servo_portao;// Criando o objeto servo_janelas para manipular o portão
Servo servo_janelas;// Criando o objeto servo_janelas para manipular as janelas
//************criando as variáveis da temperatura e umidade
//int dht11 ; //OBJETO do sensor DHT recebe os valores de D6


void setup() {
  Serial.begin(9600); // Inicio da comunicação serial
  pinMode(Led_1, OUTPUT);//Definindo o modo deste pino P/ SAÍDA de dados
  pinMode(Led_2, OUTPUT);//Definindo o modo deste pino P/ SAÍDA de dados
  pinMode(SensordeLuz, INPUT);//Definindo o modo deste P/ ENTRADA de dados
  pinMode(Ventilador, OUTPUT);//Definindo o modo deste P/ SAÍDA de dados
  //pinMode(Temp_Umidade, INPUT);//Definindo o modo deste P/ ENTRADA de dados
  pinMode(sensor_chuva, INPUT);//Definindo o modo deste P/ ENTRADA de dados
  dht11.setup(D3, DHTesp::DHT11);//Definindo o modo deste P/ SAÍDA de dados
  servo_janelas.attach(D0);//Estabelecendo o pino D0 para ser usado com o servo/janela
  servo_janelas.write(0);//Ao ligar o microcontrolador o servo/janela vai para posição 90 graus
  servo_portao.attach(D0);//Estabelecendo o pino D2 para ser usado com o servo/janela
  servo_portao.write(0);//Ao ligar o microcontrolador o servo/portão vai para posição 90 graus
}
void loop() {

// TESTANDO O ULTRASONICO NO MONITOR SERIAL
Serial.print("Distancia: ");            // Escreve texto na tela
Serial.println(ultrasonic.Ranging(CM)); // distância medida em cm
Serial.println("cm");                   // escreve texto na tela e pula uma linha
delay(1000); 

// CRIANDO UMA ROTINA PARA O ULTRASONICO

int distancia_portao ;//criando uma variável para receber a distancia
distancia_portao = ultrasonic.Ranging(CM);//comando para receber os valores da distancia
  if (distancia_portao <= 11) {
    Serial.println("Abrindo portão");
    servo_portao.write(90);
    delay(5000);
   } else {
    Serial.println("Fechar portão");
    servo_portao.write(0);
   }

// **** CRIANDO ROTINA PARA SENSOR DE TEMPERATURA E UMIDADE
  delay(dht11.getMinimumSamplingPeriod());

  float humidity = dht11.getHumidity();
  float temperature = dht11.getTemperature();

  Serial.println("TEMPERATURA");
  Serial.println(temperature);
 
  if (temperature > 27.5) 
  {
  // Se a temperatura for maior que 27 ligar ventilador e abrir as janelas ***
  Serial.println("VENTILADOR LIGADO");
  digitalWrite(Ventilador, HIGH);
     
  } 
  else if (temperature <= 27)
  {
  Serial.println("VENTILADOR DESLIGADO");
  digitalWrite(Ventilador, LOW);      
  }
  /*
// **** CRIANDO ROTINA PARA SENSOR DE LUMINOSIDADE
int luminosidade = analogRead(SensordeLuz);
  Serial.println(luminosidade);
  delay(1000);
  Serial.println(luminosidade);

  if (luminosidade <= 200 && luminosidade >=1)
  {
    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_4, HIGH);
  }
  else if (luminosidade >= 201 && luminosidade <= 590)
  {
    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, LOW); 
  }
  else if (luminosidade >= 591 && luminosidade <= 1023)
  {
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_4, LOW); 
  }
//***** CRIANDO ROTINAS PARA SENSOR DE CHUVA E JANELAS ****

int chuva = digitalRead(sensor_chuva);
  Serial.print("O VALOR DO SENSOR DE CHUVA É :  ");
  Serial.print(chuva);

  if (chuva == 0) 
  {
    Serial.println("CLIMA SEM CHUVA, MANTER JANELAS ABERTAS...");
    servo_janelas.write(90);
  }
  else if (chuva == 1) 
  {
    Serial.println("CHUVA IDENTIFICADA, FECHANDO AS JANELAS...");
    servo_janelas.write(0);
  }
*/
}
