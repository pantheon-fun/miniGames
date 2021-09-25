#include <IRremote.h>

#define MODE 0
#define DELAY 5000 //5 seconds. Only for MODE 2
/*
 * Modes:
 *  0: shooting while btn is pressed
 *  1: btn change state (not shooting - press -> shooting - press -> not shooting)
 *  2: starts shooting for DELAY on button press
 */

#define FIRST   0xA0
#define SECOND  50
#define LED_PIN 13
#define BTN     8

class transmitter {
public:
  transmitter(int pin){
      pinMode(pin, OUTPUT);
      IrSender.begin(pin, true);
  }
  void run(){
    Serial.println("run");
    unsigned long res = FIRST;
    res <<= 8;
    res |= SECOND;
    res <<= 8;
    res |= 0xE8;
    IrSender.sendSony(res, 24);
  }
};

transmitter trans = transmitter(LED_PIN);

void setup() {
  // put your setup code here, to run once:
  pinMode(BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

bool state = false;

void loop() {
  // put your main code here, to run repeatedly:
  if(MODE == 0){
    if(digitalRead(BTN) == LOW){
      trans.run();
      delay(200);
    } else {
      delay(100);
    }
  } else if (MODE == 1){
    if(digitalRead(BTN) == LOW){
      state = !state;
      Serial.println(state);
      while(digitalRead(BTN) == LOW){
        delay(50);
      }
    }
    if(state){
      trans.run();
      delay(100);
    }
  } else if (MODE == 2){
    if(digitalRead(BTN) == LOW){
      unsigned long timer1 = millis();
      while(millis() - timer1 <= DELAY){
        trans.run();
        delay(100);
      }
    }
  }
}
