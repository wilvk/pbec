#include "headers.h"

void AppData::OpenFile(std::string Filename)
{
  retriever = new RetrieveStruct();
  buffer = new Buffer();
  buffer->ReadFile(Filename);
  getTables();
}

void AppData::getTables()
{
  getBootstrapTables();
  getPowertuneTable();
  getFanTable();
  getSysClockEntries();
  getMemClockEntries();
  getVoltageEntries();
  getVramInfo();
  getVramEntries();
  getVramTimingEntries();
}

void AppData::getBootstrapTables()
{
  atom_rom_header = retriever->AtomRomHeader(buffer);
  atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
}

void AppData::getPowertuneTable()
{
  AtomPowertuneOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset;
  atom_powertune_table = retriever->AtomPowertuneTable(buffer, AtomPowertuneOffset);
}

void AppData::getFanTable()
{
  AtomFanTableOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset;
  atom_fan_table = retriever->AtomFanTable(buffer, AtomFanTableOffset);
}

void AppData::getSysClockEntries()
{
  AtomSysClockEntriesOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usSclkDependencyTableOffset;
  atom_sclk_table = retriever->AtomSysClockTable(buffer, AtomSysClockEntriesOffset);
  atom_sclk_entries = retriever->AtomSysClockEntries(buffer, AtomSysClockEntriesOffset, atom_sclk_table.ucNumEntries);
}

void AppData::getMemClockEntries()
{
  AtomMemClockTableOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usMclkDependencyTableOffset;
  atom_mclk_table = retriever->AtomMemClockTable(buffer, AtomMemClockTableOffset);
  atom_mclk_entries = retriever->AtomMemClockEntries(buffer, AtomMemClockTableOffset, atom_mclk_table.ucNumEntries);
}

void AppData::getVoltageEntries()
{
  atomVoltageTableOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usVddcLookupTableOffset;
  atom_vddc_table = retriever->AtomVoltageTable(buffer, atomVoltageTableOffset);
  atom_vddc_entries = retriever->AtomVoltageEntries(buffer, atomVoltageTableOffset, atom_vddc_table.ucNumEntries);
}

void AppData::getVramInfo()
{
  atom_vram_info_offset = atom_data_table.VRAM_Info;
  atom_vram_info = retriever->AtomVramInfo(buffer, atom_vram_info_offset);
}

void AppData::getVramEntries()
{
  AtomVramEntryOffset = atom_vram_info_offset + sizeof(ATOM_VRAM_INFO);
  atom_vram_entries = retriever->AtomVramEntries(buffer, atom_vram_info.ucNumOfVRAMModule, AtomVramEntryOffset);
}

void AppData::getVramTimingEntries()
{
  AtomVramTimingOffset = atom_vram_info_offset + atom_vram_info.usMemClkPatchTblOffset + VRAM_TIMING_ENTRIES_OFFSET;
  atom_vram_timing_entries = retriever->AtomVramTimingEntries(buffer, AtomVramTimingOffset);
}

void AppData::PrintSummary(std::string ReadArea)
{
  if(ReadArea == "HEADER")
  {
    Console::PrintDefaultAtomRomHeaderInfo(atom_rom_header);
  }
  else if(ReadArea == "POWERPLAY")
  {
    Console::PrintDefaultAtomPowerplayTableInfo(atom_powerplay_table);
  }
  else if(ReadArea == "POWERTUNE")
  {
    Console::PrintDefaultAtomPowertuneTableInfo(atom_powertune_table);
  }
  else if(ReadArea == "FAN")
  {
    Console::PrintDefaultAtomFanTableInfo(atom_fan_table);
  }
  else if(ReadArea == "SYSTEM_CLOCK")
  {
    Console::PrintDefaultAtomSysClockEntriesInfo(atom_sclk_table, atom_sclk_entries, atom_vddc_entries);
  }
  else if(ReadArea == "MEMORY_CLOCK")
  {
    Console::PrintDefaultAtomMemClockEntriesInfo(atom_mclk_table, atom_mclk_entries);
  }
  else if(ReadArea == "VRAM_INFO")
  {
    Console::PrintDefaultAtomVramInfo(atom_vram_info, atom_vram_entries);
    Console::PrintDefaultAtomVramEntriesInfo(atom_vram_info, atom_vram_entries);
  }
  else if(ReadArea == "VRAM_TIMING")
  {
    Console::PrintDefaultAtomVramTimingEntriesInfo(atom_vram_timing_entries);
  }
  else if(ReadArea == "ALL")
  {
    Console::PrintDefaultAtomRomHeaderInfo(atom_rom_header);
    Console::PrintDefaultAtomPowerplayTableInfo(atom_powerplay_table);
    Console::PrintDefaultAtomPowertuneTableInfo(atom_powertune_table);
    Console::PrintDefaultAtomFanTableInfo(atom_fan_table);
    Console::PrintDefaultAtomSysClockEntriesInfo(atom_sclk_table, atom_sclk_entries, atom_vddc_entries);
    Console::PrintDefaultAtomMemClockEntriesInfo(atom_mclk_table, atom_mclk_entries);
    Console::PrintDefaultAtomVramInfo(atom_vram_info, atom_vram_entries);
    Console::PrintDefaultAtomVramEntriesInfo(atom_vram_info, atom_vram_entries);
    Console::PrintDefaultAtomVramTimingEntriesInfo(atom_vram_timing_entries);
  }
}

