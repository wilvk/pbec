#include "byteutils.h"

std::vector<BYTE> ByteUtils::GetBytes(void *Object)
{
    int size = sizeof(Object);
    BYTE* buffer = reinterpret_cast<BYTE*>(&Object);
    std::vector<BYTE> arr(buffer, buffer + size);

    return arr;
}

std::string ByteUtils::ConvertIntToHexString(WORD* data, int len)
{
    std::stringstream ss;
    ss << std::hex;

    for(int i = 0; i < len; ++i)
    {
        ss << std::setw(2) << std::setfill('0') << (int)data[i];
    }

    return ss.str();
}
