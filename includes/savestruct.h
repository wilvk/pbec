#pragma once
#include "headers.h"

class SaveStruct
{
private:
  template<typename T>
  static std::vector<BYTE> toBytes(T &memStruct);

public:
  static void AtomVramTimingEntries(Buffer *BufferPtr, std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries, int AtomVramTimingOffset);
};
