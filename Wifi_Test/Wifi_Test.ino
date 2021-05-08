#include<SoftwareSerial.h>

SoftwareSerial WIFI_SERIAL(8, 9);
#define TIMEOUT 5000 
String IP = "10.0.0.13"
String PORT = "10596"

void setup() {
  String reply;
  // put your setup code here, to run once:
  Serial.begin(115200);
  WIFI_SERIAL.begin(115200);
  WIFI_SERIAL.setTimeout(5000);
  //config
  restore:
  SendCommand("AT+RESTORE", "OK");
  restoreRead:
  while(WIFI_SERIAL.available()){
    Serial.println("Reading data");
    String res = WIFI_SERIAL.readString();
    if(res == "OK" or res == "OK\r" or res == "OK\r\n" or res == "OK\n"){
      goto afterRestore;
    } else if (res == "ERROR" or res == "ERROR\r" or res == "ERROR\r\n"){
      goto restore;
    } else {
      goto restoreRead;
    }
  }
  afterRestore:
  //delay(5000);
  SendCommand("AT+CWMODE=1", "OK");
  conn:
  SendCommand("AT+CWJAP=\"Pantheon_WorkShop\",\"22029322Yan\"", "OK");
  connRead:
  while(WIFI_SERIAL.available()){
    Serial.println("Reading data");
    String res = WIFI_SERIAL.readString();
    if(res == "GOT IP" or res == "GOT IP\r" or res == "GOT IP\r\n" or res == "GOT IP\n"){
      goto afterconn;
    } else if (res == "ERROR" or res == "ERROR\r" or res == "ERROR\r\n"){
      goto conn;
    } else {
      goto connRead;
    }
  }
  afterconn:
  SendCommand("AT+CIPMUX=0", "OK");
  SendCommand("AT+CIPSTART=\"TCP\"," + IP + "," + PORT, "OK");
  SendCommand("AT+CIPSENDEX=1024", ">");
  WIFI_SERIAL.println("wifi connected\0");
  SendCommand("AT+CIPCLOSE","OK");
}

void loop() {
}

boolean echoFind(String keyword){
 byte current_char = 0;
 byte keyword_length = keyword.length();
 long deadline = millis() + TIMEOUT;
 while(millis() < deadline){
  if (WIFI_SERIAL.available()){
    char ch = WIFI_SERIAL.read();
    Serial.write(ch);
    if (ch == keyword[current_char])
      if (++current_char == keyword_length){
       Serial.println();
       return true;
    }
   }
  }
 return false; // Timed out
}

boolean SendCommand(String cmd, String ack){
  WIFI_SERIAL.println(cmd); // Send "AT+" command to module
  if (!echoFind(ack)) // timed out waiting for ack string
    return true; // ack blank or ack found
  else{
    return false;
  }
}
