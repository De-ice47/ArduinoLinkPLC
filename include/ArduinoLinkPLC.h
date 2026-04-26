
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
    //
    Packet constructPacket(char* dataJSON,char* ReceiverID);
    Packet deconstructPacket(const char* packet);
}
