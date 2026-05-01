#pragma once
#include "internal/ArduinoLinkPLC_Internal.h"

namespace ArduinoLinkPLC
{
    // Construction functions
    Packet constructPacket(const char * type, const char * data);
    Packet deconstructPacket(const char *);
}