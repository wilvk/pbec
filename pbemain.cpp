
#include "pbemain.h"

// converts from a struct to bytes
std::vector<unsigned char> MainWindow::getBytes(void *obj)
{
		int size = sizeof(obj);
		unsigned char* buffer = reinterpret_cast<unsigned char*>(&obj);
		std::vector<unsigned char> arr(buffer, buffer + size);

	return arr;
}

// converts from bytes to a struct
template<typename T>
T MainWindow::fromBytes(std::vector<unsigned char> &arr)
{
	T obj = T();
	//int size = sizeof(obj);
	//void* ptr = malloc(size);

	//Marshal::Copy(arr, 0, ptr, size);
	obj = static_cast<T>(arr);
	//free(ptr);

	return obj;
}

// template<typename T>
// std::wstring MainWindow::GetPropertyName(Expression<std::function<T()>*> *propertyLambda)
// {
// 	auto me = dynamic_cast<MemberExpression*>(propertyLambda->Body);
//
// 	if (me == nullptr)
// 	{
// //C# TO C++ CONVERTER TODO TASK: This exception's constructor requires an argument:
// //ORIGINAL LINE: throw new ArgumentException();
// 		throw std::invalid_argument();
// 	}
// 	return me->Member->Name;
// }

void MainWindow::setBytesAtPosition(std::vector<unsigned char> &dest, int ptr, std::vector<unsigned char> &src)
{
	for (int i = 0; i < src.size(); i++)
	{
		dest[ptr + i] = src[i];
	}
}

MainWindow::MainWindow()
{
	// save->IsEnabled = false;
	// boxROM->IsEnabled = false;
	// boxPOWERPLAY->IsEnabled = false;
	// boxPOWERTUNE->IsEnabled = false;
	// boxFAN->IsEnabled = false;
	// boxGPU->IsEnabled = false;
	// boxMEM->IsEnabled = false;
	// boxVRAM->IsEnabled = false;

	std::cout << "Modifying your BIOS is dangerous and could cause irreversible damage to your GPU.\n"
			"Using a modified BIOS may void your warranty.\nThe author will not be held accountable for your actions.";
}

