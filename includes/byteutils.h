#pragma once
#include "headers.h"

class ByteUtils
{
private:
  static int HexAsciiToDec(int value);

public:
  std::vector<BYTE> GetBytes(void *Object);
  static std::string ToHexString(BYTE HexValue);
  static std::string ToHexString(WORD HexValue);
  static std::string ToHexString(DWORD HexValue);
  static std::string PrintDecHexString(BYTE HexValue);
  static std::string PrintDecHexString(WORD HexValue);
  static std::string PrintDecHexString(DWORD HexValue);
  static std::string PrintByteArray(BYTE* ByteArray, int ArrayLength);
  static BYTE* HexStringToBytes(BYTE* HexString, int ArrayLength);
};
