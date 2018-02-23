#pragma once

#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>

#include "typedefs.h"

class ByteUtils
{

private:

public:

    std::vector<BYTE> GetBytes(void *Object);
    static std::string ToHexString(BYTE HexValue);
    static std::string ToHexString(WORD HexValue);
    static std::string ToHexString(DWORD HexValue);
    static std::string PrintDecHexString(BYTE HexValue);
    static std::string PrintDecHexString(WORD HexValue);
    static std::string PrintDecHexString(DWORD HexValue);
    static std::string PrintByteArray(BYTE* ByteArray, int ArrayLength);

};
