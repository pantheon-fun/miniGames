//3 - LED
//4,5,6,7,8 - 1 gr.
//9,10,11,12,13 - 2 gr.



//LED defines
#define LED_PIN 3
#define LED_NUM 10
#include "Adafruit_NeoPixel.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);
#define RED strip.Color(255,0,0)
#define GREEN strip.Color(0,255,0)
#define BLUE strip.Color(0,0,255)
#define FUKSIA strip.Color(255,0,255)
#define WHITE strip.Color(255,255,255)



int groupO[5] = {4,5,6,7,8};
int groupI[5] = {9,10,11,12,13};
uint32_t colorsO[5] = {RED, GREEN, BLUE, FUKSIA, WHITE};
uint32_t colorsI[5] = {RED, GREEN, BLUE, FUKSIA, WHITE};


void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  for(int i = 0; i < 5; i++){
    pinMode(groupO, OUTPUT);
    pinMode(groupI, INPUT);
  }
  randomSeed(analogRead(0));
  for(int i = 0; i < 5; i++){
    int j = random(0,5);
    Serial.println(j);
    uint32_t tmp = colorsO[j];
    colorsO[j] = colorsO[i];
    colorsO[i] = tmp;
    j = random(0,5);
    Serial.println(j);
    tmp = colorsI[j];
    colorsI[j] = colorsI[i];
    colorsI[i] = tmp;
  }
  strip.begin();
  strip.setBrightness(255);
  strip.clear();
  for(int i = 0; i < 5; i++){
    strip.setPixelColor(i, colorsO[i]);
    strip.setPixelColor(i+5, colorsI[i]);
  }
  strip.show();
  //WORKING
}

void loop(){
  for(int i = 0; i < 5; i++){
    digitalWrite(groupO[i], LOW);
  }
  int done = 0;
  int sum = 0;
  for(int i = 0; i < 5; i++){
    digitalWrite(groupO[i], HIGH);
    for(int j = 0; j < 5; j++){
      if(digitalRead(groupI[j]) == HIGH){
        sum++;
        if(colorsO[i] == colorsI[j]){
          done++;
        }
      }
    }
  }
  done = 5;
  sum = 5;
  if(done == sum && sum == 5){
    while(true){
      int i = random(0,10);
      uint32_t old = strip.getPixelColor(i);
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(150);
      strip.setPixelColor(i, old);
      strip.show();
    }
  }
}
