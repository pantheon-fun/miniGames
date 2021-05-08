#include<SoftwareSerial.h>

SoftwareSerial WIFI_SERIAL(8, 9);
#define TIMEOUT 5000 
#define IP "10.0.0.13"
#define PORT 10596

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WIFI_SERIAL.begin(115200);

  //config
  if(!SendCommand("AT", "OK")){
    Serial.println("Wifi not working properly");
  }
  SendCommand("AT+RESTORE", "OK");
  //delay(5000);
  SendCommand("AT+CWMODE=1", "OK");
  SendCommand("AT+CWJAP=\"Pantheon_WorkShop\",\"22029322Yan\"", "OK");
  delay(15000);
  SendCommand("AT+CIPMUX=0", "OK");
  //char result[250];
//  delay(10000);
//  strcat(result, "AT+CIPSTART=TCP,");
//  strcat(result, IP);
//  strcat(result, ",");
  //strcat(result,"10596");
  SendCommand("AT+CIPSTART=\"TCP\",\"10.0.0.13\",10596", "OK");
  //delay(1000);
  //SendCommand("AT+CIPSTART=\"TCP\",\"10.0.0.13\",10596", "OK");
  //delay(1000);
  //SendCommand("AT+CIPSTART=\"TCP\",\"10.0.0.13\",10596", "OK");
  //delay(1000);
  //SendCommand("AT+CIPSTART=\"TCP\",\"10.0.0.13\",10596", "OK");
  SendCommand("AT+CIPSENDEX=1024", ">");
  delay(1000);
  WIFI_SERIAL.write("wifi connected\0");
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
