#include <ESP8266WiFi.h>

//CONFIGURANDO A REDE WIFI
const char* ssid = "Moto G Play 4190";
const char* senha = "fran#2017";

//DIRECIONAMENTO DOS PINOS DO ESP8266 QUE SERÃO USADOS
int ledPin1 = 14; // D5
int ledPin2 = 13; // D7
int ledPin3 = 12; // D6
int ledPin4 = 15; // D8
WiFiServer server(80);

void setup() {
  //CONFIGURANDO A PORTA SERIAL
  Serial.begin(115200);
  delay(10);
  // CONFIGURANDO OS PINOS QUE FORAM DIRECIONADOS
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  
  //DESLIGANDO OS PINOS SEMPRE QUE O ESP8266 FOR LIGADO
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);

  //CONFIGURAÇÃO DA REDE WIFI E PARA IMPRESSÃO NA PORTA SERIAL
  Serial.print("Conectando a rede:");
  Serial.println(ssid);
  WiFi.begin(ssid, senha);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");
  server.begin();
  Serial.println("Servidor Iniciado");

  Serial.print("Use esta URL:");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

int status1 = LOW;
int status2 = LOW; 
int status3 = LOW; 
int status4 = LOW; 

void loop() {
  WiFiClient cliente = server.available();
  if(!cliente){
    return;
  }
  Serial.println("Novo cliente");
  while(!cliente.available()){
    delay(1);
  }
  String requisicao = cliente.readStringUntil('\r');
  Serial.println(requisicao);
  cliente.flush();

  if( requisicao.indexOf("/LED1=ON") !=-1){
    status1 = HIGH;  
  }  
  if(requisicao.indexOf("/LED1=OFF") != -1){
   status1 = LOW;
  }   

  if( requisicao.indexOf("/LED2=ON") !=-1){
    status2 = HIGH;  
  }  
  if(requisicao.indexOf("/LED2=OFF") != -1){
   status2 = LOW;
  }  
  if( requisicao.indexOf("/LED3=ON") !=-1){
    status3 = HIGH;  
  }  
  if(requisicao.indexOf("/LED3=OFF") != -1){
   status3 = LOW;
  }
  if( requisicao.indexOf("/LED4=ON") !=-1){
    status4 = HIGH;  
  }  
  if(requisicao.indexOf("/LED4=OFF") != -1){
   status4 = LOW;
  }


  
  Serial.print("status:");
  Serial.println(status1);
  digitalWrite(ledPin1, status1);
  digitalWrite(ledPin2, status2);
  digitalWrite(ledPin3, status3);
  digitalWrite(ledPin4, status4);

  cliente.println("HTTP/1.1 200 OK");
  cliente.println("Content-Type:text/html");
  cliente.println("");
  cliente.println("<!DOCTYPE HTML>");
  cliente.println("<html>"); 
  cliente.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n");
  cliente.println("<title>ESP8266 Web Server</title>");
  cliente.println("<style>.c{text-align: center;} div,input{padding:5px;font-size:5em;} input{width:80%;} body{text-align: center;font-family:verdana;} button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;} .q{float: right;width: 64px;text-align: right;}</style>");
  cliente.println("</head>");

  cliente.println("<br><br>");
  cliente.println("<a href=\"/LED1=ON\"\"><button> Ligar LED 1 </button></a>");
  cliente.println("<a href=\"/LED1=OFF\"\"><button> Desligar LED 1</button></a><br/>");

  cliente.println("<br><br>");
  cliente.println("<a href=\"/LED2=ON\"\"><button> Ligar LED 2 </button></a> <a href=\"/LED2=OFF\"\"><button> Desligar LED 2 </button></a><br/>");

  cliente.println("<br><br>");
  cliente.println("<a href=\"/LED3=ON\"\"><button> Ligar LED 3 </button></a>");
  cliente.println("<a href=\"/LED3=OFF\"\"><button> Desligar LED 3 </button></a><br/>");

  cliente.println("<br><br>");
  cliente.println("<a href=\"/LED4=ON\"\"><button> Ligar LED 4 </button></a>");
  cliente.println("<a href=\"/LED4=OFF\"\"><button> Desligar LED 4 </button></a><br/>");


  
  cliente.println("</html>");
  delay(1); 
}
