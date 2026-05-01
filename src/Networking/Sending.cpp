#include "internal/VeloxityLink_Internal.h"
namespace VeloxityLink
{
    void send_packet(const char *type, const char *dataJSON)
    {
        IPAddress broadcastIP(gateway[0], gateway[1], gateway[2], 255);
        send_packet(type, dataJSON, broadcastIP);
    }
    void send_packet(const char *type, const char *dataJSON, IPAddress targetIP)
    {
        send_packet(type, dataJSON, targetIP, 0);
    }
    void send_packet(const char *type, const char *dataJSON, IPAddress targetIP, long timeStamp)
    {
        Packet packet = VeloxityLink::constructPacket(type, dataJSON);
        StaticJsonDocument<256> doc;
        doc["SendID"] = packet.SenderID;
        doc["type"] = packet.Type;
        doc["data"] = packet.DataJSON;
        doc["timeStamp"] = timeStamp;
        String output;
        serializeJson(doc, output);
        udp.beginPacket(targetIP, masterComputerPort);
        udp.print(output);
        udp.endPacket();
        if (showSerialOutput)
            Serial.println("[Wifi-S] (" + String(packet.SenderID) + ") => (" + targetIP.toString() + ") <" + String(packet.Type) + "> :" + String(packet.DataJSON));
    }
}