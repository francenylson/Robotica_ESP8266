#include "ad.h"
#include "keypad.h"
#include "io.h"
#include "nokia5110.h"
#include "console.h"
#include "pwm.h"
#include "rgb.h"
#include "serial.h"
#include "so.h"
#include "ssd.h"
#include "timer.h"
#include "i2c.h"
#include "ds1307.h"


unsigned long tempoAntigo;

void setup() {
  //LCD
  //lcdInit();
  initializeDisplay(0xC0,0x07,0x014);

  //74HC595
  soInit();

  //Teclado
  kpInit();

  //Timer
  timerInit();

  //Conversor AD
  adInit();

  //Display 7 Seg.
  //ssdInit();

  //RGB
  rgbInit();

  //Buzzer
  pwmInit();
  pwmBuzzer(0);

  for(int i=0; i<504; i++) LcdWriteData(0x00); // clear LCD
}

void loop() {

    int i_adc0 = 0;
    int i_adc1 = 0;
    int i_adc2 = 0;
    int i_adc3 = 0;
    int j = 0;
    int key = 0;

    //LM35
    i_adc0 = adRead(0);                    // Leitura do TEMP
    i_adc1 = adRead(1);                    // Leitura do POT
    i_adc2 = adRead(2);                    // Leitura LDR
    i_adc3 = adRead(3);                    // Leitura do POT
    
    float mv = ( i_adc0/1024.0)*5000; 
    float temperatura_celsius = mv/10;

    LcdXY(0,0);
    LcdWriteString("TEMP:");
    
    LcdXY(32,0);
    
    LcdWriteCharacter(((int)temperatura_celsius / 100) % 10 + 48);
    LcdWriteCharacter(((int)temperatura_celsius / 10) % 10 + 48);
    LcdWriteCharacter(((int)temperatura_celsius / 1) % 10 + 48);

    LcdXY(0,1);
    LcdWriteString("LUZ_:");
    LcdXY(32,1);
    
    LcdWriteCharacter((i_adc1 / 100) % 10 + 48);
    LcdWriteCharacter((i_adc1 / 10) % 10 + 48);
    LcdWriteCharacter((i_adc1 / 1) % 10 + 48);

    LcdXY(0,2);
    LcdWriteString("CRTE:");
    LcdXY(32,2);
    
    LcdWriteCharacter((i_adc2 / 100) % 10 + 48);
    LcdWriteCharacter((i_adc2 / 10) % 10 + 48);
    LcdWriteCharacter((i_adc2 / 1) % 10 + 48);

    LcdXY(0,3);
    LcdWriteString("CEF101");
    LcdXY(32,3);
    
    LcdWriteCharacter((i_adc3 / 100) % 10 + 48);
    LcdWriteCharacter((i_adc3 / 10) % 10 + 48);
    LcdWriteCharacter((i_adc3 / 1) % 10 + 48);
    
    LcdXY(0,4);
    LcdWriteString("KEY_:");
    LcdXY(32,4);
    kpDebounce();                      //Realiza o Debounce do teclado
    
    for (key = 0; key < 4; key++) 
    {         //Varredura
      if (kpRead() & (1 << key)) 
      {       //Identifica qual tecla foi pressionada
        LcdWriteCharacter(key + 48);
        break;
      }
    }
    
    for(j = 0; j < 2; j++){                  // Delay
    //ssdUpdate();
    timerDelay(50);
  }  
}
