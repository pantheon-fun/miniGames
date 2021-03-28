const int SIZE = 8;
int pins[SIZE] = {2, 3, 4, 5, 6, 7, 8, 9};
int data[SIZE];
byte leds = 0;
int latchPin = 10;
int clockPin = 11;
int dataPin = 12;


void setup() {
  // put your setup code here, to run once:
  delay(10);
  randomSeed(millis());
  for( int i = 0; i < SIZE; i++){
    int n = random(0, 2);
    if(n == 1){data[i] = HIGH;}
    else if(n==0){data[i] = LOW;}
    pinMode(2+i, INPUT);
  }
  for(int i = 10; i < 13; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int sum = 0;
  leds = 0;
  for( int i = 0; i < SIZE; i++){
    if(digitalRead(pins[i]) == data[i]){
      leds += (int)floor(pow(2.001, i));
      Serial.println(String(i) + " gets " + String((int)floor(pow(2.001, i))));
    }
  }
  Serial.println(leds);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(500);
}
