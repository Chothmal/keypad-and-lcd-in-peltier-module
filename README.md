# keypad-and-lcd-in-peltier-module
#include "Keypad.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'7','8','9','%'},
  {'4','5','6','@'},
  {'1','2','3','-'},
  {'*','0','=','+'}
};

// For Arduino Microcontroller
byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9,8,7, 6}; 



Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x20, 20, 4); 

const int len_key = 5;
char master_key[len_key] = {'1','2','3','4','5'};
char attempt_key[len_key];
int z=0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Insert Password");
}

void loop() {
  char key = keypad.getKey();
  lcd.setCursor(z-1,1);
  lcd.print("*");
  if (key){
    switch(key){
      case '*':
        z=0;
        break;
      case '=':
        delay(10); // added debounce
        checkKEY();
        break;
      default:
         attempt_key[z]=key;
         z++;
      }
  }
}

void checkKEY()
{
   int correct=0;
   int i;
   for (i=0; i<len_key; i++) {
    if (attempt_key[i]==master_key[i]) {
      correct++;
      }
    }
   if (correct==len_key && z==len_key){
    lcd.setCursor(0,1);
    lcd.print("Correct Key");
    delay(10);
    z=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Insert pattern");
   }
   else
   {
    lcd.setCursor(0,1);
    lcd.print("Incorrect Key");
    delay(30);
    z=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Insert Password");
   }
   for (int zz=0; zz<len_key; zz++) {
    attempt_key[zz]=0;
   }
}
