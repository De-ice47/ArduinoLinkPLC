#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
  // Runtime
  WiFiUDP udp;
  bool connectionEstablished = false;
  int connectionAttempts = 0;
  //
  void setup_wifi()
  {
    digitalWrite(LED_BUILTIN, LOW);
    WiFi.config(localIP, gateway, subnet);
    WiFi.begin(masterComputerSSID, masterComputerSSIDPassword);
    Serial.print("Connecting to: ");
    Serial.print(gateway);
    Serial.print(", on network: ");
    Serial.print(masterComputerSSID);
    Serial.print(", through port: ");
    Serial.println(masterComputerPort);
    while (WiFi.status() == WL_IDLE_STATUS)
    {
      wifi_checkStatus();
      delay(250);
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print(".");
      delay(250);
      digitalWrite(LED_BUILTIN, LOW);
    }

    if (udp.begin(masterComputerPort) == 1)
    {
      Serial.println("Socket Openned: Connected!");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
      Serial.println("Socket Error");
      digitalWrite(LED_BUILTIN, LOW);
    }
    while (WiFi.status() != WL_CONNECTED)
      delay(250);
    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());
  }
}