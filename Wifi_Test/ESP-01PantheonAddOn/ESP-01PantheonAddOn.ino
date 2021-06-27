#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//   __________  __________  __________  __________  ___  ___    ___  __________  __________
//  /         / /   ______/ /___   ___/ /___   ___/ /  / /   \  /  / /  _______/ /         /
// /   ______/ /   /_____      /  /        /  /    /  / /     \/  / /  / _____  /   ______/
///______   / /   ______/     /  /        /  /    /  / /         / /  / /_   / /______   /
//         / /   /_____      /  /        /  /    /  / /  / \    / /  /___/  / /         /
//________/ /_________/     /__/        /__/    /__/ /__/   \__/ /_________/ /_________/


// WiFi
char *ssid;
char *password;

// Broker
char *mqtt_broker;
char *topic;
char *mqtt_username;
char *mqtt_password;
char *user;
int mqtt_port = 1883;


WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  //Ввод данных о подключении
  String buf;
  buf = Serial.readString();
  buf.toCharArray(ssid, buf.length());
  buf = Serial.readString();
  buf.toCharArray(password, buf.length());
  buf = Serial.readString();
  buf.toCharArray(mqtt_broker, buf.length());
  buf = Serial.readString();
  buf.toCharArray(mqtt_username, buf.length());
  buf = Serial.readString();
  buf.toCharArray(mqtt_password, buf.length());
  buf = Serial.readString();
  buf.toCharArray(user, buf.length());
//  password = (char*)Serial.readString();
//  mqtt_broker = (char*)Serial.readString();
//  mqtt_username = (char*)Serial.readString();
//  mqtt_password = (char*)Serial.readString();
//  user = (char*)Serial.readString();
  topic = "/mini-games/";
  strcat(topic, user);
  //Подключение
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()){
    String client_id = user;
    //Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)){
    } else {
      Serial.print("xfailed with state ");
      Serial.println(client.state());
      delay(2000);
    }
  }
  client.publish(topic, "executor here, bitches");
  client.subscribe(topic);
  Serial.println("Done");
  //Подключено
}

void callback(char *topic, byte *payload, unsigned int leng){ // Отправка данных от брокера -> устройству
  char pay[leng];
  for(int i = 0; i < leng; i++){
    pay[i] = (char) payload[i];
  }
  //int test_pay = atoi(&pay[0]);
  Serial.println(pay);
}

void loop() {
  // Рабочий цикл
  client.loop();
  if(Serial.available()){ // Отправка данных от устройства -> брокеру
    char *rep;
    String buf;
    buf = Serial.readString();
    buf.toCharArray(rep, buf.length());
    client.publish(topic, rep);
  }
}
