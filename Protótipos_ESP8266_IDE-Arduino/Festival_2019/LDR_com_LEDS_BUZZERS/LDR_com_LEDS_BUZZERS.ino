/*Projeto PET i - ALUNO MAKER DIGITAL
  Curso : INTRODUÇÃO A ROBÓTICA LIVRE - ALUNO MAKER DIGITAL
  /Programa : Controlando LED RGB e webservers
  Autor : Francenylson (sketch exemplo da IDE Arduino com adaptações)*/
  
// Definição dos pinos - sensor LDR e led
const int sensorLdr = A0;
const int led_1 = D0;
const int led_2 = D2;
const int led_3 = D4;
const int led_4 = D6;
const int led_5 = D8;
const int buzzer = D7;


void setup(void)
{
  //velocidade monitor serial
  Serial.begin(115200);
  
  // Inicialização Serial LDR
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorLdr, INPUT);

  // iniciarlizar desligado
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(buzzer, LOW);
  
}
 
void loop(void)
{
  //ldr
  int sensorLdrStatus = analogRead(sensorLdr);

  //mostrar no monitor
  Serial.println(sensorLdrStatus);
  
 if (sensorLdrStatus >= 170 && sensorLdrStatus <=250) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW); 
    digitalWrite(led_4, LOW); 
    digitalWrite(led_5, LOW); 
    digitalWrite(buzzer, LOW); 
    delay(500);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW); 
    digitalWrite(led_4, LOW); 
    digitalWrite(led_5, LOW); 
    digitalWrite(buzzer, LOW); 
    delay(500);
     
  }
  else if (sensorLdrStatus <= 170 & sensorLdrStatus >= 70) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH); 
    digitalWrite(led_4, HIGH); 
    digitalWrite(led_5, LOW); 
    digitalWrite(buzzer, LOW); 
    delay(500);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH); 
    digitalWrite(led_4, HIGH); 
    digitalWrite(led_5, LOW); 
    digitalWrite(buzzer, LOW); 
    delay(500);
    
  }
  else if(sensorLdrStatus <= 70) {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH); 
    digitalWrite(led_4, HIGH); 
    digitalWrite(led_5, HIGH); 
    digitalWrite(buzzer, HIGH); 
    delay(100);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH); 
    digitalWrite(led_4, HIGH); 
    digitalWrite(led_5, HIGH); 
    digitalWrite(buzzer, LOW); 
    delay(100);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH); 
    digitalWrite(led_4, HIGH); 
    digitalWrite(led_5, HIGH); 
    digitalWrite(buzzer, LOW); 
    delay(100);
    
  } else if(sensorLdrStatus >= 261) {
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW); 
    digitalWrite(led_4, LOW); 
    digitalWrite(led_5, LOW); 
    digitalWrite(buzzer, LOW); 
    
     
  }

}
