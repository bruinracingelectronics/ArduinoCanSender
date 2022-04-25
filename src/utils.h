#include <mcp2515.h>
#include <mcp2515_defs.h>
#include <stddef.h>


namespace Utils
{
    union floatData
    {
        float f;
        unsigned char fBuff[sizeof(float)];
    };

    union int32Data
    {
        int32_t i;
        unsigned char iBuff[sizeof(int32_t)];
    };

    union int16Data
    {
        int16_t i;
        unsigned char iBuff[sizeof(int16_t)];
    };

    tCAN makeFloatMessage(uint16_t id, float value);
    tCAN makeInt32Message(uint16_t id, int32_t value);
    tCAN makeInt16Message(uint16_t id, int16_t value);
}