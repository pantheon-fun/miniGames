#include<SoftwareSerial.h>

SoftwareSerial WIFI_SERIAL(8, 9);
#define TIMEOUT 1500 
String IP = "\"10.0.0.13\"";
String PORT = "10596";

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
      Serial.print("Goto afterRestore");
      goto afterRestore;
    } else if (res == "ERROR" or res == "ERROR\r" or res == "ERROR\r\n"){
      Serial.print("Goto restore");
      goto restore;
    } else {
      Serial.print("Goto restoreRead");
      goto restoreRead;
    }
  }
  afterRestore:
  //delay(5000);
  SendCommand("AT+CWMODE=1", "OK");
  SendCommand("AT+CWJAP=\"Pantheon_WorkShop\",\"22029322Yan\"", "OK");
  delay(5000);
  SendCommand("AT+CIPMUX=0", "OK");
  tcp:
  SendCommand("AT+CIPSTART=\"TCP\"," + IP + "," + PORT, "OK");
  tcpRead:
  while(WIFI_SERIAL.available()){
    String res = WIFI_SERIAL.readString();
    if(res == "OK" or res == "OK\r" or res == "OK\r\n"){
      Serial.println("Connected to TCP");
      goto afterTcp;
    } else if (res == "ERROR" or res == "ERROR\r" or res == "ERROR\r\n"){
      goto tcp;
    } else {
      goto tcpRead;
    }
  }
  afterTcp:
  SendCommand("AT+CIPMODE?", "");
  //SendCommand("AT+CIPSENDEX=5", ">");
  //delay(1500);
  //Serial.println("Game1\0\r");
  //WIFI_SERIAL.write("Game1\0\r\n");
  TcpSend("Game number one");
  //delay(1500);
  TcpSend("Workin? Workin!");
  delay(15000);
  TcpSend("EOP");
  SendCommand("AT+CIPCLOSE","OK");
}

void loop() {
}

void TcpSend(String data){
  SendCommand("AT+CIPSENDEX=1024", ">");
  WIFI_SERIAL.println(String(data + "\\0\n"));
  delay(500);
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
