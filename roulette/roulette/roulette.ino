/* 
 * Project name         Roulette
 * Author:              Lanity Roshoose
 * Date of mod.         24.04.2021
 * Version              beta 1.1
 */



int ledPins[7] = {8, 2, 7, 3, 6, 4, 5};
int ledPinsSorted[7] = {8, 7, 6, 5, 4, 3, 2};
int difficulty = -1;
int loops = 0;
int score = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i<7; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(9, INPUT_PULLUP);
  unsigned long timer = millis();
  while(difficulty == -1){
    for(int i = 1; i < 4; i++){
      if(difficulty != -1){
        break;
      }
      for(int k = 0; k<7; k++){
        digitalWrite(ledPins[k], LOW);
      }
      if(i == 1){
        for(int j = 0; j < 4; j++){
          digitalWrite(ledPins[j], HIGH);
        }
      } else if(i == 2){
        digitalWrite(ledPins[4], HIGH);
        digitalWrite(ledPins[5], HIGH);
      } else if(i == 3){
        digitalWrite(ledPins[6], HIGH);
      }
      while(millis()-timer <= 1500){
        if(digitalRead(9) == LOW){
          difficulty = i;
        }
      }
      timer = millis();
    }
  }
  Serial.print("Difficulty is (1-3): ");
  Serial.println(difficulty);
  for(int k = 0; k<7; k++){
    digitalWrite(ledPins[k], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //vistrel

  //wifi

  
  bool _running = true;
  int _delay;
  switch(difficulty){
    case 1:
      _delay = 800;
      break;
    case 2:
      _delay = 550;
      break;
    case 3:
      _delay = 200;
      break;
  }
  int pos = 0;
  bool _back = false;
  unsigned long timerPlay = millis();
  while(_running){
    digitalWrite(ledPinsSorted[pos], HIGH);
    unsigned long timer = millis();
    while(millis()-timer <= _delay){
      if(digitalRead(9) == LOW){
        _running = false;
        digitalWrite(ledPinsSorted[pos], LOW);
      }
    }
    digitalWrite(ledPinsSorted[pos], LOW);
    if(_back){
      pos--;
    } else {
      pos++;
    } if (pos == 6 || pos == 0){
      _back = !_back;
    }
    if(millis()-timerPlay > 10000){
      pos = 0;
      _running = false;
    }
  }
  Serial.print("Stopped at :");
  Serial.println(pos);
  loops++;
  if(pos > 2 && pos < 6){
    score++;
  } if (pos == 4){
    score++;
  }
  if(loops == 3){
    if(score >= 4){
      //vistrel

      //if vistrel

      //wifi
      while(true){
        for(int j = 0; j < 7; j++){
          digitalWrite(ledPinsSorted[j], !digitalRead(ledPinsSorted[j]));
          delay(150);
        }
      }
    } else {
      loops = 0;
      score = 0;
      loop();
    }
  }
}
