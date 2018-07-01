#pragma once

#include <cstring>

#include "structs.h"
#include "buffer.h"

class RetrieveStruct
{
private:
  template<typename T>
  T fromBytes(std::vector<BYTE> &StringArray);

public:
  ATOM_ROM_HEADER AtomRomHeader(Buffer* Buffer);
  ATOM_DATA_TABLES AtomDataTables(Buffer* Buffer, int MasterDataTableOffset);
  ATOM_POWERPLAY_TABLE AtomPowerplayTable(Buffer* Buffer, int AtomPowerplayOffset);
  ATOM_POWERTUNE_TABLE AtomPowertuneTable(Buffer* Buffer, int AtomPowertuneOffset);
  ATOM_FAN_TABLE AtomFanTable(Buffer* Buffer, int AtomFanOffset);
  ATOM_MCLK_TABLE AtomMemClockTable(Buffer * Buffer, int AtomMemClockTableOffset);
  std::vector<ATOM_MCLK_ENTRY> AtomMemClockEntries(Buffer* Buffer, int AtomMemClockTableOffset, int NumMemClockTableEntries);
  ATOM_SCLK_TABLE AtomSysClockTable(Buffer* Buffer, int AtomSysClockTableOffset);
  std::vector<ATOM_SCLK_ENTRY> AtomSysClockEntries(Buffer* Buffer, int AtomSysClockTableOffset, int NumSysClockTableEntries);
  ATOM_VOLTAGE_TABLE AtomVoltageTable(Buffer* Buffer, int AtomVddcTableOffset);
  std::vector<ATOM_VOLTAGE_ENTRY> AtomVoltageEntries(Buffer* Buffer, int AtomVoltageTableOffset, int NumVoltageTableEntries);
  ATOM_VRAM_INFO AtomVramInfo(Buffer* Buffer, int AtomVramInfoOffset);
  std::vector<ATOM_VRAM_ENTRY> AtomVramEntries(Buffer* Buffer, int NumVramTableEntries, int& AtomVramEntryOffset);
  std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries(Buffer* Buffer, int AtomVramTimingOffset);
};
