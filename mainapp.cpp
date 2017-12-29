#include "mainapp.h"


MainApp::MainApp()
{
    std::cout << "Modifying your BIOS is dangerous and could cause irreversible damage to your GPU." << std::endl <<
        "Using a modified BIOS may void your warranty." << std::endl <<
        "The author will not be held accountable for your actions." << std::endl;
}

bool MainApp::ContainsMatch(std::vector<std::string> list, std::string toMatch)
{
    bool found = (std::find(list.begin(), list.end(), toMatch) != list.end());

    return found;
}

void MainApp::printFileSizeWarning(int fileSize)
{
  if (fileSize < 524288)
  {
      std::cout << std::endl << std::endl <<
          "Warning: This BIOS is less than the standard 512KB size." << std::endl <<
          "Flashing this BIOS may corrupt your graphics card." << std::endl;
  }
}

void MainApp::printFileDetails(const char* filename, Buffer* buffer)
{
  std::cout << std::endl << "File Name: " << filename;
  std::cout << std::endl << "File size: " << buffer->FileData.size() << " bytes" << std::endl;
}

void MainApp::validateDeviceId(std::vector<WORD> supportedDeviceIDs, WORD deviceId)
{
  bool exists = std::find(std::begin(supportedDeviceIDs), std::end(supportedDeviceIDs), deviceId) != std::end(supportedDeviceIDs);

  std::string deviceIdString = ByteUtils::ConvertIntToHexString(&deviceId, 1);

  if(!exists)
  {
    std::cout << std::endl << "WARNING: Unsupported DeviceID: " << deviceIdString;
  }
  else
  {
    std::cout << std::endl << "DeviceId is valid:" << deviceIdString;
  }
}

void MainApp::OpenFile(const char* Filename)
{
    Buffer *buffer = new Buffer();;
    buffer->ReadFile(Filename);
    std::vector<BYTE> bufferSubset;
    RetrieveStruct* retriever = new RetrieveStruct();

    printFileSizeWarning(buffer->FileData.size());
    printFileDetails(Filename, buffer);

    atom_rom_header = retriever->AtomRomHeader(buffer);

    int zeroOffset = 0;
    bufferSubset = buffer->GetSubset(zeroOffset);

    buffer->FixChecksum(false, atom_rom_checksum_offset);

    validateDeviceId(supportedDeviceIDs, atom_rom_header.usDeviceID);

    atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
    atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
    atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
    atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));
    atom_mclk_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usMclkDependencyTableOffset;
    atom_mclk_table = retriever->AtomMemClockTable(buffer, atom_mclk_table_offset);
    atom_mclk_entries = retriever->AtomMemClockEntries(buffer, atom_mclk_table_offset, atom_mclk_table.ucNumEntries);
    atom_sclk_table = retriever->AtomSysClockTable(buffer, atom_data_table.PowerPlayInfo + atom_powerplay_table.usSclkDependencyTableOffset);
    atom_sclk_entries = retriever->AtomSysClockEntries(buffer, atom_sclk_table_offset, atom_sclk_table.ucNumEntries);
    atom_vddc_table = retriever->AtomVoltageTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usVddcLookupTableOffset));
    atom_vddc_entries = retriever->AtomVoltageEntries(buffer, atom_vddc_table_offset, atom_vddc_table.ucNumEntries);
    atom_vram_info = retriever->AtomVramInfo(buffer, atom_data_table.VRAM_Info);

    AtomVramEntryOffset = atom_vram_info_offset + sizeof(ATOM_VRAM_INFO);
    atom_vram_entries = retriever->AtomVramEntries(buffer, atom_vram_info.ucNumOfVRAMModule, AtomVramEntryOffset);

    atom_vram_timing_entries = retriever->AtomVramTimingEntries(buffer, AtomVramEntryOffset);

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
    //
    // for (int i = 0; i < atom_sclk_table.ucNumEntries; i++)
    // {
    //     std::cout << std::endl << "System Clock (" << i << "). MHz " << atom_sclk_entries[i].ulSclk / 100;
		// 		std::cout << std::endl << "System Clock (" << i << "). MV " << atom_vddc_entries[atom_sclk_entries[i].ucVddInd].usVdd;
    // }
    //
    // for (int i = 0; i < atom_mclk_table.ucNumEntries; i++)
    // {
		// 	std::cout << std::endl << "Memory Clock (" << i << "). MHz " << atom_mclk_entries[i].ulMclk / 100;
		// 	std::cout << std::endl << "Memory Clock (" << i << "). MV " << atom_mclk_entries[i].usMvdd;
    // }
    //
    // for (int i = 0; i < atom_vram_info.ucNumOfVRAMModule; i++)
    // {
    //   std::string vramInfo(reinterpret_cast<char*>(atom_vram_entries[i].strMemPNString));
		// 	std::cout << std::endl << "VRAM Info (" << i << "): " << vramInfo;
    // }
    //
    // for (int i = 0; i < atom_vram_timing_entries.size(); i++)
    // {
    //   std::cout << std::endl << "VRAM Timing (" << i << ") (MHz): " << atom_vram_timing_entries[i].ulClkRange / 100;
    //   std::string vramTimingInfo(reinterpret_cast<char*>(atom_vram_timing_entries[i].ucLatency));
    //   std::cout << std::endl << "VRAM Timing Info (" << i << "): " << vramTimingInfo;
    // }

    delete buffer;
}
