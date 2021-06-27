#include <SoftwareSerial.h>

//   __________  __________  __________  __________  ___  ___    ___  __________  __________
//  /         / /   ______/ /___   ___/ /___   ___/ /  / /   \  /  / /  _______/ /         /
// /   ______/ /   /_____      /  /        /  /    /  / /     \/  / /  / _____  /   ______/
///______   / /   ______/     /  /        /  /    /  / /         / /  / /_   / /______   /
//         / /   /_____      /  /        /  /    /  / /  / \    / /  /___/  / /         /
//________/ /_________/     /__/        /__/    /__/ /__/   \__/ /_________/ /_________/


// WiFi
const char *ssid = "SSID";
const char *password = "PASSWD";

// Broker
const char *mqtt_broker = "IP";
const char *mqtt_username = "login";
const char *mqtt_password = "password";
const char *user = "test_app";

SoftwareSerial wifi(8,9); // RX, TX
String rep;

void setup(){
  delay(1000);
  Serial.begin(9600);
  wifi.begin(9600);
  if(wifi.availableForWrite() > 0){ // Передача данных о подключении
    wifi.println(ssid);
    wifi.println(password);
    wifi.println(mqtt_broker);
    wifi.println(mqtt_username);
    wifi.println(mqtt_password);
    wifi.println(user);
  }
  while(rep != "Done"){ // Ожидание подключения
    if(wifi.available()){
      rep = wifi.readString();
    }
    delay(100);
    if(rep[0] == 'x'){
      Serial.println("Error in connection:");
      Serial.println(rep);
    }
  }
  Serial.println(rep);
}

String relay(String data = ""){
  String inner;
  if(!data and wifi.available()){
    inner = wifi.readString();
  } else if (data){
    wifi.println(data);
    while(inner != "Done"){
      inner = wifi.readString();
    }
  } else {
    inner = "";
  }
  return inner;
}

void loop(){
  rep = relay();
  if(rep){  // Принятие данных от модуля
    Serial.print("Got:");
    Serial.println(rep);
  }
  if(rep == "ask"){
    unsigned long int timer = millis()/1000;
    rep = relay((String)timer); // Отправка данных на модуль
    Serial.println(rep);
  }
  delay(2000);
}

void yield(){ // Доп чтение
  rep = relay();
  if(rep){
    Serial.print("Got:");
    Serial.println(rep);
  }
}
