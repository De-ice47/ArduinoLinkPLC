#include "ArduinoLinkPLC.h"
// Main Settings for Wifi
// 192,168,137,1
// 137, 104, 157, 147
IPAddress masterComputerIP(192,168,137,1);
const char* masterComputerSSID = "TOPQUARK 4077";
const char* masterComputerSSIDPassword = "5E1259o2";
const int masterComputerPort = 5005;
// Runtime
WiFiUDP udp;
bool connectionEstablished = false;
int connectionAttempts = 0;
//
void setup_wifi() {
  digitalWrite(LED_BUILTIN, LOW);
  WiFi.begin(masterComputerSSID, masterComputerSSIDPassword);
  Serial.begin(9600);
  Serial.print("Connecting to: ");
  Serial.print(masterComputerIP);
  Serial.print(", on network: ");
  Serial.print(masterComputerSSID);
  Serial.print(", through port: ");
  Serial.println(masterComputerPort);
  while (WiFi.status() == WL_IDLE_STATUS) {
    wifi_checkStatus();
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print(".");
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  if(udp.begin(masterComputerPort) == 1) {
    Serial.println("Socket Openned: Connected!");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    Serial.println("Socket Error");
    digitalWrite(LED_BUILTIN, LOW);
  }
}