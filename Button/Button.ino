/* 
 * Project name         Button
 * Author:              Lanity Roshoose
 * Date of mod.         12.04.2021
 * Version              beta 1.2
 */

const int AMOUNT = 8;
int LEDs[AMOUNT] = {4, 5, 6, 7, 8, 9, 10, 11};
int btn = 2;
const int DELAY = 500;


void setup(){
  for(int i = 0; i < AMOUNT; i++){
    pinMode(LEDs[i], OUTPUT);
  }
  pinMode(btn, INPUT_PULLUP);
}

void loop(){
  for(int i = 0; i < AMOUNT; i++){
    if(digitalRead(btn) == HIGH){
      break;
    }
    digitalWrite(LEDs[i], HIGH);
    delay(DELAY);
    if(i+1 >= AMOUNT){
      while("Pantheon is the best"){
        for(int j = 0; j < AMOUNT; j++){
          digitalWrite(LEDs[j], !digitalRead(LEDs[j]));
        }
        delay(DELAY);
      }
    }
  }
  for(int i = 0; i < AMOUNT; i++){
    digitalWrite(LEDs[i], LOW);
  }
}
