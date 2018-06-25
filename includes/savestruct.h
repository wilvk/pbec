#pragma once

#include<cstring>

#include "structs.h"
#include "buffer.h"

class SaveStruct
{

private:

    template<typename T>
    static std::vector<BYTE> toBytes(T &memStruct);

public:

    static void SaveTimingStraps(Buffer *BufferPtr, std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries, int AtomVramTimingOffset);

};
