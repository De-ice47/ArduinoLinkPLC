#pragma once
#include "internal/VeloxityLink_Internal.h"

namespace VeloxityLink
{
    // Construction functions
    Packet constructPacket(const char * type, const char * data);
    Packet deconstructPacket(const char *);
}