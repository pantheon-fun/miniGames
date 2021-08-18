// TODO create functions for tm1638


//MODES:
/**
 *
 * 0. Push button which diode is lit on                         ! work
 *
 * 1. Push buttons to turn all leds on                          ! work
 * 
 * 2. Simon says                                                ! work ??
 * 
 * 3. Push buttons to get sum of 21                             ! work
 * 
 * 4. button change digit. Right digit - led on. all leds - win ! work
 * 
 * 5. Simply wait                                               ! work
 *
 * 6. Balance the decode path                                   ! Not done
 * 
*/

#include <TM1638.h>
#include "pitches.h"
#define BUZZER 13

TM1638 module(8,9,7);

int mode;

void setup(){
    Serial.begin(9600);
    pinMode(11, OUTPUT);
    digitalWrite(11, HIGH);
    delay(50);
    module.setDisplayToString("PANTHEON");
    delay(50);
    randomSeed(analogRead(A0));
    mode = random(7);
    coin();
}

void coin(){
  tone(BUZZER,NOTE_B5,100);
  delay(100);
  tone(BUZZER,NOTE_E6,850);
  delay(1300);
  noTone(13);
}

void oneup(){
  tone(BUZZER,NOTE_E6,125);
  delay(130);
  tone(BUZZER,NOTE_G6,125);
  delay(130);
  tone(BUZZER,NOTE_E7,125);
  delay(130);
  tone(BUZZER,NOTE_C7,125);
  delay(130);
  tone(BUZZER,NOTE_D7,125);
  delay(130);
  tone(BUZZER,NOTE_G7,125);
  delay(125);
  noTone(BUZZER);
}

void fb(){
  tone(BUZZER,NOTE_G4,35);
  delay(35);
  tone(BUZZER,NOTE_G5,35);
  delay(35);
  tone(BUZZER,NOTE_G6,35);
  delay(35);
  noTone(BUZZER);
}

void led_on(int led){
    module.setLED(1, led);
}
void led_off(int led){
    module.setLED(0, led);
}
void leds_on(){
    module.setLEDs(0xFF);
}
void leds_off(){
    module.setLEDs(0);
}
int get_button(){
    byte btns = module.getButtons();
    while(module.getButtons() == btns){
      delay(5);
    }
    if(btns == 0){
      return -1;
    }
    for(int i = 0; i < 8; i++){
      if(btns & 0b00000001 == 1){
        delay(50);
        return i;
      }
      btns = btns >> 1;
    }
}
void failure(){
  unsigned long timer = millis();
  lcd_print("  FAIL  ");
    while(1){
      if(millis()-timer > 4000){
        return;
      }
      fb();
      leds_on();
      delay(50);
      leds_off();
      delay(50);
    }
}
void win(){
  int l = 0;
  unsigned long timer = millis();
  lcd_print("OPENING ");
  oneup();
  while(1){
    if(millis() - timer > 5000){
      mode = (mode + 1) % 6;
      Serial.println(mode);
      return;
    }
    led_on(l);
    led_on(7-l);
    delay(100);
    led_off(l);
    led_off(7-l);
    l = (l+1) % 8;
  }
}
void lcd_print(String msg){
    module.setDisplayToString(msg);
}

