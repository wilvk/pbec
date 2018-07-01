#include "headers.h"

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
  ss << std::showbase << std::internal << std::setfill('0') << std::setw(4) << std::hex << HexValue;
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
  ss << std::dec << HexValue << ", " << std::showbase << std::internal << std::setfill('0') << std::setw(4) << std::hex << HexValue;
  std::string decHexString = ss.str().c_str();
  return decHexString;
}

std::string ByteUtils::PrintByteArray(BYTE* ByteArray, int ArrayLength)
{
  std::string returnString;
  for(int i = 0; i < ArrayLength; i++)
  {
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(2) << std::hex << (int)(*ByteArray++);
    std::string hexString = ss.str().c_str();
    returnString += hexString;
  }
  return returnString;
}
