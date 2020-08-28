#include <Adafruit_BMP085.h>  //Biblioteca com as funções do BMP180
 
#include <Wire.h> // Como BMP180 e o LCD utiliza o protocolo I2C é  necessária esta biblioteca para a configuração dos pinos SDA e SCL do sensor
 
//#include <ESP8266WiFi.h>
 
#include "DHT.h"// biblioteca com funções para o sensor DHT11
 
#include <LiquidCrystal_I2C.h> //Biblioteca com funções para o lcd
 
  
 
//INICIALIZAÇÕES
 
  
 
LiquidCrystal_I2C lcd(0x27, 16, 2);// Inicialização do LCD, sendo o utilizado um 16x2
 
const char* ssid     = "AndroidAP"; // Nome da Rede
 
const char* password = "kingkong"; // Password da rede
 
  
 
const char* host = "api.thingspeak.com";
 
  
 
const char* THINGSPEAK_API_KEY = "L4ESA1UD5SC00AZL"; //Write API KEY
 
  
 
// Configurações sensor DHT11
 
#define DHTPIN D6     // Utilização da GPIO12 do ESP8266 e D6 do NodeMCU
 
  
 
#define DHTTYPE DHT11   // DHT 11
 
  
 
Adafruit_BMP085 bmp; // Inicialização sensor BMP180
 
  
 
  
 
//Atualização à taxa de 1 minuto, o Thingspeak necessita no minimo 20segundo
 
const int UPDATE_INTERVAL_SECONDS = 60;
 
//Inicialização das funções
 
  
 
// Inicialização do sensor de temperature e humidade
 
DHT dht(DHTPIN, DHTTYPE);
 
  
 
  
 
byte tmp[8] = { //função para desenhar o simbolo da temperatura no lcd
 
0b00100,
 
0b01010,
 
0b01010,
 
0b01110,
 
0b01110,
 
0b11111,
 
0b11111,
 
0b01110,
 
};
 
  
 
  
 
// Inicialização do sensor de temperature e humidade
 
DHT dht(DHTPIN, DHTTYPE);
 
  
 
  
 
byte tmp[8] = { //função para desenhar o simbolo da temperatura no lcd
 
0b00100,
 
0b01010,
 
0b01010,
 
0b01110,
 
0b01110,
 
0b11111,
 
0b11111,
 
0b01110,
 
};
 
  
 
byte hum[8] = {//função para desenhar o simbolo da humidade no lcd
 
0b00100,
 
0b00100,
 
0b01010,
 
0b01010,
 
0b10001,
 
0b10001,
 
0b10001,
 
0b01110,
 
};
 
  
 
  
 
void setup() {
 
  
 
Serial.begin(115200);
 
  
 
delay(10);
 
  
 
// Comunicação com a rede WiFi
 
  
 
Serial.println();
 
Serial.println();
 
Serial.print("Connecting to "); //Mensagem apresentada no monitor série
 
Serial.println(ssid); // Apresenta o nome da rede no monitor série
 
  
 
WiFi.begin(ssid, password); // Inicia a ligação a rede
 
  
 
while (WiFi.status() != WL_CONNECTED) {// Enquanto a ligação não for efectuada com sucesso é apresentado no monitor série uma sucessão de "."
 
delay(500);
 
Serial.print(".");
 
}
 
  
 
Serial.println("");
 
Serial.println("WiFi connected");  // Se a ligação é efectuada com sucesso apresenta esta mensagem no monitor série
 
  
 
  
 
Serial.println("Endereço IP: ");
 
Serial.println(WiFi.localIP()); // Apresentação do Endereço IP no monitor série
 
}
 
  
 
