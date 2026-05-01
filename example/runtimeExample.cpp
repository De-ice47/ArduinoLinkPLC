#include <ArduinoLinkPLC.h>

void setup()
{
    ArduinoLinkPLC::setDeviceID("My Device Name");                  // A name to identify the microcontroller on the network
    ArduinoLinkPLC::setLocalIP(IPAddress(192, 168, 0, 100));        // The microcontroller's IP address on the network
    ArduinoLinkPLC::setGatewayIP(IPAddress(192, 168, 0, 1));        // The router or hotspot IP address
    ArduinoLinkPLC::setNetworkSSID("MySSIDName");                   // The network name
    ArduinoLinkPLC::setNetworkSSID("MySSIDName", "MySSIDPassword"); // The network name and password (if required)
    ArduinoLinkPLC::setPort(49800);                                 // The port number to connect to on the master device (must match the master device's listening port)
    ArduinoLinkPLC::start_network();                                // Connect to the network and start listening for packets
}
void loop()
{
    ArduinoLinkPLC::run_network(); // Run the network loop to check for incoming packets and maintain the connection
}