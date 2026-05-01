#include "internal/ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    void statusLight(bool state)
    {
        if (useInternalLED)
        {
            digitalWrite(13, state ? HIGH : LOW);
        }
    }
}