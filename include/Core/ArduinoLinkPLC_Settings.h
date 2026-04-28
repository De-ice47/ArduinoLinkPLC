#pragma once
#include "Core/ArduinoLinkPLC_SOURCE.h"
namespace ArduinoLinkPLC
{
    // Device Settings
    extern const char *deviceSenderID;
    extern IPAddress masterComputerIP;        // Input the master device
    extern const char *masterComputerSSID;    // Master device network name
    extern const char *masterComputerSSIDPassword; // Master device network password
    extern const int masterComputerPort;                 // Master device port
}