#include "pitches.h"
#define NO_SOUND 0
#define falante D8

//web
#include <ESP8266WiFi.h>
#include "SSD1306.h" // incluindo a biblioteca do oled`
SSD1306 display(0x3c, D2, D1); // definindo o endereco e os pinos

// Replace with your network credentials
const char* ssid     = "Vivo-Internet-9CF3";
const char* password = "15262CFA";

// Set web server port number to 80
WiFiServer server(80);
//web
//web
// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String outputD1State = "off";
String outputD2State = "off";
String outputD3State = "off";
//web

//button
const int versao1 = D5; //constante botão refere-se ao pino digital d5.
const int versao2 = D6;
const int versao3 = D7;

//Variável que conterá os estados do botão (0 LOW, 1 HIGH).
int estadoBotao = 0;
int estadoBotao2 = 0;
int estadoBotao3 = 0;
int tempo = 0;




//web
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
//web



// Notas que devem ser tocadas ordenadamente;
int melodia[] = {
  NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4,
  NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,
  NOTE_FS4,NOTE_G4,NO_SOUND,NO_SOUND,NOTE_C4,
  NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,

  NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4,
  NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_B4,NOTE_AS4,
  NOTE_GS4,NOTE_A4,NO_SOUND,NOTE_A4,NOTE_A4,
  NOTE_AS4,NOTE_A4,NO_SOUND,NOTE_A4,NOTE_AS4,NOTE_A4,
  NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4,
  NOTE_AS4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,

  NOTE_E4,NOTE_D4,NO_SOUND,NOTE_G4,NOTE_G4,
  NOTE_A4,NOTE_G4,NO_SOUND,NOTE_G4,NOTE_A4,NOTE_G4,
  NOTE_G4,NOTE_C5,NOTE_B4,NOTE_A4,
  NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_D4,NOTE_C4,NO_SOUND,NOTE_C4,NOTE_E4,NOTE_G4,
  NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4,NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4,

  NOTE_AS4,NOTE_AS4,NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4,
  NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,
  NOTE_FS4,NOTE_G4,NO_SOUND,NOTE_C4,
  NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,

  NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4,
  NOTE_G4,NOTE_FS4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_C5,NOTE_AS4,
  NOTE_GS4,NOTE_A4,NO_SOUND,NO_SOUND,NOTE_F4,
  NOTE_G4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_F4,
  NOTE_F4,NOTE_AS4,NOTE_AS4,NO_SOUND,NOTE_G4,
  NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_G4,//2ºFS4 
  
  NOTE_G4,NOTE_C5,NOTE_C5,NO_SOUND,NOTE_A4,
  NOTE_AS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_A4,//2ºGS4
  NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_G4,
  NOTE_G4,NOTE_F4,NO_SOUND,NOTE_E4,NOTE_F4,NOTE_G4,
  NOTE_AS4,NOTE_A4,NOTE_E4,NOTE_F4,NOTE_CS4,NOTE_D4,NOTE_AS4,NOTE_G4,
  NOTE_G4,NOTE_F4,NO_SOUND,NOTE_G4,NOTE_A4,NOTE_AS4,
  
  NOTE_B4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_D4,NOTE_AS4,
  NOTE_A4,NOTE_F4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_E4,
  NOTE_F4 
};


// Duração das Notas: Colcheia:8; Semínima: 4; Mínima:2; Semibreve:1
int tempoNotas[] = {
  4,
  6,16,6,16,6,16,6,16,
  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,16,8,
  6,16,6,16,6,16,6,16,

  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,6,16,
  4,4,8,8,6,16,
  4,2,8,8,
  8,8,8,8,8,8,8,8,

  4,4,4,6,16,
  4,4,8,8,6,16,
  4,2,8,8,
  8,8,8,8,8,8,8,8,
  4,4,8,8,8,8,
  8,8,8,8,8,8,8,8,

  2,4,4,
  6,16,6,16,6,16,6,16,
  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,4,
  6,16,6,16,6,16,6,16,

  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,8,16,
  6,16,6,16,6,16,6,16,
  3,8,4,8,8,
  6,16,6,16,6,16,6,16,
  
  3,8,4,8,8,
  6,16,6,16,6,16,6,16,
  4,3,8,8,8,
  4,4,8,8,8,8,
  8,8,8,8,8,8,8,8,
  4,4,8,8,8,8,
  
  8,8,8,8,4,4,
  4,6,16,4,6,16,
  2
};

const int compasso = 1500; // Altera o compasso da música 
const int compasso2 = 700; // Altera o compasso da música 


