#include "internal/VeloxityLink_Internal.h"
namespace VeloxityLink
{
    void statusLight(bool state)
    {
        if (useInternalLED)
        {
            digitalWrite(13, state ? HIGH : LOW);
        }
    }
}