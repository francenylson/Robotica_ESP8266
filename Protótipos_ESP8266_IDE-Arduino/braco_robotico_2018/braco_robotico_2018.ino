/** Código final do B.R.A.M.S - Braço Robótico Articulado de Movimentos Sincronizados **/
// Elaborado por Tony Emerson Marim em 08/07/2016.
/** mecatronizei@gmail.com **/
/** Controle de 4 servo motores via potenciômetro ou aplicativo celular **/

#include <Servo.h> //biblioteca do servo motor

//constantes ao quais se referem os pinos digitais de sinalização.
const int led = 10;  
const int botao = 8;

//variável de estado inicial do botão.
int estadoBotao = 0;

//portas digitais dos servos e suas ações.
//no potenciômetro.
int port_servo_canal_1 = 3;//servobase
int port_servo_canal_2 = 5;//servobraco
int port_servo_canal_3 = 6;//servoaltura
int port_servo_canal_4 = 9;//servogarra
int port_serial;

//portas analógicas dos potenciometros e suas funções.
int potbase = 0;
int potbraco = 1;
int potaltura = 2;
int potgarra = 3;

//valores de início para os ângulos
int angulobase = 0;
int angulobraco = 0;
int anguloaltura = 0;
int angulogarra = 0;

//variáveis dos servos.
//no potenciômetro.
Servo servo_canal_1;//base
Servo servo_canal_2;//braco
Servo servo_canal_3;//altura
Servo servo_canal_4;//garra

void setup()
{
  //Faixa de transmissão do módulo Bluetooth
  Serial.begin(9600);
  Serial.setTimeout(4);

  //definindo pinos de entrada e saída.
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT);
 
  //Setup de carregamento das variáveis dos servos.
  servo_canal_1.attach(3);//(servobase)
  servo_canal_2.attach(5);//(servoaltura)
  servo_canal_3.attach(6);//(servogarra)
  servo_canal_4.attach(9);//(servobraco)
  servo_canal_1.write(port_servo_canal_1);
  servo_canal_2.write(port_servo_canal_2);
  servo_canal_3.write(port_servo_canal_3);
  servo_canal_4.write(port_servo_canal_4);
}

void loop(){
 
 estadoBotao = digitalRead(botao);
 //Condição executada enquanto botão acionado e Led verde aceso
 if(estadoBotao == HIGH){
 
        digitalWrite(led,HIGH);
        angulobase=analogRead(potbase);
        angulobase=map(angulobase,0,1024,0,180);
        servo_canal_1.write(angulobase); //leitura do angulo no potênciometro, mapeamento, e registro no servo referente a base.
       
        angulobraco=analogRead(potbraco);
        angulobraco=map(angulobraco,0,1024,0,180);
        servo_canal_2.write(angulobraco); //leitura do angulo no potênciometro, mapeamento, e registro no servo referente ao braço.
       
        anguloaltura=analogRead(potaltura);
        anguloaltura=map(anguloaltura,0,1024,0,180);
        servo_canal_3.write(anguloaltura); //leitura do angulo no potênciometro, mapeamento, e registro no servo referente a altura do braço.
       
        angulogarra=analogRead(potgarra);
        angulogarra=map(angulogarra,0,1024,0,40);
        servo_canal_4.write(angulogarra); //leitura do angulo no potênciometro, mapeamento, e registro no servo referente a abertura da garra.

}else{
    digitalWrite(led,LOW);//Condição com Led verde apagada assumida pelo bluetooth
 }
 if (Serial.available()>0) {
    port_serial = Serial.parseInt();
    if (port_serial >0 && port_serial <180)
    {
        port_servo_canal_1 = port_serial;
        port_servo_canal_2 = map(port_serial, 0, 180, 0, 180);
        servo_canal_1.write(port_servo_canal_1);
}
   if (port_serial >180 && port_serial <360)
    {
        port_servo_canal_2 = port_serial;
        port_servo_canal_2 = map(port_serial, 180, 360, 0, 180);
        servo_canal_2.write(port_servo_canal_2);
}
   if (port_serial >360 && port_serial <540)
    {
        port_servo_canal_3 = port_serial;
        port_servo_canal_3 = map(port_serial, 360, 540, 0, 180);
        servo_canal_3.write(port_servo_canal_3);
}
       if (port_serial >540 && port_serial <720)
    {
        port_servo_canal_4 = port_serial;
        port_servo_canal_4 = map(port_serial, 540, 720, 0, 180);
        servo_canal_4.write(port_servo_canal_4);
}
     
  }
}
