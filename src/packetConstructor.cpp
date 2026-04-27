#include "ArduinoLinkPLC.h"

namespace ArduinoLinkPLC
{
    Packet constructPacket(char *dataJSON, const char *type, const char *ReceiverID)
    {
        Packet packet(ReceiverID, type, dataJSON);
        packet.DataJSON = dataJSON;
        return packet;
    }
    Packet deconstructPacket(const char *packet)
    {
        Packet result("","","");

        StaticJsonDocument<256> doc;
        DeserializationError error = deserializeJson(doc, packet);
        if (error)
        {
            return result;
        }
        // Access field data from packet

        result.SenderID = doc["SendID"];
        result.ReceiverID = doc["ReceiveID"];
        result.Type = doc["type"];
        result.TimeStamp = doc["timeStamp"];

        if (strcmp(result.Type,"PING") == 0)
        {
            Serial.println("[Wifi] (PING) Sender: " + String(result.SenderID) + ", Receiver: " + String(result.ReceiverID));
        }
        return result;
    }
}