// 6 - button
// 7-12 - LEDs

void setup(){
  for(int i = 7, i <= 12; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(6, INPUT);
}

void loop(){
  for(int i = 7, i <= 12; i++){
    if(digitalRead(6) != HIGH){
      break;
    }
    digitalWrite(i, HIGH);
    delay(500);
    if (i == 12){
      while(true){
        for(int j = 7; j <= 12; j++){
          digitalWrite(j, !digitalRead(j));
        }
        delay(150);
      }
    }
  }
}
