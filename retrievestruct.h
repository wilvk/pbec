#pragma once

#include "structs.h"
#include "buffer.h"
#include "byteutils.h"

class RetrieveStruct
{

private:

	int atom_rom_header_ptr = 0x48;
	int atom_data_table_offset = 0;

	template<typename T> T fromBytes(std::vector<BYTE> &StringArray);

public:

	ATOM_ROM_HEADER AtomRomHeader(Buffer* Buffer);

	ATOM_DATA_TABLES AtomDataTables(Buffer* Buffer, int MasterDataTableOffset);

	ATOM_POWERPLAY_TABLE AtomPowerplayTable(Buffer* Buffer, int AtomPowerplayOffset);

	ATOM_POWERTUNE_TABLE AtomPowertuneTable(Buffer* Buffer, int AtomPowertuneOffset);

	ATOM_FAN_TABLE AtomFanTable(Buffer* Buffer, int AtomFanOffset);

	ATOM_MCLK_TABLE AtomMemClockTable(Buffer * Buffer, int AtomMemClockTableOffset);

	std::vector<ATOM_MCLK_ENTRY> AtomMemClockEntries(Buffer* Buffer, int AtomMemClockTableOffset, int NumMemClockTableEntries);

};
