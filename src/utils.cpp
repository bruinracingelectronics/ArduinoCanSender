#include "utils.h"
namespace Utils
{
    tCAN makeFloatMessage(uint16_t id, float value)
    {
        tCAN message;

        message.id = id;
        message.header.rtr = 0;
        message.header.length = 4;

        floatData fData;
        fData.f = value;

        for (size_t i = 0; i < sizeof(floatData); i++)
        {
            message.data[i] = fData.fBuff[i];
        }

        return message;
    }

    tCAN makeInt32Message(uint16_t id, int32_t value)
    {
        tCAN message;

        message.id = id;
        message.header.rtr = 0;
        message.header.length = 4;

        int32Data data;
        data.i = value;

        for (size_t i = 0; i < sizeof(floatData); i++)
        {
            message.data[i] = data.iBuff[i];
        }

        return message;
    }

    tCAN makeInt16Message(uint16_t id, int16_t value)
    {
        tCAN message;

        message.id = id;
        message.header.rtr = 0;
        message.header.length = 2;

        int16Data data;
        data.i = value;

        for (size_t i = 0; i < sizeof(int16Data); i++)
        {
            message.data[i] = data.iBuff[i];
        }

        return message;
    }
}