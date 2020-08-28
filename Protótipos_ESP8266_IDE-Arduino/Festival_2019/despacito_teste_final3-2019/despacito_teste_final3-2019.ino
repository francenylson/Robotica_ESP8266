#include "pitches.h"
const int sensorLdr = A0;
int led=D1;
int led2=D2;

int noteDuration;
int pauseBetweenNotes = 0;
int negra;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sensorLdr, INPUT);
     
  negra=640;

     
}

void loop() {

  
int sensorLdrStatus = analogRead(sensorLdr);

Serial.println("valor LDR");

Serial.println(sensorLdrStatus);

if (sensorLdrStatus <= 500) {

 chorus();
} else {
  
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  
}
 
}

void chorus(){
     notars(negra, NOTE_D5);
     notars(negra, NOTE_CS5);digitalWrite(led, HIGH);   // (1)
     notars(negra/2, NOTE_B4);
     notars(negra/4, NOTE_FS4);digitalWrite(led, LOW);    // (2)
     delay(negra/4); digitalWrite(led, HIGH);   // (3)
     notars(negra/4, NOTE_FS4);
     notars(negra/4, NOTE_FS4);
     digitalWrite(led, LOW);    // (4)
     digitalWrite(led2, LOW);
     notars(negra/4, NOTE_FS4);
     notars(negra/4, NOTE_FS4);
     digitalWrite(led, HIGH);   //  (1) 
     digitalWrite(led2, HIGH);
     
     notars(negra/4, NOTE_FS4);

     notars(negra/4, NOTE_B4);
     notars(negra/4, NOTE_B4);
     digitalWrite(led, LOW);    //  (2) 
      digitalWrite(led2, LOW); 
     notars(negra/4, NOTE_B4);
     digitalWrite(led, HIGH);   //  (3)  
     digitalWrite(led2, HIGH);
     notars(negra/2, NOTE_B4);
     digitalWrite(led, LOW);    //  (4)  
     digitalWrite(led2, LOW); 

     notars(negra/4, NOTE_A4);  
          
     notars(negra/4, NOTE_B4);
     digitalWrite(led, HIGH);   //  (1) 
      digitalWrite(led2, HIGH); 
     delay(negra/4); 
     delay(negra/4); 
     notars(negra/4, NOTE_G4);
     digitalWrite(led, LOW);    //  (2) 
     digitalWrite(led2, LOW); 
     
     delay(negra/4);digitalWrite(led, HIGH);   //  (3) 
//......
     notars(negra/4, NOTE_G4);  
     notars(negra/4, NOTE_G4);
     digitalWrite(led, LOW);    //  (4) 
     digitalWrite(led2, LOW);   
     notars(negra/4, NOTE_G4);  
     notars(negra/4, NOTE_G4);
     digitalWrite(led, HIGH);   //  (1)   
     digitalWrite(led2, HIGH); 
     notars(negra/4, NOTE_G4);  

     notars(negra/4, NOTE_B4);  
     notars(negra/4, NOTE_B4);  digitalWrite(led, LOW);    //  (2) 
     notars(negra/4, NOTE_B4);digitalWrite(led, HIGH);   //  (3) 
     notars(negra/2, NOTE_B4);digitalWrite(led, LOW);    //  (4) 
     
     notars(negra/4, NOTE_CS5);
     notars(negra/4, NOTE_D5);digitalWrite(led, HIGH);   //  (1) 
     delay(negra/4);
     delay(negra/4);
     notars(negra/4, NOTE_A4);
     digitalWrite(led, LOW);    //  (2)   
     digitalWrite(led2, LOW);
     delay(negra/4);
     digitalWrite(led, HIGH);   //  (3) 
     digitalWrite(led2, HIGH);
     
     notars(negra/4, NOTE_A4);     
     notars(negra/4, NOTE_A4);
     digitalWrite(led, LOW);    //  (4)  
     digitalWrite(led2, LOW);         
     notars(negra/4, NOTE_A4);               
     notars(negra/4, NOTE_A4);
     digitalWrite(led, HIGH);   //  (1)                
     digitalWrite(led2, HIGH);
     notars(negra/4, NOTE_D5);          
     notars(negra/4, NOTE_CS5);               
     notars(negra/4, NOTE_D5);
     digitalWrite(led, LOW);    //  (2)           
     notars(negra/4, NOTE_CS5);
     digitalWrite(led, HIGH);   //  (3)  
     digitalWrite(led2, HIGH);        
     notars(negra/2, NOTE_D5);
     digitalWrite(led, LOW);    //  (4)  
     digitalWrite(led2, LOW);              
     //
     notars(negra/4, NOTE_E5);
     notars_jai(negra/2, NOTE_E5,negra/4);  // (1)
//     notars(negra/2, NOTE_E5);  

    //-----------------------------------------------
      tone(D7,NOTE_CS5 ,negra*3/4);
    //-----------------------------------------------
      delay(negra/4);
      delay(negra/4);
     digitalWrite(led, LOW);    //  (2)   
     digitalWrite(led2, LOW);                  
      delay(negra/4);
     digitalWrite(led, HIGH);   //  (3)    
     digitalWrite(led2, HIGH);
                      
     noTone(D7);
     delay(negra/4);
     
     //--------------
     delay(negra/4);
     digitalWrite(led, LOW);    //  (4) 
     digitalWrite(led, LOW);

     delay(negra/4);
     delay(negra/4);       
  
}
void notars(int noteDuration,int LaNota ){

    //noteDuration=negra/4;
  tone(D7,LaNota ,noteDuration*0.9);
//      pauseBetweenNotes = noteDuration * 1.30;
      pauseBetweenNotes = noteDuration * 1.1;
      delay(pauseBetweenNotes);
      noTone(D7);  


}
void notars_jai(int noteDuration,int LaNota ,int Desfase){

    //noteDuration=negra/4;
  tone(D7,LaNota ,noteDuration*0.9);
//      pauseBetweenNotes = noteDuration * 1.30;
      pauseBetweenNotes = noteDuration * 1.1;
      delay(Desfase);
      
       digitalWrite(led, HIGH);   //  (1)  
       digitalWrite(led2, HIGH); 
      
        delay(pauseBetweenNotes-Desfase);
      noTone(D7);  


}
