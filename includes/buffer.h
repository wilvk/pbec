#pragma once
#include "typedefs.h"
#include "headers.h"

class Buffer
{
private:
  int bufferPosition;

public:
  std::vector<BYTE> FileData;
  std::vector<BYTE> ReadFile(std::string Filename);
  void WriteFile(std::string FileName);
  std::vector<BYTE> GetSubset(int &Offset);
  void SetSubset(int &Offset, std::vector<BYTE>Bytes);
  void SetBufferPosition(int NewPosition);
  int GetBufferPosition();
  void FixChecksum(bool Save);
  bool SetValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency);
  bool SetValueAtPosition(int value, int bits, int position, bool isFrequency);
  int GetValueAtPosition(int Bits, int Position, bool IsFrequency);
  std::string GetStringFromOffset(int Offset);
  std::string TableWalk(int Offset, std::vector<int> ByteSizes);
  std::string TableWalk(int Offset, std::vector<int> ByteSizes, bool IsFrequency);
  BYTE GetByteAtPosition(int Position);
};
