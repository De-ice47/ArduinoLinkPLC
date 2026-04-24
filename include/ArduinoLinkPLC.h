#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <functional>
#include <vector>
#include "ArduinoLinkPLC_Classes.h"
namespace ArduinoLinkPLC
{
    // Global vars
    extern IPAddress masterComputerIP;
    extern const char *masterComputerSSID;
    extern const char *masterComputerSSIDPassword;
    extern const int masterComputerPort;

    // Master loop and setup functions
    void setup_library();
    void loop_library();
    
    // Sending
    void send_packet(String msg);
    // Receiving
    extern ArduinoLinkPLC::EventString onPacketReceived;
}
