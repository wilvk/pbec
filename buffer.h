#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "typedefs.h"

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

  void FixChecksum(bool save, int atom_rom_checksum_offset);

  bool SetValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency);

  bool SetValueAtPosition(int value, int bits, int position, bool isFrequency);

  int GetValueAtPosition(int bits, int position, bool isFrequency);

  std::string GetStringFromOffset(int Offset);

  std::string TableWalk(int Offset, std::vector<int> ByteSizes);

  std::string TableWalk(int Offset, std::vector<int> ByteSizes, bool IsFrequency);
};


#endif /* end of include guard: BUFFER_H */
