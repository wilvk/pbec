#include "pbemain.h"

std::vector<BYTE> MainWindow::getBytes(void *obj)
{
    int size = sizeof(obj);
    BYTE* buffer = reinterpret_cast<BYTE*>(&obj);
    std::vector<BYTE> arr(buffer, buffer + size);

    return arr;
}

template<typename T> T MainWindow::fromBytes(std::vector<BYTE> &stringArray)
{
    T typeObject = T();

    std::memcpy(&typeObject, &stringArray[0], sizeof typeObject);

    return typeObject;
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
    std::cout << "Modifying your BIOS is dangerous and could cause irreversible damage to your GPU." << std::endl <<
        "Using a modified BIOS may void your warranty." << std::endl <<
        "The author will not be held accountable for your actions." << std::endl;
}

bool MainWindow::ContainsMatch(std::vector<std::string> list, std::string toMatch)
{
    bool found = (std::find(list.begin(), list.end(), toMatch) != list.end());

    return found;
}

void MainWindow::printFileSizeWarning(int fileSize)
{
  if (fileSize < 524288)
  {
      std::cout << std::endl << std::endl <<
          "Warning: This BIOS is less than the standard 512KB size." << std::endl <<
          "Flashing this BIOS may corrupt your graphics card." << std::endl;
  }
}

void MainWindow::printFileDetails(const char* filename, Buffer* buffer)
{
  std::cout << "File Name: " << std::endl << filename;
  std::cout << "File size: " << buffer->FileData.size() << " bytes" << std::endl;
}

void MainWindow::OpenFile(const char* Filename)
{
    Buffer *buffer = new Buffer();;
    buffer->ReadFile(Filename);
    std::vector<BYTE> bufferSubset;

    printFileSizeWarning(buffer->FileData.size());

    printFileDetails(Filename, buffer);

    int atom_rom_header_offset = buffer->GetValueAtPosition(16, atom_rom_header_ptr, false);

    bufferSubset = buffer->GetSubset(atom_rom_header_offset);

    ATOM_ROM_HEADER atom_rom_header = this->fromBytes<ATOM_ROM_HEADER>(bufferSubset);

    std::string deviceID = std::to_string(atom_rom_header.usDeviceID);   //int_to_hex( atom_rom_header.usDeviceID );

    buffer->FixChecksum(false, atom_rom_checksum_offset);

    if (!this->ContainsMatch(supportedDeviceID, deviceID))
    {
      std::cout << std::endl << "WARNING: Unsupported DeviceID: " + deviceID;
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

      // atom_vram_timing_entries have an undetermined length.
      // Attempt to determine the last entry in the array.
      if (atom_vram_timing_entries[i].ulClkRange == 0)
      {
        atom_vram_timing_entries.resize(i);
        break;
      }
    }

    std::cout << std::endl << "Vendor ID: " << atom_rom_header.usVendorID;
    std::cout << std::endl << "Device ID: " << atom_rom_header.usDeviceID;
    std::cout << std::endl << "Subsystem ID: " << atom_rom_header.usSubsystemID;
    std::cout << std::endl << "Subsystem Vendor ID: " << atom_rom_header.usSubsystemVendorID;
    std::cout << std::endl << "Firmware Signature: " << atom_rom_header.uaFirmWareSignature;
    std::cout << std::endl << "Max GPU Freq. (MHz): " << atom_powerplay_table.ulMaxODEngineClock / 100;
    std::cout << std::endl << "Max Memory Freq. (MHz): " << atom_powerplay_table.ulMaxODMemoryClock / 100;
    std::cout << std::endl << "Power Control Limit (%): " << atom_powerplay_table.usPowerControlLimit;
    std::cout << std::endl << "TDP (W): " << atom_powertune_table.usTDP;
    std::cout << std::endl << "TDC (A): " << atom_powertune_table.usTDC;
    std::cout << std::endl << "Max Power Limit (W): " << atom_powertune_table.usMaximumPowerDeliveryLimit;
    std::cout << std::endl << "Max Temp. (C): " << atom_powertune_table.usTjMax;
    std::cout << std::endl << "Shutdown Temp. (C): " << atom_powertune_table.usSoftwareShutdownTemp;
    std::cout << std::endl << "Hotspot Temp. (C): " << atom_powertune_table.usTemperatureLimitHotspot;
    std::cout << std::endl << "Temp. Hysteresis: " << atom_fan_table.ucTHyst;
    std::cout << std::endl << "Min Temp. (C): " << atom_fan_table.usTMin / 100;
    std::cout << std::endl << "Med Temp. (C): " << atom_fan_table.usTMed / 100;
    std::cout << std::endl << "High Temp. (C): " << atom_fan_table.usTHigh / 100;
    std::cout << std::endl << "Max Temp. (C): " << atom_fan_table.usTMax / 100;
    std::cout << std::endl << "Min PWM (%): " << atom_fan_table.usPWMMin / 100;
    std::cout << std::endl << "Med PWM (%): " << atom_fan_table.usPWMMed / 100;
    std::cout << std::endl << "High PWM (%): " << atom_fan_table.usPWMHigh / 100;
    std::cout << std::endl << "Max PWM (%): " << atom_fan_table.usFanPWMMax;
    std::cout << std::endl << "Max RPM: " << atom_fan_table.usFanRPMMax;
    std::cout << std::endl << "Sensitivity: " << atom_fan_table.usFanOutputSensitivity;
    std::cout << std::endl << "Acoustic Limit (MHz): " << atom_fan_table.ulMinFanSCLKAcousticLimit / 100;

    for (int i = 0; i < atom_sclk_table.ucNumEntries; i++)
    {
        std::cout << std::endl << "System Clock (" << i << "). MHz " << atom_sclk_entries[i].ulSclk / 100;
				std::cout << std::endl << "System Clock (" << i << "). MV " << atom_vddc_entries[atom_sclk_entries[i].ucVddInd].usVdd;
    }

    for (int i = 0; i < atom_mclk_table.ucNumEntries; i++)
    {
			std::cout << std::endl << "Memory Clock (" << i << "). MHz " << atom_mclk_entries[i].ulMclk / 100;
			std::cout << std::endl << "Memory Clock (" << i << "). MV " << atom_mclk_entries[i].usMvdd;
    }

    for (int i = 0; i < atom_vram_info.ucNumOfVRAMModule; i++)
    {
      std::string vramInfo(reinterpret_cast<char*>(atom_vram_entries[i].strMemPNString));
			std::cout << std::endl << "VRAM Info (" << i << "): " << vramInfo;
    }

    for (int i = 0; i < atom_vram_timing_entries.size(); i++)
    {
      std::cout << std::endl << "VRAM Timing (" << i << ") (MHz): " << atom_vram_timing_entries[i].ulClkRange / 100;
      std::string vramTimingInfo(reinterpret_cast<char*>(atom_vram_timing_entries[i].ucLatency));
      std::cout << std::endl << "VRAM Timing Info (" << i << "): " << vramTimingInfo;
    }

    delete buffer;
}

template< typename T >
std::string MainWindow::int_to_hex( T i )
{
    char res[5];

    if( i <= 0xFFFF )
    {
        return sprintf(&res[0], "%04x", i);
    }

    return "0x00";
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
