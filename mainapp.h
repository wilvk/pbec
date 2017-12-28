#pragma once

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

class MainApp
{

private:

	std::vector<WORD> supportedDeviceIDs = {0x67DF, 0x1002};
	std::wstring deviceID = L"";

	int atom_rom_checksum_offset = 0x21;
	int atom_rom_header_offset = 0;
	ATOM_ROM_HEADER atom_rom_header;
	ATOM_DATA_TABLES atom_data_table;

	int atom_powerplay_offset = 0;
	ATOM_POWERPLAY_TABLE atom_powerplay_table;

	int atom_data_table_offset = 0;

	int atom_powertune_offset = 0;
	ATOM_POWERTUNE_TABLE atom_powertune_table;

	int atom_fan_offset = 0;
	ATOM_FAN_TABLE atom_fan_table;

	int atom_mclk_table_offset = 0;
	ATOM_MCLK_TABLE atom_mclk_table;
	std::vector<ATOM_MCLK_ENTRY> atom_mclk_entries;

	int atom_sclk_table_offset = 0;
	ATOM_SCLK_TABLE atom_sclk_table;
	std::vector<ATOM_SCLK_ENTRY> atom_sclk_entries;

	int atom_vddc_table_offset = 0;
	ATOM_VOLTAGE_TABLE atom_vddc_table;
	std::vector<ATOM_VOLTAGE_ENTRY> atom_vddc_entries;

	int atom_vram_info_offset = 0;
	ATOM_VRAM_INFO atom_vram_info;
	std::vector<ATOM_VRAM_ENTRY> atom_vram_entries;
	std::vector<ATOM_VRAM_TIMING_ENTRY> atom_vram_timing_entries;
	int atom_vram_index = 0;

	bool setValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency = false);

	void printFileSizeWarning(int fileSize);

	void printFileDetails(const char* filename, Buffer* buffer);

	void validateDeviceId(std::vector<WORD> supportedDeviceIDs, WORD deviceId);

public:

	void OpenFile(const char* Filename);

	void updateVRAM_entries();

	MainApp();

	virtual ~MainApp() { /* delete int32; */ }

	void setBytesAtPosition(std::vector<BYTE> &dest, int ptr, std::vector<BYTE> &src);

	int getValueAtPosition(int bits, int position, bool isFrequency = false);

	bool setValueAtPosition(int value, int bits, int position, bool isFrequency = false);

	bool ContainsMatch(std::vector<std::string> list, std::string toMatch);

};
