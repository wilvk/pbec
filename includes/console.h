# pragma once

#include <iostream>
#include <algorithm>
#include "typedefs.h"
#include "structs.h"
#include "byteutils.h"

class Console
{

private:

    static void printSectionHeader(const char* headerText);
    static void printSectionFooter();

public:

// verbose structs
    static void PrintAtomRomHeaderInfo(ATOM_ROM_HEADER AtomRomHeader);
    static void PrintAtomDataTableInfo(ATOM_DATA_TABLES AtomDataTable);
    static void PrintAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE AtomPowerplayTable);
    static void PrintAtomPowertuneTableInfo(ATOM_POWERTUNE_TABLE AtomPowertuneTable);
    static void PrintAtomFanTableInfo(ATOM_FAN_TABLE AtomFanTable);
// default
    static void PrintDefaultAtomRomHeaderInfo(ATOM_ROM_HEADER AtomRomHeader);
    static void PrintDefaultAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE AtomPowerplayTable);
    static void PrintDefaultAtomPowertuneTableInfo(ATOM_POWERTUNE_TABLE AtomPowertuneTable);
    static void PrintDefaultAtomFanTableInfo(ATOM_FAN_TABLE AtomFanTable);
    static void PrintDefaultAtomSysClockEntriesInfo(ATOM_SCLK_TABLE AtomSysClockTable, std::vector<ATOM_SCLK_ENTRY> AtomSysClockEntries, std::vector<ATOM_VOLTAGE_ENTRY> AtomVoltageEntries);
    static void PrintDefaultAtomMemClockEntriesInfo(ATOM_MCLK_TABLE AtomMemClockTable, std::vector<ATOM_MCLK_ENTRY> AtomMemClockEntries);
    static void PrintDefaultAtomVramInfo(ATOM_VRAM_INFO AtomVramInfo, std::vector<ATOM_VRAM_ENTRY> AtomVramEntries);
    static void PrintDefaultAtomVramEntriesInfo(ATOM_VRAM_INFO AtomVramInfo, std::vector<ATOM_VRAM_ENTRY> AtomVramEntries);
    static void PrintDefaultAtomVramTimingEntriesInfo(std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramEntries);
// misc
    static void PrintFileSizeWarning(int Filesize);
    static void PrintBiosWarning();
    static void PrintFileDetails(const char* Filename, int Filesize);
    static void PrintDeviceValidation(std::vector<WORD> SupportedDeviceIDs, WORD DeviceId);
    static void PrintAttributes();

};
