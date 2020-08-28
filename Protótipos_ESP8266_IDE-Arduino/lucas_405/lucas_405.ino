#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 lcd.begin (20,4);
}
 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("********************");
  lcd.setCursor(9,1);
  lcd.print("VIDA");
  lcd.setCursor(5,2);
  lcd.print("DE SILICIO");
  lcd.setCursor(0,3);
 lcd.print("********************");
}