void mode0(){
  lcd_print(" REPEAT ");
  leds_off();
  int retries = random(10,15);
  for(int i = 0; i < retries; i++){
    delay(250);
    int led = random(8);
    led_on(led);
    int btn;
    while(btn != led){
      btn = get_button();
      if(btn > -1 && btn != led){
        failure();
        return;
      }
    }
    led_off(led);
  }
  win();
}
void mode1(){
  lcd_print("ALL   ON");
  int sum = 0;
  Serial.println("Started mode 1");
  leds_off();
  int leds[8];
  for(int i = 0; i < 8; i++){
    leds[i] = random(2);
    if(leds[i] == 1){
      led_on(i);
    } else {
      led_off(i);
    }
  }
  unsigned long timer = millis();
  while(sum != 8){
    if(millis()-timer > 12000){
      failure();
      return;
    }
    sum = 0;
    for(int i = 0; i < 8; i++){
      if(leds[i] == 1){
        sum++;
      }
    }
    if(sum == 8){
      win();
      return;
    }
    int btn = get_button();
    if(btn == -1){
      continue;
    }
    if(leds[btn] == 1){
      leds[btn] = 0;
      led_off(btn);
    } else {
      leds[btn] = 1;
      led_on(btn);
    }
  }
  win();
}
void mode2(){
  Serial.println("Started simon");
  lcd_print(" REPEAT ");
  leds_off();
  delay(1000);
  randomSeed(analogRead(A0));
  for(int i = 1; i < 6; i++){
    int leds[i];
    for(int j = 0; j < i; j++){
      leds[j] = random(8);
      led_on(leds[j]);
      delay(500);
      leds_off();
      delay(150);
    }
    for(int j = 0; j < i; j++){
      int btn = -1;
      while(1){
        btn = get_button();
        Serial.println(leds[j]);
        if(btn == leds[j]){
          break;
        } else if(btn == -1){
          continue;
        } else {
          failure();
          return;
        }
      }
    }
  }
  win();
}
void mode3(){
  module.clearDisplay();
  lcd_print("     |21");
  int sum = 0;
  leds_off();
  int leds2[8] = {0,0,0,0,0,0,0,0};
  int leds_n[8] = {1,2,3,4,5,6,7,8};
  for(int i = 0; i < 8; i++){
    int j = random(0, 8);
    int _temp = leds_n[i];
    leds_n[i] = leds_n[j];
    leds_n[j] = _temp;
  }
  unsigned long timer3 = millis();
  while(sum != 21){
    if(millis()-timer3 > 25000){
      failure();
      return;
    }
    int btn = get_button();
    if(btn < 0){
      continue;
    }
    if(leds2[btn] == 0){
      leds2[btn] = 1;
      led_on(btn);
    } else {
      leds2[btn] = 0;
      led_off(btn);
   }
   sum = 0;
   for(int i = 0; i < 8; i++){
      if(leds2[i] == 1){
        sum += leds_n[i];
        module.clearDisplayDigit(0, 0);
        module.clearDisplayDigit(1, 0);
        lcd_print(String(sum));
      }
    }
  }
  win();
}
void mode4(){
  lcd_print("00000000");
  int sum = 0;
  leds_off();
  int digits[8];
  for(int i = 0; i < 8; i++){
    digits[i] = random(10);
  }
  int lcd_digits[8] = {0,0,0,0,0,0,0,0};
  unsigned long timer2 = millis();
  while(sum != 8){
    sum = 0;
    if(millis() - timer2 > 40000){
      failure();
      return;
    }
    int btn = get_button();
    if(btn == -1){
      continue;
    }
    lcd_digits[btn] = (lcd_digits[btn] + 1) % 10;
    String msg;
    for(int i = 0; i< 8; i++){
      msg.concat(lcd_digits[i]);
      if(lcd_digits[i] == digits[i]){
        sum += 1;
        led_on(i);
      } else { led_off(i);}
    }
    Serial.println(msg);
    lcd_print(msg);
  }
  delay(500);
  win();
}
void mode5(){
  module.clearDisplay();
  leds_off();
  for(int i = 0; i < 8; i++){
    module.setDisplayDigit(random(10), i, false);
  }
  leds_off();
  unsigned long timer = millis();
  while(millis() - timer < 10000){
    int i = random(8);
    module.setDisplayDigit(random(10), i, false);
    if(random(2)){
      led_on(random(8));
    } else {
      led_off(random(8));
    }
    delay(20);
  }
  delay(500);
  win();
}

void loop(){
  Serial.print("Loop with mode: ");
  Serial.println(mode);
    if(mode == 0){
      mode0();
    } else if (mode == 1){
      mode1();
    } else if (mode == 2){
      Serial.println("starting simon!");
      mode2();
    } else if (mode == 3){
      Serial.println("starting 3 mode");
      mode3();
    } else if (mode == 4){
      mode4();
    } else if (mode == 5){
      mode5();
    }
}
