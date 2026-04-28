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
    char *DeviceID = "ArdUnoR4";
    IPAddress localIP;                  // Static IP for this PLC
    IPAddress gateway(0,0,0,0);                   // Master device IP
    char *masterComputerSSID;      // Master device network name
    char *masterComputerSSIDPassword; // Master device network password
    int masterComputerPort = 0;                  // Master device port
    bool showSerialOutput = false;

    void displaySerialOutput(bool running){
        showSerialOutput = running;
    }
    void config(char* deviceID, IPAddress local_IP, IPAddress gatewayIP, char* SSID, char* SSID_Password, int port = 49800){
        DeviceID = deviceID;
        localIP = local_IP;
        gateway = gatewayIP;
        masterComputerSSID = SSID;
        masterComputerSSIDPassword = SSID_Password;
        masterComputerPort = port;
    }
}