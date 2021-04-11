void setup(){
  for(int i = 4, i <= 11; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(6, INPUT);
}

void loop(){
  for(int i = 4, i <= 11; i++){
    if(digitalRead(6) != HIGH){
      break;
    }
    digitalWrite(i, HIGH);
    delay(500);
    if (i == 11){
      while(true){
        for(int j = 4; j <= 11; j++){
          digitalWrite(j, !digitalRead(j));
        }
        delay(250);
      }
    }
  }
}