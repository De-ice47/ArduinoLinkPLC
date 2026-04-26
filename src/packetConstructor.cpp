#include "ArduinoLinkPLC.h"

namespace ArduinoLinkPLC
{
    Packet constructPacket(char* dataJSON, const char* ReceiverID)
    {
        Packet packet(ReceiverID);
        packet.DataJSON = dataJSON;
        return packet;
    }
    Packet deconstructPacket(const char* packet)
    {
        StaticJsonDocument<256> doc;

        DeserializationError error = deserializeJson(doc,packet);

        if (error)
            return;

        // Access field data from packet
        const char* senderID = doc["SendID"];
        const char* receiverID = doc["ReceiveID"];
        const char* type = doc["type"];
        const long timeStamp = doc["timeStamp"];

        if (type == "PING")
        {
            Serial.println("[Wifi] (PING) Sender: " + String(senderID) + ", Receiver: " + String(receiverID));
        }
    }
}