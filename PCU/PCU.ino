#define pinY A0
#define pinX A1
#define pinSW 13

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "IRremote.h"

const byte ADMIN_KILL           = 0x00;
const byte PAUSE_UNPAUSE        = 0x01;
const byte START_GAME           = 0x02;
const byte RESTORE_DEFAULTS     = 0x03;
const byte RESPAWN              = 0x04;
const byte NEW_GAME             = 0x05; //Restores AidKit
const byte FULL_AMMO            = 0x06;
const byte END_GAME             = 0x07;
const byte RESET_CLOCK          = 0x08;
const byte CHANGE_COLOR         = 0x09; //Red - Blue, not Red to Red
const byte INITIALIZE_PLAYER    = 0x0A;
const byte EXPLODE_PLAYER       = 0x0B;
const byte NEW_GAME_READY       = 0x0C;
const byte FULL_HEALTH          = 0x0D;
const byte FULL_ARMOR           = 0x0F;
const byte FLAG_CAPTURE         = 0x11;
const byte BOMB_DISARMED        = 0x12;
const byte CLEAR_SCORES         = 0x14;
const byte TEST_SENSORS         = 0x15;
const byte STUN_PLAYER          = 0x16;
const byte DISARM_PLAYER        = 0x17;

const byte favourites[4] = {NEW_GAME, START_GAME, ADMIN_KILL, FULL_AMMO};
String favouritesS[4] = {"New game", "Start game", "Admin kill", "Full ammo"};
const byte fun[4] = {EXPLODE_PLAYER, STUN_PLAYER, DISARM_PLAYER, TEST_SENSORS};
String funS[4] = {"Explode", "Stun", "Disarm", "Sensor test"};

class Lt_transmitter {
public:
  Lt_transmitter(){
    IrSender.begin(3, true);
    }
  void sendCommand(byte byte2){
    unsigned long res = 0x83;
    res <<= 8;
    res |= byte2;
    res <<=8;
    res |= 0xE8;
    IrSender.sendSony(res, 24);
  }
};


Lt_transmitter trans;

int current_menu = 0;
int current_path = 0;

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hi, I am PCU!");
  lcd.setCursor(0, 1);
  lcd.print("    PANTHEON");
  pinMode(pinSW, INPUT_PULLUP);
  pinMode(pinY, INPUT);
  pinMode(pinX, INPUT);
  lcd.setCursor(0,0);
  lcd.print(funS[0]);
}

void loop() {
  float y = analogRead(pinY);
  float x = analogRead(pinX);
  int sw = digitalRead(pinSW);
  int new_menu = current_menu;
  int new_path = current_path;


  for(int i = 0; i < 1; i++){
    if(sw == LOW){
      while(digitalRead(pinSW) == LOW){
        delay(150);
      }
      if(current_menu == 0){
        trans.sendCommand(favourites[current_path]);
      } else {
        trans.sendCommand(fun[current_path]);
      }
    }
    if(y < 150){
      while(analogRead(pinY) < 150){
        delay(150);
      }
      new_menu--;
      if(new_menu < 0){new_menu = 0;}
      break;
    } else if(y > 850){
      while(analogRead(pinY) > 850){
        delay(150);
      }
      new_menu++;
      if(new_menu > 1){new_menu = 1;}
      break;
    }
    if(x < 150){
      while(analogRead(pinX) < 150){
        delay(150);
      }
      new_path--;
      if(new_path < 0){new_path = 0;}
      break;
    } else if(x > 850){
      while(analogRead(pinX) > 850){
        delay(150);
      }
      new_path++;
      if(new_path > 3){new_path = 3;}
      break;
    }
  }

  if(current_menu != new_menu || current_path != new_path){
    lcd.clear();
    lcd.setCursor(0,0);
    if(new_menu == 0){
      lcd.print("Favourites");
      current_menu = 0;
      lcd.setCursor(0,1);
      lcd.print(favouritesS[new_path]);
    } else {
      current_menu = 1;
      lcd.print("FUN");
      lcd.setCursor(0,1);
      lcd.print(funS[new_path]);
    }
    current_path = new_path;
    Serial.print("Current menu:   ");
    Serial.println(current_menu);
    Serial.print("Current path:   ");
    Serial.println(current_path);
    Serial.println(funS[current_path]);
  }
}
