#include "mainapp.h"


void MainApp::OpenFile(const char* Filename)
{
    Buffer *buffer = new Buffer();;
    buffer->ReadFile(Filename);
    std::vector<BYTE> bufferSubset;
    RetrieveStruct* retriever = new RetrieveStruct();
    bool printDebug = false;
    bool printInfo = true;

    ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

    //buffer->FixChecksum(false, AtomRomChecksumOffset);

    ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);

    ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);

    if(printDebug)
    {
      Console::PrintAtomRomHeaderInfo(atom_rom_header);
      Console::PrintAtomDataTableInfo(atom_data_table);
      Console::PrintAtomPowerplayTableInfo(atom_powerplay_table);
      //TODO: other structs/vects
    }

    int AtomPowertuneOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset;
    ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, AtomPowertuneOffset);

    int AtomFanTableOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset;
    ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, AtomFanTableOffset);

    int AtomMemClockTableOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usMclkDependencyTableOffset;
    ATOM_MCLK_TABLE atom_mclk_table = retriever->AtomMemClockTable(buffer, AtomMemClockTableOffset);
    std::vector<ATOM_MCLK_ENTRY> atom_mclk_entries = retriever->AtomMemClockEntries(buffer, AtomMemClockTableOffset, atom_mclk_table.ucNumEntries);

    std::cout << std::endl << "atom_data_table.PowerPlayInfo: " << atom_data_table.PowerPlayInfo;
    std::cout << std::endl << "atom_powerplay_table.usSclkDependencyTableOffset: " << atom_powerplay_table.usSclkDependencyTableOffset;

    int AtomSysClockEntriesOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usSclkDependencyTableOffset;

    std::cout << std::endl << "AtomSysClockEntriesOffset: " << AtomSysClockEntriesOffset;
    std::cout << std::endl << "atom_mclk_table.ucNumEntries: " << atom_mclk_table.ucNumEntries;

    ATOM_SCLK_TABLE atom_sclk_table = retriever->AtomSysClockTable(buffer, AtomSysClockEntriesOffset);

    std::cout << std::endl << "atom_sclk_table_offset: " << atom_sclk_table_offset;
    std::cout << std::endl << "atom_sclk_table.ucNumEntries: " << atom_sclk_table.ucNumEntries;

    std::vector<ATOM_SCLK_ENTRY> atom_sclk_entries = retriever->AtomSysClockEntries(buffer, atom_sclk_table_offset, atom_sclk_table.ucNumEntries);

    int atomVoltageTableOffset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usVddcLookupTableOffset;
    ATOM_VOLTAGE_TABLE atom_vddc_table = retriever->AtomVoltageTable(buffer, atomVoltageTableOffset);
    std::vector<ATOM_VOLTAGE_ENTRY> atom_vddc_entries = retriever->AtomVoltageEntries(buffer, atomVoltageTableOffset, atom_vddc_table.ucNumEntries);

    ATOM_VRAM_INFO atom_vram_info = retriever->AtomVramInfo(buffer, atom_data_table.VRAM_Info);

    int AtomVramEntryOffset = atom_vram_info_offset + sizeof(ATOM_VRAM_INFO);
    std::vector<ATOM_VRAM_ENTRY> atom_vram_entries = retriever->AtomVramEntries(buffer, atom_vram_info.ucNumOfVRAMModule, AtomVramEntryOffset);
    std::vector<ATOM_VRAM_TIMING_ENTRY> atom_vram_timing_entries = retriever->AtomVramTimingEntries(buffer, AtomVramEntryOffset);

    if(printInfo)
    {
      Console::PrintDefaultAtomRomHeaderInfo(atom_rom_header);
      Console::PrintDefaultAtomPowerplayTableInfo(atom_powerplay_table);
      Console::PrintDefaultAtomPowertuneTableInfo(atom_powertune_table);
      Console::PrintDefaultAtomFanTableInfo(atom_fan_table);
      Console::PrintDefaultAtomSysClockEntriesInfo(atom_sclk_table, atom_sclk_entries, atom_vddc_entries);
      Console::PrintDefaultAtomMemClockEntriesInfo(atom_mclk_table, atom_mclk_entries);
      Console::PrintDefaultAtomVramInfo(atom_vram_info, atom_vram_entries);
      Console::PrintDefaultAtomVramTimingEntriesInfo(atom_vram_timing_entries);
    }

    delete buffer;
}
