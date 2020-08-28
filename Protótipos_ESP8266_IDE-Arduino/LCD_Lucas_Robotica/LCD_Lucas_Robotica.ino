#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  
  Serial.begin(115200);
  Serial.println("LCD...");

  Serial.println("Dose: check for LCD");

  Wire.begin();
  Wire.beginTransmission(0x27);
  
  
} 

void loop()
{
    lcd.setBacklight(255);
    lcd.home(); lcd.clear();
    lcd.print(" Fala ai Lucas");
    delay(2000);

    lcd.setBacklight(0);
    delay(1000);
    lcd.setBacklight(255);
    delay(1500);
    
    lcd.clear();
    lcd.print("LCD funcionando");
    lcd.cursor();
    delay(1500);
    
    lcd.clear();
    lcd.print("Pode usar agora");
    lcd.blink();
    delay(2000);
    
    lcd.clear();
    lcd.print("usar na estufa");
    lcd.noBlink();
    lcd.noCursor();
    delay(2000);

  
    lcd.clear();
    lcd.print("Como preferir");
    lcd.noDisplay();
    delay(2000);

 
    lcd.clear();
    lcd.print("Display ligado");
    lcd.display();
    delay(2000);
 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** Lucas");
    lcd.setCursor(0, 1);
    lcd.print("*** Lucas 405");
    delay(2000);

    lcd.scrollDisplayLeft();
    delay(700);

    lcd.scrollDisplayLeft();
    delay(700);

    lcd.scrollDisplayLeft();
    delay(700);

    lcd.scrollDisplayRight();
  } 

 
