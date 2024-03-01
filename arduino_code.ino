#include <Wire.h>

#include <LiquidCrystal_I2C.h>  
int lcdColumns = 16;
int lcdRows = 2;  
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 


char Display;
String Word;
String messageStatic;
String messageToScroll;


int L1;
int L2;

void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.begin(16,2);// Columnas y filas de LCD
  Serial.begin(9600);
}

void loop() {

  if(Serial.available())
  {
    Display = Serial.read();  
    Word = Word + Display; 

if (Display == '*') {

      Serial.println(Word);
      Serial.println();
      L1 = Word.indexOf(',');
      messageStatic = Word.substring(0, L1);
      L2 = Word.indexOf(',', L1+1);
      messageToScroll = Word.substring(L1+1, L2);

      Serial.print("messageStatic");
      Serial.println(messageStatic); 
      Serial.print("messageToScroll");
      Serial.println(messageToScroll);
      Word = "";
      lcd.setCursor(0,0);
      lcd.print(messageStatic);
       lcd.setCursor(0,1);
      lcd.print(messageStatic);
  }
  
        }
}