void AppData::PrintVerbose(std::string ReadArea)
{
  if(ReadArea == "HEADER")
  {
    Console::PrintAtomRomHeaderInfo(atom_rom_header);
  }
  else if(ReadArea == "DATA")
  {
    Console::PrintAtomDataTableInfo(atom_data_table);
  }
  else if(ReadArea == "POWERPLAY")
  {
    Console::PrintAtomPowerplayTableInfo(atom_powerplay_table);
  }
  else if(ReadArea == "POWERTUNE")
  {
    Console::PrintAtomPowertuneTableInfo(atom_powertune_table);
  }
  else if(ReadArea == "FAN")
  {
    Console::PrintAtomFanTableInfo(atom_fan_table);
  }
  else if(ReadArea == "ALL")
  {
    Console::PrintAtomRomHeaderInfo(atom_rom_header);
    Console::PrintAtomDataTableInfo(atom_data_table);
    Console::PrintAtomPowerplayTableInfo(atom_powerplay_table);
    Console::PrintAtomPowertuneTableInfo(atom_powertune_table);
    Console::PrintAtomFanTableInfo(atom_fan_table);
  }
}

void AppData::SetTimingStraps(BYTE* InsertData, std::vector<int> To)
{
  for(std::vector<int>::iterator it = To.begin(); it != To.end(); it++)
  {
    std::cout << std::endl <<
      "Copying strap to array item #" << *it << std::endl <<
      "Value Before: " << ByteUtils::PrintByteArray( atom_vram_timing_entries.at(*it).ucLatency, VRAM_TIMING_LATENCY_LENGTH );
    memcpy( atom_vram_timing_entries.at(*it).ucLatency, InsertData, VRAM_TIMING_LATENCY_LENGTH * sizeof(BYTE) );
    std::cout << std::endl <<
      "Value After:  " << ByteUtils::PrintByteArray( atom_vram_timing_entries.at(*it).ucLatency, VRAM_TIMING_LATENCY_LENGTH );
  }
}

void AppData::SetTimingStraps(std::string InsertData, std::vector<int> To)
{
  char const *insertData = InsertData.c_str();
  this->SetTimingStraps((BYTE*)insertData, To);
}

void AppData::SetTimingStraps(int From, std::vector<int> To)
{
  BYTE* fromStrap;
  fromStrap = atom_vram_timing_entries.at(From).ucLatency;

  std::cout << std::endl <<
    "Copying strap from array item #" << From << std::endl <<
    "With value:   " << ByteUtils::PrintByteArray( fromStrap, TIMING_STRAPS_LENGTH );

  if(From >= To.size())
  {
    std::cout << std::endl << "Error: strap to copy from is larger than strap array. " << "From: " << From << " Array Size: " << To.size();
    return;
  }

  this->SetTimingStraps( fromStrap, To);
}

void AppData::WriteTimingStrapsToBuffer()
{
  SaveStruct::SaveTimingStraps(buffer, atom_vram_timing_entries, AtomVramTimingOffset);
}

void AppData::WriteBufferToFile(std::string FileName)
{
  buffer->WriteFile(FileName);
}
