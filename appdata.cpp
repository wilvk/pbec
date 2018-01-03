#include "appdata.h"


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
  atom_vram_timing_entries = retriever->AtomVramTimingEntries(buffer, atom_vram_info, atom_vram_info_offset);
}

void AppData::PrintSummary()
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

void AppData::PrintVerbose()
{
  Console::PrintAtomRomHeaderInfo(atom_rom_header);
  Console::PrintAtomDataTableInfo(atom_data_table);
  Console::PrintAtomPowerplayTableInfo(atom_powerplay_table);
  Console::PrintAtomPowertuneTableInfo(atom_powertune_table);
  Console::PrintAtomFanTableInfo(atom_fan_table);
}
