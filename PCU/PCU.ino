#define pinY A1
#define pinX A2
#define pinSW 4

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <IRremote.h>

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const byte NEW_GAME             = 0x05;
const byte START_GAME           = 0x02;
const byte ADMIN_KILL           = 0x00;
const byte FULL_AMMO            = 0x06;
const byte EXPLODE_PLAYER       = 0x0B;
const byte STUN_PLAYER          = 0x16;
const byte DISARM_PLAYER        = 0x17;

String menus[7] = {"New game", "Start gm", "Kill", "Ammo", "Explode", "Stun", "Disarm"};
byte menuc[7] = {NEW_GAME, START_GAME, ADMIN_KILL, FULL_AMMO, EXPLODE_PLAYER, STUN_PLAYER, DISARM_PLAYER};

class transmitter {
public:
  transmitter(){
    pinMode(2, OUTPUT);
    IrSender.begin(2, true);
  }
  void sendCmd(byte b){
    unsigned long res = 0x83;
    res <<= 8;
    res |= b;
    res <<=8;
    res |= 0xE8;
    IrSender.sendSony(res, 24);
  }
};


void setup(){
  Serial.begin(9600);
  Serial.println("Started");
  tft.initR(INITR_144GREENTAB);
  tft.fillScreen(ST77XX_BLACK);
  tft.fillRect(15, 35, 8, 45, ST77XX_RED);
  tft.fillRect(30, 25, 8, 55, ST77XX_WHITE);
  tft.fillRect(45, 15, 8, 65, ST77XX_WHITE);
  tft.fillRect(60, 5, 8, 75, ST77XX_WHITE);
  tft.fillRect(75, 15, 8, 65, ST77XX_WHITE);
  tft.fillRect(90, 25, 8, 55, ST77XX_WHITE);
  tft.fillRect(105, 35, 8, 45, ST77XX_RED);
  tft.setCursor(17,95);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.print("PANTHEON");
  delay(1000);
  tft.fillScreen(ST77XX_BLACK);
  for(int i = 0; i < 7; i++){
      tft.setCursor(17, 5+17*i);
      tft.print(menus[i]);
  }
  tft.setTextColor(ST77XX_RED);
  Serial.println("Ended setup");
  pinMode(pinSW, INPUT_PULLUP);
}

int current = -1;
int new_m = 0;
transmitter trans;

void loop(){
  //x0 = 17
  //9 букв в одной строке
  //7 строк
  for(int i = 0; i < 1; i++){
    if(digitalRead(pinSW) == LOW){
      tft.setCursor(0, 5+17*current);
      tft.setTextColor(ST77XX_GREEN);
      tft.print("#");
      do{
        trans.sendCmd(menuc[current]);
        Serial.println(menus[current]);
        delay(150);
      }while(digitalRead(pinSW) == LOW);
      tft.setTextColor(ST77XX_RED);
      tft.fillRect(0, 5+17*current, 12, 17, ST77XX_BLACK);
      tft.setCursor(0, 5+17*current);
      tft.print(">");
    }
    if(analogRead(pinY) < 150){
      new_m++;
      if(new_m > 6){new_m = 0;}
      while (analogRead(pinY) < 150){
        delay(10);
      }
      break;
    }
    if(analogRead(pinY) > 850){
      new_m--;
      if(new_m < 0){new_m = 6;}
      while (analogRead(pinY) > 850){
        delay(10);
      }
      break;
    }
  }

  if(current != new_m){
    tft.setCursor(0, 5+17*current);
    tft.print(" ");
    tft.fillRect(0, 5+17*current, 11, 14, ST77XX_BLACK);
    tft.setCursor(0, 5+17*new_m);
    tft.print(">");
    current = new_m;
  }
}
