#include "retrievestruct.h"

template<typename T>
T RetrieveStruct::fromBytes(std::vector<BYTE> &StringArray)
{
  T typeObject = T();
  std::memcpy(&typeObject, &StringArray[0], sizeof typeObject);
  return typeObject;
}

ATOM_ROM_HEADER RetrieveStruct::AtomRomHeader(Buffer* Buffer)
{
  std::vector<BYTE> bufferSubset;
  int atom_rom_header_offset = Buffer->GetValueAtPosition(16, ATOM_ROM_HEADER_PTR, false);
  bufferSubset = Buffer->GetSubset(atom_rom_header_offset);
  ATOM_ROM_HEADER atom_rom_header = fromBytes<ATOM_ROM_HEADER>(bufferSubset);
  return atom_rom_header;
}

ATOM_DATA_TABLES RetrieveStruct::AtomDataTables(Buffer* Buffer, int MasterDataTableOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(MasterDataTableOffset);
  ATOM_DATA_TABLES atom_data_tables = fromBytes<ATOM_DATA_TABLES>(bufferSubset);
  return atom_data_tables;
}

ATOM_POWERPLAY_TABLE RetrieveStruct::AtomPowerplayTable(Buffer* Buffer, int AtomPowerplayOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(AtomPowerplayOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = fromBytes<ATOM_POWERPLAY_TABLE>(bufferSubset);
  return atom_powerplay_table;
}

ATOM_POWERTUNE_TABLE RetrieveStruct::AtomPowertuneTable(Buffer* Buffer, int AtomPowertuneOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(AtomPowertuneOffset);
  ATOM_POWERTUNE_TABLE atom_powertune_table = fromBytes<ATOM_POWERTUNE_TABLE>(bufferSubset);
  return atom_powertune_table;
}

ATOM_FAN_TABLE RetrieveStruct::AtomFanTable(Buffer* Buffer, int AtomFanOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(AtomFanOffset);
  ATOM_FAN_TABLE atom_fan_table = this->fromBytes<ATOM_FAN_TABLE>(bufferSubset);

  return atom_fan_table;
}

ATOM_MCLK_TABLE RetrieveStruct::AtomMemClockTable(Buffer * Buffer, int AtomMemClockTableOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(AtomMemClockTableOffset);
  ATOM_MCLK_TABLE atom_mclk_table = fromBytes<ATOM_MCLK_TABLE>(bufferSubset);

  return atom_mclk_table;
}

std::vector<ATOM_MCLK_ENTRY> RetrieveStruct::AtomMemClockEntries(Buffer * Buffer, int AtomMemClockTableOffset, int NumMemClockTableEntries)
{
  std::vector<BYTE> bufferSubset;
  std::vector<ATOM_MCLK_ENTRY> atom_mclk_entries = std::vector<ATOM_MCLK_ENTRY>(NumMemClockTableEntries);
  for (int i = 0; i < atom_mclk_entries.size(); i++)
  {
    int atom_mclk_entry_offset = AtomMemClockTableOffset + sizeof(ATOM_MCLK_TABLE) + sizeof(ATOM_MCLK_ENTRY) * i;
    bufferSubset = Buffer->GetSubset(atom_mclk_entry_offset);
    atom_mclk_entries[i] = fromBytes<ATOM_MCLK_ENTRY>(bufferSubset);
  }
  return atom_mclk_entries;
}

ATOM_SCLK_TABLE RetrieveStruct::AtomSysClockTable(Buffer* Buffer, int AtomSysClockTableOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(AtomSysClockTableOffset);
  ATOM_SCLK_TABLE atom_sclk_table = fromBytes<ATOM_SCLK_TABLE>(bufferSubset);
  return atom_sclk_table;
}

std::vector<ATOM_SCLK_ENTRY> RetrieveStruct::AtomSysClockEntries(Buffer* Buffer, int AtomSysClockTableOffset, int NumSysClockTableEntries)
{
  std::vector<BYTE> bufferSubset;
  std::vector<ATOM_SCLK_ENTRY> atom_sclk_entries = std::vector<ATOM_SCLK_ENTRY>(NumSysClockTableEntries);
  for (int i = 0; i < atom_sclk_entries.size(); i++)
  {
    int atom_sclk_entry_offset = AtomSysClockTableOffset + sizeof(ATOM_SCLK_TABLE) + (sizeof(ATOM_SCLK_ENTRY) * i);
    bufferSubset = Buffer->GetSubset(atom_sclk_entry_offset);
    atom_sclk_entries[i] = fromBytes<ATOM_SCLK_ENTRY>(bufferSubset);
  }
  return atom_sclk_entries;
}

ATOM_VOLTAGE_TABLE RetrieveStruct::AtomVoltageTable(Buffer* Buffer, int AtomVddcTableOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(AtomVddcTableOffset);
  ATOM_VOLTAGE_TABLE atom_vddc_table = this->fromBytes<ATOM_VOLTAGE_TABLE>(bufferSubset);
  return atom_vddc_table;
}

std::vector<ATOM_VOLTAGE_ENTRY> RetrieveStruct::AtomVoltageEntries(Buffer* Buffer, int AtomVoltageTableOffset, int NumVoltageTableEntries)
{
  std::vector<BYTE> bufferSubset;
  std::vector<ATOM_VOLTAGE_ENTRY> atom_vddc_entries = std::vector<ATOM_VOLTAGE_ENTRY>(NumVoltageTableEntries);
  for (int i = 0; i < NumVoltageTableEntries; i++)
  {
    int atom_vddc_entry_offset = AtomVoltageTableOffset + sizeof(ATOM_VOLTAGE_TABLE) + sizeof(ATOM_VOLTAGE_ENTRY) * i;
    bufferSubset = Buffer->GetSubset(atom_vddc_entry_offset);
    atom_vddc_entries[i] = fromBytes<ATOM_VOLTAGE_ENTRY>(bufferSubset);
  }
  return atom_vddc_entries;
}

ATOM_VRAM_INFO RetrieveStruct::AtomVramInfo(Buffer* Buffer, int AtomVramInfoOffset)
{
  std::vector<BYTE> bufferSubset;
  bufferSubset = Buffer->GetSubset(AtomVramInfoOffset);
  ATOM_VRAM_INFO atom_vram_info = fromBytes<ATOM_VRAM_INFO>(bufferSubset);
  return atom_vram_info;
}

std::vector<ATOM_VRAM_ENTRY> RetrieveStruct::AtomVramEntries(Buffer* Buffer, int NumVramTableEntries, int &AtomVramEntryOffset)
{
  std::vector<BYTE> bufferSubset;
  std::vector<ATOM_VRAM_ENTRY> atom_vram_entries = std::vector<ATOM_VRAM_ENTRY>(NumVramTableEntries);
  for (int i = 0; i < NumVramTableEntries; i++)
  {
    bufferSubset = Buffer->GetSubset(AtomVramEntryOffset);
    atom_vram_entries[i] = fromBytes<ATOM_VRAM_ENTRY>(bufferSubset);
    AtomVramEntryOffset += atom_vram_entries[i].usModuleSize;
  }
  return atom_vram_entries;
}

std::vector<ATOM_VRAM_TIMING_ENTRY> RetrieveStruct::AtomVramTimingEntries(Buffer* Buffer, int AtomVramTimingOffset)
{
  std::vector<BYTE> bufferSubset;
  std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries = std::vector<ATOM_VRAM_TIMING_ENTRY>(MAX_VRAM_ENTRIES);
  for (int i = 0; i < MAX_VRAM_ENTRIES; i++)
  {
    int localOffset = AtomVramTimingOffset + sizeof(ATOM_VRAM_TIMING_ENTRY) * i;
    bufferSubset = Buffer->GetSubset(localOffset);
    AtomVramTimingEntries[i] = fromBytes<ATOM_VRAM_TIMING_ENTRY>(bufferSubset);
    if (AtomVramTimingEntries[i].ulClkRange == 0)
    {
      AtomVramTimingEntries.resize(i);
      break;
    }
  }
  return AtomVramTimingEntries;
}
