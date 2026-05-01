#pragma once
#include "internal/ArduinoLinkPLC_Internal.h"

namespace ArduinoLinkPLC
{
    // Construction functions
    Packet constructPacket(const char * type, const char * data, const char * receiver);
    Packet deconstructPacket(const char *);
}