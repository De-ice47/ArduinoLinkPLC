#include "ArduinoLinkPLC_Internal.h"

namespace ArduinoLinkPLC
{
    Packet constructPacket(const char *type, const char *dataJSON, const char *ReceiverID)
    {
        Packet packet(type, dataJSON, ReceiverID);
        packet.DataJSON = dataJSON;
        packet.ReceiverID = ReceiverID;
        return packet;
    }
    Packet deconstructPacket(const char *packet)
    {
        Packet result("", "", "");

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
        result.DataJSON = doc["data"];

        return result;
    }
}