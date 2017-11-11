
#include "pbemain.h"

std::vector<BYTE> MainWindow::getBytes(void *obj)
{
		int size = sizeof(obj);
		BYTE* buffer = reinterpret_cast<BYTE*>(&obj);
		std::vector<BYTE> arr(buffer, buffer + size);

		return arr;
}

template<typename T> T MainWindow::fromBytes(std::vector<BYTE> &arr)
{
		T obj = T();
		obj = reinterpret_cast<T>(arr);

		return obj;
}

void MainWindow::setBytesAtPosition(std::vector<BYTE> &dest, int ptr, std::vector<BYTE> &src)
{
		for (int i = 0; i < src.size(); i++)
		{
			dest[ptr + i] = src[i];
		}
}

MainWindow::MainWindow()
{
		std::cout << "Modifying your BIOS is dangerous and could cause irreversible damage to your GPU.\n"
				"Using a modified BIOS may void your warranty.\nThe author will not be held accountable for your actions.";
}

bool MainWindow::ContainsMatch(std::vector<std::string> list, std::string toMatch)
{
		std::vector<std::string>::const_iterator it;

		it = find (list.begin(), list.end(), 30);

  	if (it != list.end())
		{
			return true;
		}

		return false;
}

void MainWindow::OpenFile(const char* Filename)
{
		Buffer *buffer = new Buffer();
		buffer->ReadFile(Filename);
		std::vector<BYTE> bufferSubset;

		if (buffer->FileData.size() < 524288)
		{
			std::cout << "Warning: This BIOS is less than the standard 512KB size.\nFlashing this BIOS may corrupt your graphics card.";
		}

		int atom_rom_header_offset = buffer->GetValueAtPosition(16, atom_rom_header_ptr, false);

		bufferSubset = buffer->GetSubset(atom_rom_header_offset);

		ATOM_ROM_HEADER atom_rom_header = this->fromBytes<ATOM_ROM_HEADER>(bufferSubset);

		std::string deviceID = int_to_hex( atom_rom_header.usDeviceID );

		buffer->FixChecksum(false);

		if (!this->ContainsMatch(supportedDeviceID, deviceID))
		{
			std::cout << "WARNING: Unsupported DeviceID: " + deviceID;
		}

		atom_data_table_offset = atom_rom_header.usMasterDataTableOffset;
		bufferSubset = buffer->GetSubset(atom_data_table_offset);
		atom_data_table = fromBytes<ATOM_DATA_TABLES>(bufferSubset);

		atom_powerplay_offset = atom_data_table.PowerPlayInfo;
		bufferSubset = buffer->GetSubset(atom_powerplay_offset);
		atom_powerplay_table = fromBytes<ATOM_POWERPLAY_TABLE>(bufferSubset);

		atom_powertune_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset;
		bufferSubset = buffer->GetSubset(atom_powertune_offset);
		atom_powertune_table = fromBytes<ATOM_POWERTUNE_TABLE>(bufferSubset);

		atom_fan_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset;
		bufferSubset = buffer->GetSubset(atom_fan_offset);
		atom_fan_table = fromBytes<ATOM_FAN_TABLE>(bufferSubset);

		atom_mclk_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usMclkDependencyTableOffset;
		bufferSubset = buffer->GetSubset(atom_mclk_table_offset);
		atom_mclk_table = fromBytes<ATOM_MCLK_TABLE>(bufferSubset);

		atom_mclk_entries = std::vector<ATOM_MCLK_ENTRY>(atom_mclk_table.ucNumEntries);

		for (int i = 0; i < atom_mclk_entries.size(); i++)
		{
			int atom_mclk_entry_offset = atom_mclk_table_offset + sizeof(ATOM_MCLK_TABLE) + sizeof(ATOM_MCLK_ENTRY) * i;
			bufferSubset = buffer->GetSubset(atom_mclk_entry_offset);
			atom_mclk_entries[i] = fromBytes<ATOM_MCLK_ENTRY>(bufferSubset);
		}

		atom_sclk_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usSclkDependencyTableOffset;
		bufferSubset = buffer->GetSubset(atom_sclk_table_offset);
		atom_sclk_table = fromBytes<ATOM_SCLK_TABLE>(bufferSubset);
		atom_sclk_entries = std::vector<ATOM_SCLK_ENTRY>(atom_sclk_table.ucNumEntries);

		for (int i = 0; i < atom_sclk_entries.size(); i++)
		{
			int atom_sclk_entry_offset = atom_sclk_table_offset + sizeof(ATOM_SCLK_TABLE) + sizeof(ATOM_SCLK_ENTRY) * i;
			bufferSubset = buffer->GetSubset(atom_sclk_entry_offset);
			atom_sclk_entries[i] = fromBytes<ATOM_SCLK_ENTRY>(bufferSubset);
		}

		atom_vddc_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usVddcLookupTableOffset;
		bufferSubset = buffer->GetSubset(atom_vddc_table_offset);
		atom_vddc_table = fromBytes<ATOM_VOLTAGE_TABLE>(bufferSubset);
		atom_vddc_entries = std::vector<ATOM_VOLTAGE_ENTRY>(atom_vddc_table.ucNumEntries);

		for (int i = 0; i < atom_vddc_table.ucNumEntries; i++)
		{
			int atom_vddc_entry_offset = atom_vddc_table_offset + sizeof(ATOM_VOLTAGE_TABLE) + sizeof(ATOM_VOLTAGE_ENTRY) * i;
			bufferSubset = buffer->GetSubset(atom_vddc_entry_offset);
			atom_vddc_entries[i] = fromBytes<ATOM_VOLTAGE_ENTRY>(bufferSubset);
		}

		atom_vram_info_offset = atom_data_table.VRAM_Info;
		bufferSubset = buffer->GetSubset(atom_vram_info_offset);
		atom_vram_info = fromBytes<ATOM_VRAM_INFO>(bufferSubset);

		atom_vram_entries = std::vector<ATOM_VRAM_ENTRY>(atom_vram_info.ucNumOfVRAMModule);
		int atom_vram_entry_offset = atom_vram_info_offset + sizeof(ATOM_VRAM_INFO);

		for (int i = 0; i < atom_vram_info.ucNumOfVRAMModule; i++)
		{
			bufferSubset = buffer->GetSubset(atom_vram_entry_offset);
			atom_vram_entries[i] = fromBytes<ATOM_VRAM_ENTRY>(bufferSubset);
			atom_vram_entry_offset += atom_vram_entries[i].usModuleSize;
		}

		atom_vram_timing_entries = std::vector<ATOM_VRAM_TIMING_ENTRY>(16);

		for (int i = 0; i < 16; i++)
		{
			int atom_vram_timing_entry_offset = atom_vram_entry_offset + 0x3D + sizeof(ATOM_VRAM_TIMING_ENTRY) * i;
			bufferSubset = buffer->GetSubset(atom_vram_timing_entry_offset);
			atom_vram_timing_entries[i] = fromBytes<ATOM_VRAM_TIMING_ENTRY>(bufferSubset);

			// atom_vram_timing_entries have an undetermined length. Attempt to determine the last entry in the array.
			if (atom_vram_timing_entries[i].ulClkRange == 0)
			{
				atom_vram_timing_entries.resize(i);
				break;
			}

		}

			//TODO: output these to stdout
			// tableROM::Items->Add(new {NAME = L"VendorID", VALUE = L"0x" + atom_rom_header.usVendorID.ToString(L"X")});
			// tableROM::Items->Add(new {NAME = L"DeviceID", VALUE = L"0x" + atom_rom_header.usDeviceID.ToString(L"X")});
			// tableROM::Items->Add(new {NAME = L"Sub ID", VALUE = L"0x" + atom_rom_header.usSubsystemID.ToString(L"X")});
			// tableROM::Items->Add(new {NAME = L"Sub VendorID", VALUE = L"0x" + atom_rom_header.usSubsystemVendorID.ToString(L"X")});
			// tableROM::Items->Add(new {NAME = L"Firmware Signature", VALUE = L"0x" + atom_rom_header.uaFirmWareSignature.ToString(L"X")});
			// tablePOWERPLAY::Items->Add(new {NAME = L"Max GPU Freq. (MHz)", VALUE = atom_powerplay_table.ulMaxODEngineClock / 100});
			// tablePOWERPLAY::Items->Add(new {NAME = L"Max Memory Freq. (MHz)", VALUE = atom_powerplay_table.ulMaxODMemoryClock / 100});
			// tablePOWERPLAY::Items->Add(new {NAME = L"Power Control Limit (%)", VALUE = atom_powerplay_table.usPowerControlLimit});
			// tablePOWERTUNE::Items->Add(new {NAME = L"TDP (W)", VALUE = atom_powertune_table.usTDP});
			// tablePOWERTUNE::Items->Add(new {NAME = L"TDC (A)", VALUE = atom_powertune_table.usTDC});
			// tablePOWERTUNE::Items->Add(new {NAME = L"Max Power Limit (W)", VALUE = atom_powertune_table.usMaximumPowerDeliveryLimit});
			// tablePOWERTUNE::Items->Add(new {NAME = L"Max Temp. (C)", VALUE = atom_powertune_table.usTjMax});
			// tablePOWERTUNE::Items->Add(new {NAME = L"Shutdown Temp. (C)", VALUE = atom_powertune_table.usSoftwareShutdownTemp});
			// tablePOWERTUNE::Items->Add(new {NAME = L"Hotspot Temp. (C)", VALUE = atom_powertune_table.usTemperatureLimitHotspot});
			// tableFAN::Items->Add(new {NAME = L"Temp. Hysteresis", VALUE = atom_fan_table.ucTHyst});
			// tableFAN::Items->Add(new {NAME = L"Min Temp. (C)", VALUE = atom_fan_table.usTMin / 100});
			// tableFAN::Items->Add(new {NAME = L"Med Temp. (C)", VALUE = atom_fan_table.usTMed / 100});
			// tableFAN::Items->Add(new {NAME = L"High Temp. (C)", VALUE = atom_fan_table.usTHigh / 100});
			// tableFAN::Items->Add(new {NAME = L"Max Temp. (C)", VALUE = atom_fan_table.usTMax / 100});
			// tableFAN::Items->Add(new {NAME = L"Min PWM (%)", VALUE = atom_fan_table.usPWMMin / 100});
			// tableFAN::Items->Add(new {NAME = L"Med PWM (%)", VALUE = atom_fan_table.usPWMMed / 100});
			// tableFAN::Items->Add(new {NAME = L"High PWM (%)", VALUE = atom_fan_table.usPWMHigh / 100});
			// tableFAN::Items->Add(new {NAME = L"Max PWM (%)", VALUE = atom_fan_table.usFanPWMMax});
			// tableFAN::Items->Add(new {NAME = L"Max RPM", VALUE = atom_fan_table.usFanRPMMax});
			// tableFAN::Items->Add(new {NAME = L"Sensitivity", VALUE = atom_fan_table.usFanOutputSensitivity});
			// tableFAN::Items->Add(new {NAME = L"Acoustic Limit (MHz)", VALUE = atom_fan_table.ulMinFanSCLKAcousticLimit / 100});

		for (int i = 0; i < atom_sclk_table.ucNumEntries; i++)
		{
			//tableGPU::Items->Add(new {MHZ = atom_sclk_entries[i].ulSclk / 100, MV = atom_vddc_entries[atom_sclk_entries[i].ucVddInd].usVdd});
		}

		for (int i = 0; i < atom_mclk_table.ucNumEntries; i++)
		{
			//tableMEMORY::Items->Add(new {MHZ = atom_mclk_entries[i].ulMclk / 100, MV = atom_mclk_entries[i].usMvdd});
		}

		for (int i = 0; i < atom_vram_info.ucNumOfVRAMModule; i++)
		{
			//listVRAM::Items->Add(Encoding::UTF8->GetString(atom_vram_entries[i].strMemPNString));
		}

			//listVRAM->SelectedIndex = 0;
			//atom_vram_index = listVRAM::SelectedIndex;

		for (int i = 0; i < atom_vram_timing_entries.size(); i++)
		{
			//tableVRAM_TIMING::Items->Add(new {MHZ = atom_vram_timing_entries[i].ulClkRange / 100, VALUE = ByteArrayToString(atom_vram_timing_entries[i].ucLatency)});
		}

		delete buffer;
}

template< typename T >
std::string int_to_hex( T i )
{
	  std::stringstream stream;
	  stream << "0x"
	         << std::setfill ('0') << std::setw(sizeof(T) * 2)
	         << std::hex << i;
	  return stream.str();
}

std::wstring MainWindow::ByteArrayToString(std::vector<BYTE> &ba)
{
		std::wstring hex(ba.begin(), ba.end());
		return boost::replace_all_copy(hex, L"-", L"");
}

std::vector<BYTE> MainWindow::StringToByteArray(const std::wstring &hex)
{
		if (hex.length() % 2 != 0)
		{
			std::cout << "ERROR: Invalid hex string";
			throw InvalidDataException();
		}

		std::vector<BYTE> bytes(hex.length() / 2);

		for (int i = 0; i < hex.length(); i += 2)
		{
			wchar_t singleString = hex.substr(i, 2)[0];
			bytes[i / 2] = singleString;
		}

		return bytes;
}
