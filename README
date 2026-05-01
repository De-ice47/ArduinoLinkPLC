# ArduinoLinkPLC
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/de-ice47/library/ArduinoLinkPLC.svg)](https://registry.platformio.org/libraries/de-ice47/ArduinoLinkPLC)

Lightweight WiFi communication bridge for Arduino devices to interface with UDP ports on other devices.
____
__Features__
* Packet Send/Receive

__Getting Started__
* Setup

The setup function is where networks should be configured to the desired values before the network is started.
```
#include <Arduino.h>
#include "ArduinoLinkPLC.h"
void setup()
{
    ArduinoLinkPLC::setDeviceID("ArdUnoR4");

    // The IP address of your router or hotspot that the network is hosted on
    ArduinoLinkPLC::setGatewayIP(IPAddress(###, ###, ###, 1));

    // The address of the microcontroller whose first three numbers will match
    // the gateway IP addresss, and the last number can be between 2 and 254
    ArduinoLinkPLC::setLocalIP(IPAddress(###, ###, ###, 99));


    ArduinoLinkPLC::setNetworkSSID("My Network Name", "My Network Password");

    ArduinoLinkPLC::setPort(49800);
}
```
* Starting the network

Once everything is set as desired, start the network connection with this function.
```
ArduinoLinkPLC::start_network();
```
* Network Runtime

When the network is running, the ```run_network();``` function will need to be ran continuously to allow the microcontroller's connection to keep functioning.
```
void loop()
{
    ArduinoLinkPLC::run_network();
}
```
* Receiving Packets

To receive packets transmitted to this device, use the ``` ArduinoLinkPLC::onPacketReceived.subscribe();``` in ```setup()``` and then input a function name into the argument to subscribe it to the event.
```
void packetReceivedFunction(const ArduinoLinkPLC::Packet &packet)
{
    // This function will be called whenever a packet is received
    // You can add your own code here to handle the packet data as needed
    Serial.println(packet.DataJSON);
}
void setup()
{
    ArduinoLinkPLC::onPacketReceived.subscribe(packetReceivedFunction);
}
```
* Stopping the network

When the network needs to be turned off, use this function.
```
ArduinoLinkPLC::stop_network();
```