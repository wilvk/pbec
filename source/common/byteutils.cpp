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

int ByteUtils::HexAsciiToDec(int value)
{
  if(value > 47 && value < 59)
  {
    value -= 48;
  }
  else if(value > 96 && value < 103)
  {
    value -= 97;
    value += 10;
  }
  else if(value > 64 && value < 71)
  {
    value -= 65;
    value += 10;
  }
  else
  {
    value = 0;
  }
  return value;
}

BYTE* ByteUtils::HexStringToBytes(BYTE* HexString, int ArrayLength)
{
  BYTE* returnBytes;
  returnBytes = (BYTE*) malloc(ArrayLength/2);
  int j=0;

  for(int i = 0; i < ArrayLength; i++)
  {
    if(i % 2 == 0)
    {
      int valueHigh = (int)(*(HexString+i));
      int valueLow =  (int)(*(HexString+i+1));

      valueHigh = ByteUtils::HexAsciiToDec(valueHigh);
      valueLow =  ByteUtils::HexAsciiToDec(valueLow);

      valueHigh *= 16;
      int total = valueHigh + valueLow;
      *(returnBytes+j++) = (BYTE)total;
    }
  }
  return returnBytes;
}
