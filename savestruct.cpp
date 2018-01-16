#include "savestruct.h"

template<typename T>
std::vector<BYTE> SaveStruct::toBytes(T &memStruct)
{
  int arraySize = sizeof(T);
  BYTE byteArray[arraySize];

  memcpy(byteArray, &memStruct, arraySize);
  std::vector<BYTE> returnVector(byteArray, byteArray + arraySize);

  return returnVector;
}

void SaveStruct::SaveTimingStraps(Buffer *BufferPtr, std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries, int AtomVramTimingOffset)
{
  int absolutePosition = AtomVramTimingOffset;
 
  for(std::vector<ATOM_VRAM_TIMING_ENTRY>::iterator it = AtomVramTimingEntries.begin(); it != AtomVramTimingEntries.end(); it++)
  {
    std::vector<BYTE> tempArray = toBytes<ATOM_VRAM_TIMING_ENTRY>(*it);

    for(std::vector<BYTE>::iterator byteIt = tempArray.begin(); byteIt != tempArray.end(); byteIt++)
	{
		std::cout << "< " << (int)*byteIt << " >";
        BufferPtr->SetValueAtPosition((int)*byteIt, 8, absolutePosition++, false); 
	}	
  } 
}
