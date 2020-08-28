/*******************************************************************************
*
*    Projeto 35 - Padrão para tocar qualquer melodia com buzzer ou auto-falante
*                   http://squids.com.br/arduino
*
*******************************************************************************/
#include "notas.h" //arquivo com definição de todas as notas anexadas
#define NO_SOUND 0

// Notas que devem ser tocadas disponibilizadas ordenadamente;
int melodia[] ={
  NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4
};

// Duração das Notas: Semicolcheia:16; Colcheia:8; Semínima: 4; Mínima:2; Semibreve:1
int tempoNotas[] ={
   4,4,4,4,4,4,4
};

const int compasso = 1500; // Altera o compasso da música
const int comprimento = 7; // Número de notas musicais indicado no vetor melodia
const int pinBuzzer = 8; // Indica a porta digital ligada ao buzzer

void setup(){
  pinMode(pinBuzzer, OUTPUT);
}

void loop(){
  for (int Nota = 0; Nota <comprimento; Nota++){//comprimento indica quantas notas tem o nosso vetor.
    int tempo = compasso/tempoNotas[Nota]; //Tempo = compasso dividido pela indicação do vetor tempoNotas.
    tone(pinBuzzer, melodia[Nota],tempo); //Toca a nota indicada pelo vetor melodia durante o tempo.
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*1.2);
  }
  delay(3000);
} 
