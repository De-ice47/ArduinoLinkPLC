#include "Core/ArduinoLinkPLC_Settings.h"

namespace ArduinoLinkPLC
{
    // Device Settings
    const char *deviceSenderID = "ArdUnoR4";
    IPAddress masterComputerIP(192, 168, 137, 1);        // Input the master device
    const char *masterComputerSSID = "ISR30OK 3700";    // Master device network name
    const char *masterComputerSSIDPassword = "47x8%B28"; // Master device network password
    const int masterComputerPort = 49500;                 // Master device port
}