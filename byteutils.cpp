#include "byteutils.h"

std::vector<BYTE> ByteUtils::GetBytes(void *Object)
{
    int size = sizeof(Object);
    BYTE* buffer = reinterpret_cast<BYTE*>(&Object);
    std::vector<BYTE> arr(buffer, buffer + size);

    return arr;
}

std::string ByteUtils::ToHexString(BYTE HexValue)
{
  DWORD converted = (DWORD)HexValue;
  return ToHexString(converted);
}


std::string ByteUtils::ToHexString(WORD HexValue)
{
  DWORD converted = (DWORD)HexValue;
  return ToHexString(converted);
}

std::string ByteUtils::ToHexString(DWORD HexValue)
{
  std::ostringstream ss;
  ss << "0x" << std::hex << HexValue;
  std::string hexString = ss.str().c_str();

  return hexString;
}

std::string ByteUtils::PrintDecHexString(BYTE HexValue)
{
  DWORD converted = (DWORD)HexValue;
  return PrintDecHexString(converted);
}


std::string ByteUtils::PrintDecHexString(WORD HexValue)
{
  DWORD converted = (DWORD)HexValue;
  return PrintDecHexString(converted);
}

std::string ByteUtils::PrintDecHexString(DWORD HexValue)
{
  std::ostringstream ss;
  ss << std::dec << HexValue << ", 0x" << std::hex << HexValue;
  std::string decHexString = ss.str().c_str();

  return decHexString;
}
