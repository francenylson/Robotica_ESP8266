#include "pitches.h"

int falante = 7;
int tempo = 500;
// Array com as notas na ordem em que devem ser tocadas:
int notas[] = {
 NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
 NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 
};

void setup() {
 // nada a fazer aqui
}
void loop() {
 // Tocar cada nota do array durante o tempo especificado:
 for (int i = 0; i < 8; i++) {
   tone(falante, notas[i], tempo);
   delay(tempo);
 }
}
