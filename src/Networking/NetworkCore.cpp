#include "internal/VeloxityLink_Internal.h"
namespace VeloxityLink
{
  //
  WiFiUDP udp;
  bool networkActive = false;
  // local
  bool connectionEstablished = false;
  int connectionAttempts = 0;
  //
  void start_network()
  {
    Serial.begin(9600);
    statusLight(false);
    WiFi.config(localIP, gateway, IPAddress(255, 255, 255, 0));
    WiFi.begin(masterComputerSSID, masterComputerSSIDPassword);
    if (showSerialOutput)
    {
      Serial.print("Connecting to gateway: ");
      Serial.print(gateway);
      Serial.print(", on network: ");
      Serial.print(masterComputerSSID);
      Serial.print(", through port: ");
      Serial.println(masterComputerPort);
    }
    while (WiFi.status() == WL_IDLE_STATUS)
    {
      wifi_checkStatus();
      delay(250);
      statusLight(true);
      if (showSerialOutput)
        Serial.print(".");
      delay(250);
      statusLight(false);
    }

    if (udp.begin(masterComputerPort) == 1)
    {
      if (showSerialOutput)
        Serial.println("Socket Openned: Connected!");
      statusLight(true);
    }
    else
    {
      if (showSerialOutput)
        Serial.println("Socket Error");
      statusLight(false);
    }
    while (WiFi.status() != WL_CONNECTED)
      delay(250);
    if (showSerialOutput)
    {
      Serial.print("Local IP: ");
      Serial.println(WiFi.localIP());
    }
  }
  void stop_network()
  {
    udp.stop();
    WiFi.disconnect();
    if (showSerialOutput)
      Serial.println("Network Stopped");
    statusLight(false);
  }
}