void setup() {
  pinMode(versao1,OUTPUT); 
  pinMode(versao2,OUTPUT); 
  pinMode(versao3,OUTPUT);

  //oled
  display.init(); // iniciando o display oled
  display.flipScreenVertically(); //orientacao do texto

  // Set outputs to LOW
  digitalWrite(versao1, LOW);
  digitalWrite(versao2, LOW);
  digitalWrite(versao3, LOW);
  //web
  // Connect to Wi-Fi network with SSID and password
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();


}

void loop(){
//web
    display.clear();//LIMPA O BUFFER PARA O DISPLAY
    display.display();//ENVIA UM BUFFER PARA O DISPLAY
    display.setTextAlignment(TEXT_ALIGN_LEFT);//DEFINE O ALINHAMENTO DO DISPLAY
    display.setFont(ArialMT_Plain_16);//DEFINE A FONTE E O TAMANHO PARA ESCRITA
    display.drawString(0, 0, "ROBÓTICA P E T"); //10=ESPACAMENTO A ESQUERA E 0=LINHA DO TESTO
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 19, "ALUNO MAKER DIGITAL"); 
    display.drawString(0, 33, "HINO NACIONAL DIGITAL");// ESCREVE TEXTO NA POSICAO INDICADA:1=POSICAO HORIZONTAL E 23=POSIC VERTICAL
    display.drawString(0, 46, "PLAYER - WEBSERVICE");// ESCREVE TEXTO NA POSICAO INDICADA:33=POSICAO HORIZONTAL E 35=POSIC VERTICAL
    //display.drawString(0, 58, String((int)WiFi.localIP()));// ESCREVE TEXTO NA POSICAO INDICADA:8=POSICAO HORIZONTAL E 50=POSIC VERTICAL
    display.display();
    delay(2000);

//web   
   
  
    for (int Nota = 0; Nota < 230; Nota++) {//o número 80 indica quantas notas tem a nossa matriz.
    int tempo = compasso/tempoNotas[Nota]; //Tempo = compasso dividido pela indicação da matriz tempoNotas.
    
    if (versao1 == HIGH) {
    tone(falante, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*0.7);
  } else if (versao2 == HIGH) {
    tone(falante, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*0.4);
    
  }  if (versao3 == HIGH) {
    tone(falante, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*0.3);
    
  }     
    
  }
  
  //Não é necessária a repetição pois a mesma será feita pelo botão Reset.

  //wevWiFiClient client = server.available();   // Listen for incoming clients
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            //*****
            // HINO WEB
            for (int Nota = 0; Nota < 230; Nota++) {//o número 80 indica quantas notas tem a nossa matriz.
            int tempo = compasso/tempoNotas[Nota]; //Tempo = compasso dividido pela indicação da matriz tempoNotas.
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("VERSÃO 1 ON");
              outputD1State = "on";
              tone(falante, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
              // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
              delay(tempo*0.7);
              } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("VERSÃO 1 OFF");
              outputD1State = "off";
              digitalWrite(versao1, LOW);
              
              
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("VERSÃO 2");
              outputD2State = "on";
              tone(falante, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
              // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
              delay(tempo*0.4);
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("VERSÃO 2 OFF");
              outputD2State = "off";
              digitalWrite(versao2, LOW);
              
            }else if (header.indexOf("GET /0/on") >= 0) {
              Serial.println("VERSÃO 3");
              outputD3State = "on";
              tone(falante, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
              // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
              delay(tempo*0.3);  
            } else if (header.indexOf("GET /0/off") >= 0) {
              Serial.println("VERSÃO 3 OFF");
              outputD3State = "off";
              digitalWrite(versao3, LOW);
            }
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; background-color: #9800FF}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            // Web Page Heading
            client.println("<body><p>ROBOTICA LIVRE</p>");
            client.println("<body><p>METODOLOGIA</p>");
            client.println("<body><h1>PET - ALUNO MAKER</h1>");
            client.println("<body><p>CRE CRTE RECANTO DAS EMAS</p>");
            client.println("<body><p> -------- * - * - * - * - * --------</p>");
            // Display current state, and ON/OFF buttons for GPIO VERSOES 
            client.println("<p>VERSAO 1</p>");
            // If the output5State is off, it displays the ON button       
            if (outputD1State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">LIGADO</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">DESLIGADO</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO AZUL  
            client.println("<p>VERSAO 2 </p>");
            // If the output4State is off, it displays the ON button       
            if (outputD2State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">LIGADO</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">DESLIGADO</button></a></p>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO VERMELHO
            client.println("<p>VERSAO 3</p>");
            // If the output5State is off, it displays the ON button       
            if (outputD3State=="off") {
              client.println("<p><a href=\"/0/on\"><button class=\"button\">LIGADO</button></a></p>");
            } else {
              client.println("<p><a href=\"/0/off\"><button class=\"button button2\">DESLIGADO</button></a></p>");
            } 
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
//Fim de Programa
