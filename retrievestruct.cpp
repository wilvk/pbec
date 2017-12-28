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
    int atom_rom_header_offset = Buffer->GetValueAtPosition(16, atom_rom_header_ptr, false);
    bufferSubset = Buffer->GetSubset(atom_rom_header_offset);
    ATOM_ROM_HEADER atom_rom_header = fromBytes<ATOM_ROM_HEADER>(bufferSubset);

    return atom_rom_header;
}

ATOM_DATA_TABLES RetrieveStruct::AtomDataTables(Buffer* Buffer, int MasterDataTableOffset)
{
    std::vector<BYTE> bufferSubset;
    atom_data_table_offset = MasterDataTableOffset;
    bufferSubset = Buffer->GetSubset(atom_data_table_offset);
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
