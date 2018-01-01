﻿#pragma once

#include <string>
#include <vector>
#include <stack>
#include <stdexcept>
#include <functional>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <cstdint>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include "byteutils.h"
#include "structs.h"
#include "retrievestruct.h"
#include "exceptionhelper.h"
#include "buffer.h"
#include "console.h"

class MainApp
{

private:

	std::vector<BYTE> bufferSubset;
	RetrieveStruct* retriever;
	Buffer *buffer;

	std::vector<WORD> supportedDeviceIDs = {0x67DF, 0x1002};

	bool printDebug = false;
	bool printInfo = true;

	const int AtomRomChecksumOffset = 0x21;

	int atom_vram_info_offset;
	int atom_sclk_table_offset;
	int AtomPowertuneOffset;
	int AtomFanTableOffset;
	int AtomSysClockEntriesOffset;
	int AtomMemClockTableOffset;
	int atomVoltageTableOffset;
	int AtomVramEntryOffset;

	ATOM_ROM_HEADER atom_rom_header;
	ATOM_DATA_TABLES atom_data_table;
	ATOM_POWERPLAY_TABLE atom_powerplay_table;
	ATOM_POWERTUNE_TABLE atom_powertune_table;
	ATOM_FAN_TABLE atom_fan_table;
	ATOM_SCLK_TABLE atom_sclk_table;
	std::vector<ATOM_SCLK_ENTRY> atom_sclk_entries;
	ATOM_MCLK_TABLE atom_mclk_table;
	std::vector<ATOM_MCLK_ENTRY> atom_mclk_entries;
	ATOM_VOLTAGE_TABLE atom_vddc_table;
	std::vector<ATOM_VOLTAGE_ENTRY> atom_vddc_entries;
	ATOM_VRAM_INFO atom_vram_info;
	std::vector<ATOM_VRAM_ENTRY> atom_vram_entries;
	std::vector<ATOM_VRAM_TIMING_ENTRY> atom_vram_timing_entries;

	bool setValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency = false);

	void printFileSizeWarning(int fileSize);

	void printFileDetails(const char* filename, Buffer* buffer);

	void validateDeviceId(std::vector<WORD> supportedDeviceIDs, WORD deviceId);

  void getTables();

	void getBootstrapTables();

	void getPowertuneTable();

	void getFanTable();

	void getSysClockEntries();

	void getMemClockEntries();

	void getVoltageEntries();

	void getVramTimingEntries();

	void printDefaultInfo();

	void printDebugInfo();

public:

	void OpenFile(const char* Filename);

	void updateVRAM_entries();

	void setBytesAtPosition(std::vector<BYTE> &dest, int ptr, std::vector<BYTE> &src);

	int getValueAtPosition(int bits, int position, bool isFrequency = false);

	bool setValueAtPosition(int value, int bits, int position, bool isFrequency = false);

	void PrintAtomRomHeaderInfo(ATOM_ROM_HEADER atom_rom_header);

	void PrintAtomDataTableInfo(ATOM_DATA_TABLES atom_data_table);

	void PrintAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE atom_powerplay_table);

};
