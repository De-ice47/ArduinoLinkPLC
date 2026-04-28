#pragma once
#include "Core/ArduinoLinkPLC_SOURCE.h"
namespace ArduinoLinkPLC
{
    // Device Settings
    extern char *DeviceID;
    extern IPAddress localIP;
    extern IPAddress gateway;                      // Master device IP
    extern char *masterComputerSSID;         // Master device network name
    extern char *masterComputerSSIDPassword; // Master device network password
    extern int masterComputerPort;           // Master device port
    extern bool showSerialOutput;

    void displaySerialOutput(bool);
    void config(char* deviceID, IPAddress local_IP, IPAddress gatewayIP, char* SSID, char* SSID_Password, int port);
}