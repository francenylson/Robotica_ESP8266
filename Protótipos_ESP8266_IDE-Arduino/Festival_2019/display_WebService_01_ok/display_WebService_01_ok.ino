/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid     = "Vivo-Internet-9CF3";
const char* password = "15262CFA";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String outputD1State = "off";
String outputD2State = "off";
String outputD3State = "off";

// Assign output variables to GPIO pins
const int outputD1 = D1;
const int outputD2 = D2;
const int outputD3 = D3;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(outputD1, OUTPUT);
  pinMode(outputD2, OUTPUT);
  pinMode(outputD3, OUTPUT);
  // Set outputs to LOW
  digitalWrite(outputD1, LOW);
  digitalWrite(outputD2, LOW);
  digitalWrite(outputD3, LOW);

  // Connect to Wi-Fi network with SSID and password
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
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("VELOCIDADE 1 on");
              outputD1State = "on";
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(1000);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(1000);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(1000);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(1000);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(1000);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(1000);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(1000);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(1000);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(1000);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(1000);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(1000);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(1000);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(1000);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(900);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              
              
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("VELOCIDADE 1 off");
              outputD1State = "off";
              digitalWrite(outputD1, LOW);
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("VELOCIDADE 2 on");
              outputD2State = "on";
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(300);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(200);
                            digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(400);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(400);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(300);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              
              
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("VELOCIDADE 2 off");
              outputD2State = "off";
              digitalWrite(outputD2, LOW);
            }else if (header.indexOf("GET /0/on") >= 0) {
              Serial.println("VELOCIDADE 3 on");
              outputD3State = "on";
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(150);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              delay(100);
              digitalWrite(outputD1, LOW);
              digitalWrite(outputD2, LOW);
              digitalWrite(outputD3, LOW);
              delay(50);
              digitalWrite(outputD1, HIGH);
              digitalWrite(outputD2, HIGH);
              digitalWrite(outputD3, HIGH);
              
            } else if (header.indexOf("GET /0/off") >= 0) {
              Serial.println("VELOCIDADE 3 off");
              outputD3State = "off";
              digitalWrite(outputD3, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>PAINEL ROBOTICA PET</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO VERMELHO 
            client.println("<p>VELOCIDADE 1</p>");
            // If the output5State is off, it displays the ON button       
            if (outputD1State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">LIGADO</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">DESLIGADO</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO AZUL  
            client.println("<p>VELOCIDADE 2 </p>");
            // If the output4State is off, it displays the ON button       
            if (outputD2State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">LIGADO</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">DESLIGADO</button></a></p>");
            }
            client.println("</body></html>");

            // Display current state, and ON/OFF buttons for GPIO VERMELHO
            client.println("<p>VELOCIDADE 3</p>");
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
