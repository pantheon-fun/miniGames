int pinsOut[4] = {22, 23, 24, 25};
int pinsIn[4] = {26, 27, 28, 29};
int fLed[4] = {42, 38, 34, 30};
int conn[4] = { -1, -1, -1, -1};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    pinMode(pinsOut[i], OUTPUT);
    pinMode(pinsIn[i], INPUT);
    pinMode(fLed[i], OUTPUT);
    pinMode(fLed[i] + 1, OUTPUT);
    pinMode(fLed[i] + 2, OUTPUT);
    pinMode(fLed[i] + 3, OUTPUT);
  }
}

void loop() {
  for(int o = 0; o < 4; o++){
    digitalWrite(pinsOut[o], HIGH);
    for(int i = 0; i < 4; i++){
      conn[o] = -1;
      if(digitalRead(pinsIn[i]) == HIGH){
        conn[o] = i;
        break;
      }
    }
    digitalWrite(pinsOut[o], LOW);
    if (conn[o] != -1){
      digitalWrite(fLed[o]+3-conn[o], HIGH);
    } else {
      for (int i = 0; i < 4; i++){
        digitalWrite(fLed[o]+i, LOW);
      }
    }
  }
}
