//DEFININDO PINOS DAS BARREIRAS
#include <Servo.h>

Servo b1;
Servo b2;
Servo b3;
Servo b4;

//DEFININDO PINO NIVELDE ÁGUA
#define sensor_chuva A0

int monitorando_chuva;

void setup() {
  // PINOS DOS SERVOS
  b1.attach(D0);
  b2.attach(D3);
  b3.attach(D6);
  b4.attach(D8);

  //PINO DO SENSOR DE CHUVA
  pinMode(sensor_chuva, INPUT);
  Serial.begin(115200); 

  //INICIALIZANDO O MICROCONTROLADOR COM OS SERVOS EM POSIÇÃO 0
  b1.write(0);
  b2.write(0);
  b3.write(0);
  b4.write(0);
  Serial.println("servos em posição zero");
}

void loop() {
  monitorando_chuva = analogRead(sensor_chuva);
  Serial.print("Valor do sensor de chuva");
  Serial.print(monitorando_chuva);
  

  if (monitorando_chuva < 600) {
    b1.write(90);
    b2.write(90);
    b3.write(90);
    b4.write(90);
    Serial.println("Levantando Barreiras");
  } else {
    Serial.println("Barreira desativada");
    b1.write(0);
    b2.write(0);
    b3.write(0);
    b4.write(0);
  }
}
