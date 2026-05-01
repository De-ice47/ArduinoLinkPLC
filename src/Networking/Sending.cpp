#include "internal/ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    void send_packet(const char *type, const char *dataJSON)
    {
        IPAddress broadcastIP(gateway[0], gateway[1], gateway[2], 255);
        send_packet(type, dataJSON, broadcastIP);
    }
    void send_packet(const char *type, const char *dataJSON, IPAddress targetIP)
    {
        String target = targetIP.toString();
        Packet packet = ArduinoLinkPLC::constructPacket(type, dataJSON, target.c_str());
        StaticJsonDocument<256> doc;
        doc["SendID"] = packet.SenderID;
        doc["ReceiveID"] = packet.ReceiverID;
        doc["type"] = packet.Type;
        doc["data"] = packet.DataJSON;
        doc["timeStamp"] = packet.TimeStamp;
        String output;
        serializeJson(doc, output);
        udp.beginPacket(targetIP, masterComputerPort);
        udp.print(output);
        udp.endPacket();
        if (showSerialOutput)
            Serial.println("[Wifi-S] (" + String(packet.SenderID) + ") => (" + String(packet.ReceiverID) + ") <" + String(packet.Type) + "> :" + String(packet.DataJSON));
    }

}