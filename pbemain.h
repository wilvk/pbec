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

#include "exceptionhelper.h"
#include "structs.h"
#include "buffer.h"

class MainWindow
{

private:

	std::vector<WORD> supportedDeviceIDs = {0x67DF, 0x1002};
	std::wstring deviceID = L"";

	int atom_rom_checksum_offset = 0x21;
	int atom_rom_header_ptr = 0x48;
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

	//void SaveFileDialog_Click(void *sender, RoutedEventArgs *e);

	void fixChecksum(bool save);

	static std::vector<BYTE> getBytes(void *obj);

	template<typename T> static T fromBytes(std::vector<BYTE> &arr);

	//FrameworkElement *FindByName(const std::wstring &name, FrameworkElement *root);

	//void listVRAM_SelectionChanged(void *sender, SelectionChangedEventArgs *e);

	void printFileSizeWarning(int fileSize);

	void printFileDetails(const char* filename, Buffer* buffer);

	void validateDeviceId(std::vector<WORD> supportedDeviceIDs, WORD deviceId);

	std::string convertIntToHexString(WORD* data, int len);

public:

	void OpenFile(const char* Filename);

	static std::wstring ByteArrayToString(std::vector<BYTE> &ba);

	static std::vector<BYTE> StringToByteArray(const std::wstring &hex);

	void updateVRAM_entries();

	MainWindow();

	virtual ~MainWindow() { /* delete int32; */ }

	//template<typename T> std::wstring GetPropertyName(Expression<std::function<T()>*> *propertyLambda);

	void setBytesAtPosition(std::vector<BYTE> &dest, int ptr, std::vector<BYTE> &src);

	int getValueAtPosition(int bits, int position, bool isFrequency = false);

	bool setValueAtPosition(int value, int bits, int position, bool isFrequency = false);

	bool ContainsMatch(std::vector<std::string> list, std::string toMatch);

};
