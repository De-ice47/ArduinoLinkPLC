#include "Core/ArduinoLinkPLC_Settings.h"

namespace ArduinoLinkPLC
{
    // Device Settings
    // const char *DeviceID = "ArdUnoR4";
    // IPAddress localIP(0, 0, 0, 0);    // Static IP for this PLC
    // IPAddress gateway(0,0,0,0);        // Master device IP
    // IPAddress subnet(255, 255, 255, 0);     // Probably good on default
    // const char *masterComputerSSID = "";    // Master device network name
    // const char *masterComputerSSIDPassword = ""; // Master device network password
    // const int masterComputerPort = 00000;                 // Master device port

    // Device Settings
    const char *DeviceID = "ArdUnoR4";
    IPAddress localIP(192, 168, 137, 45);                  // Static IP for this PLC
    IPAddress gateway(192, 168, 137, 1);                   // Master device IP
    IPAddress subnet(255, 255, 255, 0);                    // Probably good on default
    const char *masterComputerSSID = "TOPQUARK 4047";      // Master device network name
    const char *masterComputerSSIDPassword = "uP7r%?wDDJ"; // Master device network password
    const int masterComputerPort = 49800;                  // Master device port
}