#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "typedefs.h"
#include "byteutils.h"

class Buffer
{

private:

  int bufferPosition;

public:

  std::vector<BYTE> FileData;

  std::vector<BYTE> ReadFile(const char* Filename);

  std::vector<BYTE> GetSubset(int &Offset);

  void SetBufferPosition(int NewPosition);

  int GetBufferPosition();

  void FixChecksum(bool Save, int AtomRomChecksumOffset);

  bool SetValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency);

  bool SetValueAtPosition(int value, int bits, int position, bool isFrequency);

  int GetValueAtPosition(int Bits, int Position, bool IsFrequency);

  std::string GetStringFromOffset(int Offset);

  std::string TableWalk(int Offset, std::vector<int> ByteSizes);

  std::string TableWalk(int Offset, std::vector<int> ByteSizes, bool IsFrequency);

  BYTE GetByteAtPosition(int Position);
};


#endif /* end of include guard: BUFFER_H */
