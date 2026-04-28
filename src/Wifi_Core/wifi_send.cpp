#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    void send_packet(const char *type, const char *dataJSON)
    {
        const char *target = masterComputerSSID;
        Packet packet = ArduinoLinkPLC::constructPacket(type, dataJSON, target);
        StaticJsonDocument<256> doc;
        doc["SendID"] = packet.SenderID;
        doc["ReceiveID"] = packet.ReceiverID;
        doc["type"] = packet.Type;
        doc["data"] = packet.DataJSON;
        doc["timeStamp"] = packet.TimeStamp;
        String output;
        serializeJson(doc, output);
        udp.beginPacket(gateway, masterComputerPort);
        udp.print(output);
        udp.endPacket();
        if(showSerialOutput) Serial.println("[Wifi-S] (" + String(packet.SenderID) + ") => (" + String(packet.ReceiverID) + ") <" + String(packet.Type) + "> :" + String(packet.DataJSON));
    }
}