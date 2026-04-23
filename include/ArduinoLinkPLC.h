#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

extern IPAddress masterComputerIP;
extern const char* masterComputerSSID;
extern const char* masterComputerSSIDPassword;
extern const int masterComputerPort;
extern WiFiUDP udp;

void setup_wifi();

void receive_packets();
void parsePacketMessage(String msg);

void send_packet(String msg);

void wifi_checkStatus();