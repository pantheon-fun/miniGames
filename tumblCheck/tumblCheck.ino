/* 
 * Project name         Button
 * Author:              Lanity Roshoose
 * Date of mod.         06.05.2021
 * Version              beta 2.0
 */

//Russian Symbols
#define BIG_B "\xA0"
#define BIG_G "\xA1"
#define BIG_YO "\xA2"
#define BIG_ZH "\xA3"
#define BIG_Z "\xA4"
#define BIG_I "\xA5"
#define BIG_IY "\xA6"
#define BIG_L "\xA7"
#define BIG_P "\xA8"
#define BIG_U "\xA9"
#define BIG_PH "\xAA"
#define BIG_CH "\xAB"
#define BIG_SH "\xAC"
#define BIG_TZ "\xAD"
#define BIG_EE "\xAE"
#define BIG_AA "\xAF"
#define BIG_U "\xB0"
#define BIG_YA "\xB2"
#define BIG_D "\xE0"
#define BIG_C "\xE1"
#define BIG_SCH "\xE2"

#define B "\xB2"
#define V "\xB3"
#define G "\xB4"
#define YO "\xB5"
#define ZH "\xB6"
#define Z "\xB7"
#define I "\xB8"
#define IY "\xB9"
#define K "\xBA"
#define L "\xBB"
#define M "\xBC"
#define N "\xBD"
#define P "\xBE"
#define T "\xBF"
#define CH "\xC0"
#define SH "\xC1"
#define TZ "\xC2"
#define EE "\xC3"
#define MZ "\xC4"
#define AA "\xC5"
#define U "\xC6"
#define YA "\xC7"
#define D "\xE3"
#define PH "\xE4"
#define C "\xE5"
#define SCH "\xE6"
#include <Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,15,2);


int pinsT[8] = {23, 25, 27, 29, 31, 33, 35, 37};
int pinsL[8] = {22, 24, 26, 28, 30, 32, 34, 36};
int data[8];
char color[8] = {'r', 'y', 'r', 'g', 'b', 'y', 'g', 'b'};


void blink(int amount){
  for(int i = 0; i < 8; i++){
    digitalWrite(pinsL[i],LOW);
  }
  for (int k = 0; k < amount*2; k++){
    for(int l = 0; l < 8; l++){
      digitalWrite(pinsL[l], !digitalRead(pinsL[l]));
    }
    delay(250);
  }
}

void initSequence(){
  randomSeed(analogRead(A5));
  for(int i = 0; i < 8; i++){
    int n = random(0, 2);
    if(n == 1){data[i] = HIGH;}
    else if(n == 0){data[i] = LOW;}
  }
  Serial.println("Initiated data");
}

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(BIG_D "o" B "po " P "o" ZH "a" L "o" V "a" T MZ);
  lcd.setCursor(0, 1);
  lcd.print("  B Pantheon!");
  delay(1500);
  for(int i = 0; i < 8; i++){
    pinMode(pinsT[i], INPUT_PULLUP);
    pinMode(pinsL[i], OUTPUT);
  }
  delay(10);
  initSequence();
}

void first_mode(){
  bool _running = true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Pe" ZH I M " 1");
  lcd.setCursor(0,1);
  lcd.print(BIG_Z "a" ZH G I " " V "ce");
  while(_running){
    int sum = 0;
    for(int i = 0; i < 8; i++){
      if(digitalRead(pinsT[i]) == data[i]){
        digitalWrite(pinsL[i], HIGH);
        sum++;
      } else {
        digitalWrite(pinsL[i], LOW);
      }
    }
    if(sum == 8){
      _running = false;
    }
  }
}

void second_mode(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Pe" ZH I M " 2");
  lcd.setCursor(0,1);
  lcd.print(BIG_Z "a" ZH G I " ");
  Serial.println("Started_SM");
  bool _running = true;
  randomSeed(analogRead(A5));
  char onColor = color[random(0, 8)];
  switch(onColor){
    case 'r':
      lcd.print("Kpac" N EE IY);
      break;
    case 'g':
      lcd.print(BIG_Z "e" L YO N EE IY);
      break;
    case 'b':
      lcd.print("C" I N I IY);
      break;
    case 'y':
      lcd.print(BIG_ZH YO L T EE IY);
      break;
  }
  Serial.println(onColor); 
//  for(int i = 0; i < 8; i++){
//    Serial.println(data[i]);
//  }
  while(_running){
    _running = false;
    for(int i = 0; i < 8; i++){
      if(digitalRead(pinsT[i]) == data[i]){
        digitalWrite(pinsL[i], HIGH);
        if(color[i] != onColor){
          _running = true;
        }
      } else {
        digitalWrite(pinsL[i], LOW);
        if(color[i] == onColor){
          _running = true;
        }
      }
    }
    delay(100);
  }
}

void third_mode(){
  bool _running = true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Pe" ZH I M " 3");
  lcd.setCursor(0,1);
  while(_running){
    int sum = 0;
    for(int i = 0; i < 8; i++){
      if(digitalRead(pinsT[i]) == data[i]){
        digitalWrite(pinsL[i], HIGH);
        switch(color[i]){
          case 'r':
            sum += 1;
            break;
          case 'y':
            sum += 5;
            break;
          case 'b':
            sum += 10;
            break;
          case 'g':
            sum += 6;
            break;
        }  // bbr, gby, yybr
      }
      else{
        digitalWrite(pinsL[i], LOW);
      }
    }
    delay(100);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("Cy" M M "a: ");
    lcd.print(sum);
    lcd.print("/21");
    if(sum == 21){
      _running = false;
    }
  }
}

void loop(){
  first_mode();
  blink(5);
  delay(200);
  initSequence();
  second_mode();
  blink(5);
  delay(200);
  initSequence();
  third_mode();
  while(true){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("B" EE " " P "po" SH L I " " I G "py");
    lcd.setCursor(0,1);
    lcd.print("Coc" I);
    blink(50);
  }
}
