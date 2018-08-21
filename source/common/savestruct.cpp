#include "headers.h"

template<typename T>
std::vector<BYTE> SaveStruct::toBytes(T &memStruct)
{
  int arraySize = sizeof(T);
  BYTE byteArray[arraySize];
  memcpy(byteArray, &memStruct, arraySize);
  std::vector<BYTE> returnVector(byteArray, byteArray + arraySize);
  return returnVector;
}

void SaveStruct::AtomVramTimingEntries(Buffer *BufferPtr, std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries, int AtomVramTimingOffset)
{
  std::cout << std::endl << "Saving timing straps";

  int i = 0;
  for(std::vector<ATOM_VRAM_TIMING_ENTRY>::iterator it = AtomVramTimingEntries.begin(); it != AtomVramTimingEntries.end(); it++,i++)
  {
    int localOffset = AtomVramTimingOffset + sizeof(ATOM_VRAM_TIMING_ENTRY) * i;
    std::vector<BYTE> tempArray = toBytes<ATOM_VRAM_TIMING_ENTRY>(*it);
    BufferPtr->SetSubset(localOffset, tempArray);
  }
}
