#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define DATA 2
#define LOCK 0

bool state = true; // true - locked, false - unlocked

const char *ssid = "LASERWAR_NET";
const char *password = NULL;

const char *mqtt_broker = "10.0.0.21";
const char *topic = "/arena/doors/black_door";
const char *mqtt_username = "login";
const char *mqtt_password = "password";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // put your setup code here, to run once:
  pinMode(DATA, INPUT_PULLUP);
  pinMode(LOCK, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    offline();
  }
  client.setServer(mqtt_broker, 1883);
  client.setCallback(callback);
  unsigned long timer = millis();
  while (!client.connected()){
    String client_id = "Door_black";
    if(client.connect(client_id.c_str(), mqtt_username, mqtt_password)){
      delay(1);
    } else {
      delay(1);
    }
    if(millis() - timer >= 10000){
      offline()
    }
  }
  client.publish("/quest/flow", "{ \"name\": \"Door_black\", \"state\": \"ONLINE\" }");
  client.subscribe(topic);
}

void offline(){
  if(digitalRead(DATA) == LOW){
    state = false;
    if(client.connected()){
      client.publish("/quest/flow", "{ \"name\": \"Door_black\", \"state\": \"Opened\" }");
    }
    digitalWrite(LOCK, LOW);
    unsigned long timer = millis();
    while(millis()-timer < 15000){
      delay(10);
    }
    state = true;
    if(client.connected()){
      client.publish("/quest/flow", "{ \"name\": \"Door_black\", \"state\": \"Closed\" }");
    }
  }
  if(state){
    digitalWrite(LOCK, HIGH);
  } else {
    digitalWrite(LOCK, LOW);
  }
}

void callback(char *topic, byte *payload, unsigned int length){
  char str[length+1];
  int i = 0;
  for(i = 0; i < length; i++){
    str[i] = (char)payload[i];
  }
  str[i] = 0;
  StaticJsonDocument <128> doc;
  deserializeJson(doc, str);
  if(doc.containsKey("chst")){
    state = !state;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!client.connected()){
    String client_id = "Door_black";
    if(client.connect(client_id.c_str(), mqtt_username, mqtt_password)){
      delay(1);
    } else {
      offline();
    }
  }
  client.loop();
  offline();
}
