#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    // Main Settings for Wifi
    IPAddress masterComputerIP(192, 168, 137, 1);        // Input the master device
    const char *masterComputerSSID = "TOPQUARK 4077";    // Master device network name
    const char *masterComputerSSIDPassword = "5E1259o2"; // Master device network password
    const int masterComputerPort = 49500;                 // Master device port

    // Desktop: 192,168,137,1 TOPQUARK 4077, 5E1259o2
}