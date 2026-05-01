#include "internal/VeloxityLink_Internal.h"

namespace VeloxityLink
{
    Packet constructPacket(const char *type, const char *dataJSON)
    {
        Packet packet(type, dataJSON);
        packet.DataJSON = dataJSON;
        return packet;
    }
    Packet deconstructPacket(const char *packet)
    {
        Packet result("", "");

        StaticJsonDocument<256> doc;
        DeserializationError error = deserializeJson(doc, packet);
        if (error)
        {
            return result;
        }
        // Access field data from packet

        result.SenderID = doc["SendID"];
        result.Type = doc["type"];
        result.TimeStamp = doc["timestamp"];
        result.DataJSON = doc["data"];

        return result;
    }
}