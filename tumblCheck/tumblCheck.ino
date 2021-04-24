/* 
 * Project name         Button
 * Author:              Lanity Roshoose
 * Date of mod.         22.04.2021
 * Version              beta 1.3
 */

int pinsT[8] = {31, 30, 33, 32, 35, 34, 37, 36};
int pinsL[8] = {23, 22, 25, 24, 27, 26, 29, 28};
int data[8];
char color[8] = {'b', 'r', 'g', 'y', 'b', 'r', 'y', 'g'};


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
  for(int i = 0; i < 8; i++){
    pinMode(pinsT[i], INPUT_PULLUP);
    pinMode(pinsL[i], OUTPUT);
  }
  delay(10);
  initSequence();
}

void first_mode(){
  bool _running = true;
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
  Serial.println("Started_SM");
  bool _running = true;
  randomSeed(analogRead(A5));
  char onColor = color[random(0, 8)];
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
        }
      }
      else{
        digitalWrite(pinsL[i], LOW);
      }
    }
    delay(100);
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
    blink(50);
  }
}
