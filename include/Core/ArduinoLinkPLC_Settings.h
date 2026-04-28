#pragma once
#include "Core/ArduinoLinkPLC_SOURCE.h"
namespace ArduinoLinkPLC
{
    // Device Settings
    extern const char *DeviceID;
    extern IPAddress localIP;                      // Static IP for this PLC
    extern IPAddress gateway;                      // Master device IP
    extern IPAddress subnet;                       // Probably good on default
    extern const char *masterComputerSSID;         // Master device network name
    extern const char *masterComputerSSIDPassword; // Master device network password
    extern const int masterComputerPort;           // Master device port
}