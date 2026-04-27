#pragma once
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
    void send_packet(char* type, char* dataJSON);
    // Receiving
    extern ArduinoLinkPLC::EventString onPacketReceived;
    //
    Packet constructPacket(char* dataJSON,const char* type,const char* ReceiverID);
    Packet deconstructPacket(const char* packet);
}
