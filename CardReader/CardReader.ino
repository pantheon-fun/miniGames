/* 
 * Project name         CardReader
 * Author:              Lanity Roshoose
 * Date of mod.         17.04.2021
 * Version              beta 1.1
 */


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PantheonDuino.h>
#include "tones.h"

//===========Настройки=============

#define speakerPin 7 //Пин на динамик
#define readerPin 6  //Пин на датчик карты
#define irPin 5      //Пин на инфракрасный
#define timing1 400
#define timing2 70
byte shot[2];

//=================================

unsigned long int time1;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  randomSeed(A7);
  pinMode(readerPin, INPUT);
  pinMode(irPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  lcd.init();
  lcd.backlight();

  toneStart();
}

void toneStart(){
  tone(speakerPin, NOTE_A7); delay(100);
  tone(speakerPin, NOTE_G7); delay(100);
  tone(speakerPin, NOTE_E7); delay(100); 
  tone(speakerPin, NOTE_C7); delay(100);  
  tone(speakerPin, NOTE_D7); delay(100); 
  tone(speakerPin, NOTE_B7); delay(100); 
  tone(speakerPin, NOTE_F7); delay(100); 
  tone(speakerPin, NOTE_C7); delay(100);
  noTone(speakerPin);
}

void lcdSlow(){
  lcd.clear();
  String messages[3] = {
    "    Too slow!   ",
    "   Try faster   ",
    "    Try more    "
    };
  lcd.setCursor(0,0);
  lcd.print("Are you trying?");
  lcd.setCursor(0,1);
  lcd.print(messages[random(0,3)]);
}

void lcdFast(){
  lcd.clear();
  String messages[5] = {
    "    Too fast!   ",
    "   Try slower   ",
    "    Try more    ",
    " Are u in hurry?",
    " Slower, slower "
    };
  lcd.setCursor(0,0);
  lcd.print("Are you trying?");
  lcd.setCursor(0,1);
  lcd.print(messages[random(0,5)]);
}

void toneError(){
  for (int j=0; j <3; j++){
    for (int i=1000; i<2000; i=i*1.1) { tone(speakerPin, i); delay(10); }
    delay(50);
    for (int i=1000; i>500; i=i*1.9) { tone(speakerPin, i); delay(10); }
    delay(50);
    }
    noTone(speakerPin);
}

void toneOk(){
  for (int i=400; i<6000; i=i*1.5) { tone(speakerPin, i); delay(30); }
  noTone(speakerPin);
}

void(* reset) (void) = 0; // Функция перезапуска

bool started = false;
void loop() {
  if(!started){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Waiting for shot");
    lcd.setCursor(0,1);
    lcd.print("<------ Receiver");
    getShot(irPin, &Serial, shot);
    if(shot[0] != 0){
      started = true;
    }
    time1 = millis();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Waiting for card");
    lcd.setCursor(0,1);
    lcd.print("Cardreader ---->");
  }
  if(!started){
    loop();
  }
  bool done = false;
  // put your main code here, to run repeatedly:
  //digitalWrite(6, LOW);
  if(digitalRead(readerPin)){
    delay(timing1);
    if(digitalRead(readerPin)){
      delay(timing2);
      if(!digitalRead(readerPin)){
        done = true;  
      } else {
        while(digitalRead(readerPin)){
          delay(50);
        }
        lcdSlow();
        toneError();
      }
    } else {
      lcdFast();
      toneError();
    }
  }
  unsigned long int time2 = millis();
  if(time2 - time1 >= 20000){
    reset();
  }
  if(done){
    lcd.clear();
    byte shot2[2];
    toneOk();
    lcd.setCursor(0,0);
    lcd.print("Waiting for shot");
    lcd.setCursor(0,1);
    lcd.print("<------ Receiver");
    getShot(irPin, &Serial, shot2);
    if(shot2[0] != shot[0] || shot2[1] != shot[1]){
      reset();
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Card Accepted!");
    lcd.setCursor(0,1);
    lcd.print("    PANTHEON    ");
    toneOk();
  }
}
