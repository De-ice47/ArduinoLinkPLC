#include "Core/ArduinoLinkPLC_Settings.h"

namespace ArduinoLinkPLC
{
    // Device Settings
    const char *deviceSenderID = "ArdUnoR4";
    IPAddress masterComputerIP(0, 0, 0, 0);        // Input the master device
    const char *masterComputerSSID = "";    // Master device network name
    const char *masterComputerSSIDPassword = ""; // Master device network password
    const int masterComputerPort = 00000;                 // Master device port
}