// from click dialog
void MainWindow::OpenFile(std::string FileName)
{
		// tableROM::Items->Clear();
		// tablePOWERPLAY::Items->Clear();
		// tablePOWERTUNE::Items->Clear();
		// tableFAN::Items->Clear();
		// tableGPU::Items->Clear();
		// tableMEMORY::Items->Clear();
		// tableVRAM::Items->Clear();
		// tableVRAM_TIMING::Items->Clear();

		std::ifstream file(FileName, std::ios::binary | std::ios::ate);
		std::streamsize fileSize = file.tellg();
		file.seekg(0, std::ios::beg);

		std::vector<char> buffer(fileSize);
		file.read(buffer.data(), fileSize);

		if (fileSize < 524288)
		{
			std::cout << "Warning: This BIOS is less than the standard 512KB size.\nFlashing this BIOS may corrupt your graphics card.";
		}

			int atom_rom_header_offset = getValueAtPosition(16, atom_rom_header_ptr);
			ATOM_ROM_HEADER atom_rom_header = fromBytes<ATOM_ROM_HEADER>(buffer.Skip(atom_rom_header_offset)->ToArray());

			deviceID = atom_rom_header.usDeviceID.ToString(L"X");
			fixChecksum(false);

			if (!supportedDeviceID.Contains(deviceID))
			{
				// TODO: user check
				std::cout << "WARNING: Unsupported DeviceID 0x" + deviceID;
			}

			atom_data_table = fromBytes<ATOM_DATA_TABLES>(buffer.Skip(atom_rom_header.usMasterDataTableOffset)->ToArray());
			atom_powerplay_offset = atom_data_table.PowerPlayInfo;
			atom_powerplay_table = fromBytes<ATOM_POWERPLAY_TABLE>(buffer.Skip(atom_powerplay_offset)->ToArray());

			atom_powertune_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset;
			atom_powertune_table = fromBytes<ATOM_POWERTUNE_TABLE>(buffer.Skip(atom_powertune_offset)->ToArray());

			atom_fan_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset;
			atom_fan_table = fromBytes<ATOM_FAN_TABLE>(buffer.Skip(atom_fan_offset)->ToArray());

			atom_mclk_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usMclkDependencyTableOffset;
			atom_mclk_table = fromBytes<ATOM_MCLK_TABLE>(buffer.Skip(atom_mclk_table_offset)->ToArray());
			atom_mclk_entries = std::vector<ATOM_MCLK_ENTRY>(atom_mclk_table.ucNumEntries);

			for (int i = 0; i < atom_mclk_entries.size(); i++)
			{
				atom_mclk_entries[i] = fromBytes<ATOM_MCLK_ENTRY>(buffer.Skip(atom_mclk_table_offset + sizeof(ATOM_MCLK_TABLE::typeid) + sizeof(ATOM_MCLK_ENTRY::typeid)*i)->ToArray());
			}

			atom_sclk_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usSclkDependencyTableOffset;
			atom_sclk_table = fromBytes<ATOM_SCLK_TABLE>(buffer.Skip(atom_sclk_table_offset)->ToArray());
			atom_sclk_entries = std::vector<ATOM_SCLK_ENTRY>(atom_sclk_table.ucNumEntries);

			for (int i = 0; i < atom_sclk_entries.size(); i++)
			{
				atom_sclk_entries[i] = fromBytes<ATOM_SCLK_ENTRY>(buffer.Skip(atom_sclk_table_offset + sizeof(ATOM_SCLK_TABLE::typeid) + sizeof(ATOM_SCLK_ENTRY::typeid)*i)->ToArray());
			}

			atom_vddc_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usVddcLookupTableOffset;
			atom_vddc_table = fromBytes<ATOM_VOLTAGE_TABLE>(buffer.Skip(atom_vddc_table_offset)->ToArray());
			atom_vddc_entries = std::vector<ATOM_VOLTAGE_ENTRY>(atom_vddc_table.ucNumEntries);

			for (int i = 0; i < atom_vddc_table.ucNumEntries; i++)
			{
				atom_vddc_entries[i] = fromBytes<ATOM_VOLTAGE_ENTRY>(buffer.Skip(atom_vddc_table_offset + sizeof(ATOM_VOLTAGE_TABLE::typeid) + sizeof(ATOM_VOLTAGE_ENTRY::typeid)*i)->ToArray());
			}

			atom_vram_info_offset = atom_data_table.VRAM_Info;
			atom_vram_info = fromBytes<ATOM_VRAM_INFO>(buffer.Skip(atom_vram_info_offset)->ToArray());
			atom_vram_entries = std::vector<ATOM_VRAM_ENTRY>(atom_vram_info.ucNumOfVRAMModule);
			auto atom_vram_entry_offset = atom_vram_info_offset + sizeof(ATOM_VRAM_INFO::typeid);

			for (int i = 0; i < atom_vram_info.ucNumOfVRAMModule; i++)
			{
				atom_vram_entries[i] = fromBytes<ATOM_VRAM_ENTRY>(buffer.Skip(atom_vram_entry_offset)->ToArray());
				atom_vram_entry_offset += atom_vram_entries[i].usModuleSize;
			}
			atom_vram_timing_entries = std::vector<ATOM_VRAM_TIMING_ENTRY>(16);

			for (int i = 0; i < 16; i++)
			{
				atom_vram_timing_entries[i] = fromBytes<ATOM_VRAM_TIMING_ENTRY>(buffer.Skip(atom_vram_entry_offset + 0x3D + sizeof(ATOM_VRAM_TIMING_ENTRY::typeid)*i)->ToArray());

				// atom_vram_timing_entries have an undetermined length
				// attempt to determine the last entry in the array
				if (atom_vram_timing_entries[i].ulClkRange == 0)
				{
					Array::Resize(atom_vram_timing_entries, i);
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

		delete fileStream;
		delete br;
}

int MainWindow::getValueAtPosition(int bits, int position, bool isFrequency)
{
	int value = 0;
	if (position <= buffer.size() - 4)
	{
		switch (bits)
		{
			case 8:
			default:
				value = buffer[position];
				break;
			case 16:
				value = (buffer[position + 1] << 8) | buffer[position];
				break;
			case 24:
				value = (buffer[position + 2] << 16) | (buffer[position + 1] << 8) | buffer[position];
				break;
			case 32:
				value = (buffer[position + 3] << 24) | (buffer[position + 2] << 16) | (buffer[position + 1] << 8) | buffer[position];
				break;
		}
		if (isFrequency)
		{
			return value / 100;
		}
		return value;
	}
	return -1;
}

bool MainWindow::setValueAtPosition(int value, int bits, int position, bool isFrequency)
{
	if (isFrequency)
	{
		value *= 100;
	}
	if (position <= buffer.size() - 4)
	{
		switch (bits)
		{
			case 8:
			default:
				buffer[position] = static_cast<unsigned char>(value);
				break;
			case 16:
				buffer[position] = static_cast<unsigned char>(value);
				buffer[position + 1] = static_cast<unsigned char>(value >> 8);
				break;
			case 24:
				buffer[position] = static_cast<unsigned char>(value);
				buffer[position + 1] = static_cast<unsigned char>(value >> 8);
				buffer[position + 2] = static_cast<unsigned char>(value >> 16);
				break;
			case 32:
				buffer[position] = static_cast<unsigned char>(value);
				buffer[position + 1] = static_cast<unsigned char>(value >> 8);
				buffer[position + 2] = static_cast<unsigned char>(value >> 16);
				buffer[position + 3] = static_cast<unsigned char>(value >> 32);
				break;
		}
		return true;
	}
	return false;
}

bool MainWindow::setValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency)
{
	int value = 0;
	if (!int::TryParse(text, value))
	{
		return false;
	}
	return setValueAtPosition(value, bits, position, isFrequency);
}

//TODO: just focus on reading the file to begin with
// void MainWindow::SaveFileDialog_Click(void *sender, RoutedEventArgs *e)
// {
// 		FileStream *fs = new FileStream(SaveFileDialog->FileName, FileMode::Create);
// 		BinaryWriter *bw = new BinaryWriter(fs);
//
// 		for (int i = 0; i < tableROM::Items->Count; i++)
// 		{
// 			auto container = dynamic_cast<FrameworkElement*>(tableROM::ItemContainerGenerator->ContainerFromIndex(i));
// 			auto name = (dynamic_cast<TextBlock*>(FindByName(L"NAME", container)))->Text;
// 			auto value = (dynamic_cast<TextBox*>(FindByName(L"VALUE", container)))->Text;
// 			auto num = atoi( value.c_str() );
//
// 			if (name == L"VendorID")
// 			{
// 				atom_rom_header.usVendorID = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"DeviceID")
// 			{
// 				atom_rom_header.usDeviceID = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Sub ID")
// 			{
// 				atom_rom_header.usSubsystemID = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Sub VendorID")
// 			{
// 				atom_rom_header.usSubsystemVendorID = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Firmware Signature")
// 			{
// 				atom_rom_header.uaFirmWareSignature = static_cast<unsigned int>(num);
// 			}
// 		}
//
// 		for (int i = 0; i < tablePOWERPLAY::Items->Count; i++)
// 		{
// 			auto container = dynamic_cast<FrameworkElement*>(tablePOWERPLAY::ItemContainerGenerator->ContainerFromIndex(i));
// 			auto name = (dynamic_cast<TextBlock*>(FindByName(L"NAME", container)))->Text;
// 			auto value = (dynamic_cast<TextBox*>(FindByName(L"VALUE", container)))->Text;
// 			auto num = atoi( value.c_str() );
//
// 			if (name == L"Max GPU Freq. (MHz)")
// 			{
// 				atom_powerplay_table.ulMaxODEngineClock = static_cast<unsigned int>(num * 100);
// 			}
// 			else if (name == L"Max Memory Freq. (MHz)")
// 			{
// 				atom_powerplay_table.ulMaxODMemoryClock = static_cast<unsigned int>(num * 100);
// 			}
// 			else if (name == L"Power Control Limit (%)")
// 			{
// 				atom_powerplay_table.usPowerControlLimit = static_cast<unsigned short>(num);
// 			}
// 		}
//
// 		for (int i = 0; i < tablePOWERTUNE::Items->Count; i++)
// 		{
// 			auto container = dynamic_cast<FrameworkElement*>(tablePOWERTUNE::ItemContainerGenerator->ContainerFromIndex(i));
// 			auto name = (dynamic_cast<TextBlock*>(FindByName(L"NAME", container)))->Text;
// 			auto value = (dynamic_cast<TextBox*>(FindByName(L"VALUE", container)))->Text;
// 			auto num = atoi( value.c_str() );
//
// 			if (name == L"TDP (W)")
// 			{
// 				atom_powertune_table.usTDP = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"TDC (A)")
// 			{
// 				atom_powertune_table.usTDC = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Max Power Limit (W)")
// 			{
// 				atom_powertune_table.usMaximumPowerDeliveryLimit = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Max Temp. (C)")
// 			{
// 				atom_powertune_table.usTjMax = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Shutdown Temp. (C)")
// 			{
// 				atom_powertune_table.usSoftwareShutdownTemp = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Hotspot Temp. (C)")
// 			{
// 				atom_powertune_table.usTemperatureLimitHotspot = static_cast<unsigned short>(num);
// 			}
// 		}
//
// 		for (int i = 0; i < tableFAN::Items->Count; i++)
// 		{
// 			auto container = dynamic_cast<FrameworkElement*>(tableFAN::ItemContainerGenerator->ContainerFromIndex(i));
// 			auto name = (dynamic_cast<TextBlock*>(FindByName(L"NAME", container)))->Text;
// 			auto value = (dynamic_cast<TextBox*>(FindByName(L"VALUE", container)))->Text;
// 			auto num = atoi( value.c_str() );
//
// 			if (name == L"Temp. Hysteresis")
// 			{
// 				atom_fan_table.ucTHyst = static_cast<unsigned char>(num);
// 			}
// 			else if (name == L"Min Temp. (C)")
// 			{
// 				atom_fan_table.usTMin = static_cast<unsigned short>(num * 100);
// 			}
// 			else if (name == L"Med Temp. (C)")
// 			{
// 				atom_fan_table.usTMed = static_cast<unsigned short>(num * 100);
// 			}
// 			else if (name == L"High Temp. (C)")
// 			{
// 				atom_fan_table.usTHigh = static_cast<unsigned short>(num * 100);
// 			}
// 			else if (name == L"Max Temp. (C)")
// 			{
// 				atom_fan_table.usTMax = static_cast<unsigned short>(num * 100);
// 			}
// 			else if (name == L"Min PWM (%)")
// 			{
// 				atom_fan_table.usPWMMin = static_cast<unsigned short>(num * 100);
// 			}
// 			else if (name == L"Med PWM (%)")
// 			{
// 				atom_fan_table.usPWMMed = static_cast<unsigned short>(num * 100);
// 			}
// 			else if (name == L"High PWM (%)")
// 			{
// 				atom_fan_table.usPWMHigh = static_cast<unsigned short>(num * 100);
// 			}
// 			else if (name == L"Max PWM (%)")
// 			{
// 				atom_fan_table.usFanPWMMax = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Max RPM")
// 			{
// 				atom_fan_table.usFanRPMMax = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Sensitivity")
// 			{
// 				atom_fan_table.usFanOutputSensitivity = static_cast<unsigned short>(num);
// 			}
// 			else if (name == L"Acoustic Limit (MHz)")
// 			{
// 				atom_fan_table.ulMinFanSCLKAcousticLimit = static_cast<unsigned int>(num * 100);
// 			}
// 		}
//
// 		for (int i = 0; i < tableGPU::Items->Count; i++)
// 		{
// 			auto container = dynamic_cast<FrameworkElement*>(tableGPU::ItemContainerGenerator->ContainerFromIndex(i));
//
// 			//TODO:  auto mhz = static_cast<int>(int32->ConvertFromString((static_cast<TextBox*>(FindByName(L"MHZ", container)))->Text)) * 100;
// 			//TODO: auto mv = static_cast<int>(int32->ConvertFromString((static_cast<TextBox*>(FindByName(L"MV", container)))->Text));
//
// 			atom_sclk_entries[i].ulSclk = static_cast<unsigned int>(mhz);
// 			atom_vddc_entries[atom_sclk_entries[i].ucVddInd].usVdd = static_cast<unsigned short>(mv);
// 			if (mv < 0xFF00)
// 			{
// 				atom_sclk_entries[i].usVddcOffset = 0;
// 			}
// 		}
//
// 		for (int i = 0; i < tableMEMORY::Items->Count; i++)
// 		{
// 			auto container = dynamic_cast<FrameworkElement*>(tableMEMORY::ItemContainerGenerator->ContainerFromIndex(i));
// 			//TODO: auto mhz = static_cast<int>(int32->ConvertFromString((static_cast<TextBox*>(FindByName(L"MHZ", container)))->Text)) * 100;
// 			//TODO: auto mv = static_cast<int>(int32->ConvertFromString((static_cast<TextBox*>(FindByName(L"MV", container)))->Text));
//
// 			atom_mclk_entries[i].ulMclk = static_cast<unsigned int>(mhz);
// 			atom_mclk_entries[i].usMvdd = static_cast<unsigned short>(mv);
// 		}
//
// 		updateVRAM_entries();
// 		for (int i = 0; i < tableVRAM_TIMING::Items->Count; i++)
// 		{
// 			auto container = dynamic_cast<FrameworkElement*>(tableVRAM_TIMING::ItemContainerGenerator->ContainerFromIndex(i));
// 			auto name = (dynamic_cast<TextBlock*>(FindByName(L"MHZ", container)))->Text;
// 			auto value = (dynamic_cast<TextBox*>(FindByName(L"VALUE", container)))->Text;
// 			auto mhz = atoi( name.c_str() ); * 100;
// 			auto arr = StringToByteArray(value);
//
// 			atom_vram_timing_entries[i].ulClkRange = static_cast<unsigned int>(mhz);
// 			atom_vram_timing_entries[i].ucLatency = arr;
// 		}
//
// 		setBytesAtPosition(buffer, atom_rom_header_offset, getBytes(atom_rom_header));
// 		setBytesAtPosition(buffer, atom_powerplay_offset, getBytes(atom_powerplay_table));
// 		setBytesAtPosition(buffer, atom_powertune_offset, getBytes(atom_powertune_table));
// 		setBytesAtPosition(buffer, atom_fan_offset, getBytes(atom_fan_table));
//
// 		for (int i = 0; i < atom_mclk_table.ucNumEntries; i++)
// 		{
// 			setBytesAtPosition(buffer, atom_mclk_table_offset + sizeof(ATOM_MCLK_TABLE::typeid) + sizeof(ATOM_MCLK_ENTRY::typeid)*i, getBytes(atom_mclk_entries[i]));
// 		}
//
// 		for (int i = 0; i < atom_sclk_table.ucNumEntries; i++)
// 		{
// 			setBytesAtPosition(buffer, atom_sclk_table_offset + sizeof(ATOM_SCLK_TABLE::typeid) + sizeof(ATOM_SCLK_ENTRY::typeid)*i, getBytes(atom_sclk_entries[i]));
// 		}
//
// 		for (int i = 0; i < atom_vddc_table.ucNumEntries; i++)
// 		{
// 			setBytesAtPosition(buffer, atom_vddc_table_offset + sizeof(ATOM_VOLTAGE_TABLE::typeid) + sizeof(ATOM_VOLTAGE_ENTRY::typeid)*i, getBytes(atom_vddc_entries[i]));
// 		}
//
// 		auto atom_vram_entry_offset = atom_vram_info_offset + sizeof(ATOM_VRAM_INFO::typeid);
// 		for (int i = 0; i < atom_vram_info.ucNumOfVRAMModule; i++)
// 		{
// 			setBytesAtPosition(buffer, atom_vram_entry_offset, getBytes(atom_vram_entries[i]));
// 			atom_vram_entry_offset += atom_vram_entries[i].usModuleSize;
// 		}
// 		for (int i = 0; i < atom_vram_timing_entries.size(); i++)
// 		{
// 			setBytesAtPosition(buffer, atom_vram_entry_offset + 0x3D + sizeof(ATOM_VRAM_TIMING_ENTRY::typeid)*i, getBytes(atom_vram_timing_entries[i]));
// 		}
//
// 		fixChecksum(true);
// 		bw->Write(buffer);
//
// 		fs->Close();
// 		bw->Close();
// 	}
// }

void MainWindow::fixChecksum(bool save)
{
	unsigned char checksum = buffer[atom_rom_checksum_offset];
	int size = buffer[0x02]*512;
	unsigned char offset = 0;

	for (int i = 0; i < size; i++)
	{
		offset += buffer[i];
	}
	if (checksum == (buffer[atom_rom_checksum_offset] - offset))
	{
		txtChecksum->Foreground = Brushes::Green;
	}
	else if (!save)
	{
		txtChecksum->Foreground = Brushes::Red;
		MessageBox::Show(L"Invalid checksum - Save to fix!", L"WARNING", MessageBoxButton::OK, MessageBoxImage::Warning);
	}
	if (save)
	{
		buffer[atom_rom_checksum_offset] -= offset;
		txtChecksum->Foreground = Brushes::Green;
	}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
	txtChecksum->Text = L"0x" + buffer[atom_rom_checksum_offset].ToString(L"X");
}

FrameworkElement *MainWindow::FindByName(const std::wstring &name, FrameworkElement *root)
{
	std::stack<FrameworkElement*> tree;
	tree.push(root);

	while (tree.size() > 0)
	{
		FrameworkElement *current = tree.pop();
		if (current->Name == name)
		{
			return current;
		}

		int count = VisualTreeHelper::GetChildrenCount(current);
		for (int i = 0; i < count; ++i)
		{
			DependencyObject *child = VisualTreeHelper::GetChild(current, i);
			if (dynamic_cast<FrameworkElement*>(child) != nullptr)
			{
				tree.push(static_cast<FrameworkElement*>(child));
			}
		}
	}

	return nullptr;
}

std::wstring MainWindow::ByteArrayToString(std::vector<unsigned char> &ba)
{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
	std::wstring hex = BitConverter::ToString(ba);
	return boost::replace_all_copy(hex, L"-", L"");
}

std::vector<unsigned char> MainWindow::StringToByteArray(const std::wstring &hex)
{
	if (hex.length() % 2 != 0)
	{
		MessageBox::Show(L"Invalid hex string", L"Error", MessageBoxButton::OK, MessageBoxImage::Error);
		throw InvalidDataException();
	}
	std::vector<unsigned char> bytes(hex.length() / 2);
	for (int i = 0; i < hex.length(); i += 2)
	{
		bytes[i / 2] = Convert::ToByte(hex.substr(i, 2), 16);
	}
	return bytes;
}

void MainWindow::updateVRAM_entries()
{
	for (int i = 0; i < tableVRAM::Items->Count; i++)
	{
		auto container = dynamic_cast<FrameworkElement*>(tableVRAM::ItemContainerGenerator->ContainerFromIndex(i));
		auto name = (dynamic_cast<TextBlock*>(FindByName(L"NAME", container)))->Text;
		auto value = (dynamic_cast<TextBox*>(FindByName(L"VALUE", container)))->Text;
		auto num = static_cast<int>(int32->ConvertFromString(value));

		if (name == L"VendorID")
		{
			atom_vram_entries[atom_vram_index].ucMemoryVenderID = static_cast<unsigned char>(num);
		}
		else if (name == L"Size (MB)")
		{
			atom_vram_entries[atom_vram_index].usMemorySize = static_cast<unsigned short>(num);
		}
		else if (name == L"Density")
		{
			atom_vram_entries[atom_vram_index].ucDensity = static_cast<unsigned char>(num);
		}
		else if (name == L"Type")
		{
			atom_vram_entries[atom_vram_index].ucMemoryType = static_cast<unsigned char>(num);
		}
	}
}

// void MainWindow::listVRAM_SelectionChanged(void *sender, SelectionChangedEventArgs *e)
// {
// 	updateVRAM_entries();
// 	tableVRAM::Items->Clear();
// 	if (listVRAM::SelectedIndex >= 0 && listVRAM::SelectedIndex < listVRAM::Items->Count)
// 	{
// 		atom_vram_index = listVRAM::SelectedIndex;
// //C# TO C++ CONVERTER TODO TASK: This type of object initializer has no direct C++ equivalent:
// //C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
// 		tableVRAM::Items->Add(new {NAME = L"VendorID", VALUE = L"0x" + atom_vram_entries[atom_vram_index].ucMemoryVenderID.ToString(L"X")});
// //C# TO C++ CONVERTER TODO TASK: This type of object initializer has no direct C++ equivalent:
// 		tableVRAM::Items->Add(new {NAME = L"Size (MB)", VALUE = atom_vram_entries[atom_vram_index].usMemorySize});
// //C# TO C++ CONVERTER TODO TASK: This type of object initializer has no direct C++ equivalent:
// //C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
// 		tableVRAM::Items->Add(new {NAME = L"Density", VALUE = L"0x" + atom_vram_entries[atom_vram_index].ucDensity.ToString(L"X")});
// //C# TO C++ CONVERTER TODO TASK: This type of object initializer has no direct C++ equivalent:
// //C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
// 		tableVRAM::Items->Add(new {NAME = L"Type", VALUE = L"0x" + atom_vram_entries[atom_vram_index].ucMemoryType.ToString(L"X")});
// 	}
}