void loop() {
 
  
 
Wire.begin(2, 0);            // Configuração dos pinos para o sensor BMP180. GPIO2 para SDA(pino para a transferência de dados) que corresponde ao D4, GPIO0 para SCL(pino para temporização) que corresponde ao  D3
 
Wire.setClock(400000); //Temporização entre dispositivos
 
if (!bmp.begin()) {
 
Serial.println("O sensor BMP180 não foi encontrado!");
 
while (1) {}  //enquanto o sensor não for encontrado executa este ciclo
 
}
 
  
 
Serial.print("connecting to ");
 
Serial.println(host);//Apresenta no monitor série o nome da rede à qual é efectuada a ligação
 
  
 
// Uso WiFiClient para criar comunicações TCP
 
WiFiClient client;
 
const int httpPort = 80; //Uso Porto80
 
if (!client.connect(host, httpPort)) {
 
Serial.println("Falha Comunicação");//Verifica o estado da ligação
 
return;
 
}
 
  
 
// Leitura dos dados do sensor
 
int humidity = dht.readHumidity();// Leitura Humidade
 
float temperature = dht.readTemperature(); //Leitura Temperatura
 
  
 
int pressure = bmp.readPressure(); // Leitura Pressão Atmosférica em Pa
 
  
 
  
 
Wire.begin(4, 5);// Configuração dos pinos para o LCD. GPIO4 para SDA(pino para a transferência de dados) que corresponde ao D2, GPIO5 para SCL(pino para temporização) que corresponde ao  D1
 
lcd.init();   // Inicialização do LCD
 
lcd.createChar(0, tmp);// Cria o simbolo da temperatura
 
lcd.createChar(1, hum);// Cria o simbolo da humidade
 
lcd.backlight(); // Activar a luz de fundo
 
lcd.setCursor(0, 0); // Posição no LCD para a temperatura, neste casso é na linha de cima, alinhado à esquerda
 
lcd.write(byte(0));// Desenha no LCD o simbolo da temperatura
 
lcd.print(" ");
 
lcd.print(temperature); // Imprime no LCD a temperatura
 
lcd.print((char)223);// Imprime no LCD "º"
 
lcd.print("C");
 
lcd.setCursor(11, 0);
 
lcd.write(byte(1));// Desenha no LCD o seimbolo da humidade
 
lcd.print(" ");
 
lcd.print(humidity); // Imprime no LCD a humidade
 
lcd.print("%");
 
lcd.setCursor(0, 1);// Posição no LCD para a pressão, neste casso é na linha de baixo, alinhado à esquerda
 
lcd.print("Pressao:");
 
lcd.print(pressure); // Imprime no LCD a pressão
 
à esquerda
 
lcd.write(byte(0));// Desenha no LCD o simbolo da temperatura
 
lcd.print(" ");
 
lcd.print(temperature); // Imprime no LCD a temperatura
 
lcd.print((char)223);// Imprime no LCD "º"
 
lcd.print("C");
 
lcd.setCursor(11, 0);
 
lcd.write(byte(1));// Desenha no LCD o seimbolo da humidade
 
lcd.print(" ");
 
lcd.print(humidity); // Imprime no LCD a humidade
 
lcd.print("%");
 
lcd.setCursor(0, 1);// Posição no LCD para a pressão, neste casso é na linha de baixo, alinhado à esquerda
 
lcd.print("Pressao:");
 
lcd.print(pressure); // Imprime no LCD a pressão
 
lcd.print("Pa");
 
  
 
  
 
// Criar URL para o pedido
 
String url = "/update?api_key=";
 
url += THINGSPEAK_API_KEY;
 
url += "&field1="; //Colocar os dados de temperatura no gráfico 1 do Thingspeak
 
url += String(temperature);
 
url += "&field2="; //Colocar os dados de humidade no gráfico 2 do Thingspeak
 
url += String(humidity);
 
url += "&field3="; //Colocar os dados de pressão no gráfico 3 do Thingspeak
 
url += String(pressure);
 
  
 
  
 
Serial.print("Pedido URL: ");
 
Serial.println(url);
 
  
 
// Envio de solicitação ao servidor
 
client.print(String("GET ") + url + " HTTP/1.1\r\n" +
 
"Host: " + host + "\r\n" +
 
"Connection: close\r\n\r\n");
 
delay(10);
 
while(!client.available()){//Verificação se o cliente está conectado
 
delay(100);
 
Serial.print(".");
 
}
 
// Leitura das respostas do servidor e envio para o monitor série
 
while(client.available()){
 
String line = client.readStringUntil('\r');
 
Serial.print(line);
 
}
 
  
 
Serial.println();
 
Serial.println("Comunicação fechada"); //Depois do cliente efectuar o pedido apresenta esta mensagem no monitor série
 
  
 
  
 
  
 
delay(1000 * UPDATE_INTERVAL_SECONDS); //Como os valores da função delay são em ms, multiplica-se por 1000 para que a multiplicação com 60 seja igual a 60 segundos e portanto 1 minuto
 
}
 
  
 
  
 
No código acima altera-se o valor SSID para o nome da Rede ao qual o ESP8266 vai comunicar, a password pela palavra-passe dessa rede, o THINGSPEAK_API_KEY pela write API Key obtida pelo canal criado no ThingSpeak. Antes de fazer-se a compilação do programa devem-se incluir as
 
  
 
  
 
Serial.println();
 
Serial.println("Comunicação fechada"); //Depois do cliente efectuar o pedido apresenta esta mensagem no monitor série
 
  
 
  
 
  
 
delay(1000 * UPDATE_INTERVAL_SECONDS); //Como os valores da função delay são em ms, multiplica-se por 1000 para que a multiplicação com 60 seja igual a 60 segundos e portanto 1 minuto
 
}
