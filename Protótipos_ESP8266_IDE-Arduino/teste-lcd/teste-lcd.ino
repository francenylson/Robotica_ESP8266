#include <Wire.h>  //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27, 20, 4); //FUNÇÃO DO TIPO "LiquidCrystal_I2C"
 
void setup()
{
 
}
 
void loop()
{
  //PROGRAMAÇÃO DE CÓDIGO DO VOID LOOP - PRA ESSE EXEMPLO PODE FICAR SEM NADA
 lcd.init();   // initializing the LCD
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("BIOTECH_PROJECT"); // EXIBE O SEGUNDO TEXTO NA PRIMEIRA LINHA
  lcd.setCursor(1, 1);
  lcd.print("ALUNOS MAKER DIGITAL"); // EXIBE O SEGUNDO TEXTO NA SEGUNDA LINHA
  lcd.setCursor(8, 2);
  lcd.print("--o--"); // EXIBE O SEGUNDO TEXTO NA SEGUNDA LINHA
  lcd.setCursor(0, 3);
  lcd.print("CED 104"); // EXIBE O SEGUNDO TEXTO NA SEGUNDA LINHA
}
