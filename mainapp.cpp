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

  std::string deviceIdString = ByteUtils::ToHexString(deviceId);

  if(!exists)
  {
    std::cout << std::endl << "WARNING: Unsupported DeviceID: " << deviceIdString;
  }
  else
  {
    std::cout << std::endl << "DeviceId is valid:" << deviceIdString;
  }

  std::cout << std::endl;
}

void MainApp::PrintAtomRomHeaderInfo(ATOM_ROM_HEADER atom_rom_header)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_ROM_HEADER (dec,hex)";
  std::cout << std::endl << "ATOM_COMMON_TABLE_HEADER sHeader";
  std::cout << std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(atom_rom_header.sHeader.usStructureSize);
  std::cout << std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(atom_rom_header.sHeader.ucTableFormatRevision);
  std::cout << std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(atom_rom_header.sHeader.ucTableContentRevision);
  std::cout << std::endl << "uaFirmWareSignature: " << ByteUtils::PrintDecHexString(atom_rom_header.uaFirmWareSignature);
  std::cout << std::endl << "usBiosRuntimeSegmentAddress: " << ByteUtils::PrintDecHexString(atom_rom_header.usBiosRuntimeSegmentAddress);
  std::cout << std::endl << "usProtectedModeInfoOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.usProtectedModeInfoOffset);
  std::cout << std::endl << "usConfigFilenameOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.usConfigFilenameOffset);
  std::cout << std::endl << "usCRC_BlockOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.usCRC_BlockOffset);
  std::cout << std::endl << "usBIOS_BootupMessageOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.usBIOS_BootupMessageOffset);
  std::cout << std::endl << "usInt10Offset: " << ByteUtils::PrintDecHexString(atom_rom_header.usInt10Offset);
  std::cout << std::endl << "usPciBusDevInitCode: "<< ByteUtils::PrintDecHexString(atom_rom_header.usPciBusDevInitCode);
  std::cout << std::endl << "usIoBaseAddress: " << ByteUtils::PrintDecHexString(atom_rom_header.usIoBaseAddress);
  std::cout << std::endl << "usSubsystemVendorID: " << ByteUtils::PrintDecHexString(atom_rom_header.usSubsystemVendorID);
  std::cout << std::endl << "usSubsystemID: "<< ByteUtils::PrintDecHexString(atom_rom_header.usSubsystemID);
  std::cout << std::endl << "usPCI_InfoOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.usPCI_InfoOffset);
  std::cout << std::endl << "usMasterCommandTableOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.usMasterCommandTableOffset);
  std::cout << std::endl << "usMasterDataTableOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.usMasterDataTableOffset);
  std::cout << std::endl << "ucExtendedFunctionCode: " << ByteUtils::PrintDecHexString(atom_rom_header.ucExtendedFunctionCode);
  std::cout << std::endl << "ulPSPDirTableOffset: " << ByteUtils::PrintDecHexString(atom_rom_header.ulPSPDirTableOffset);
  std::cout << std::endl << "usVendorID: " << ByteUtils::PrintDecHexString(atom_rom_header.usVendorID);
  std::cout << std::endl << "usDeviceID: " << ByteUtils::PrintDecHexString(atom_rom_header.usDeviceID);
}

void MainApp::PrintAtomDataTableInfo(ATOM_DATA_TABLES atom_data_table)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_DATA_TABLE (dec,hex)";
  std::cout << std::endl << "ATOM_COMMON_TABLE_HEADER sHeader";
  std::cout << std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(atom_data_table.sHeader.usStructureSize);
  std::cout << std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(atom_data_table.sHeader.ucTableFormatRevision);
  std::cout << std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(atom_data_table.sHeader.ucTableContentRevision);

  std::cout << std::endl << "UtilityPipeLine: " << ByteUtils::PrintDecHexString(atom_data_table.UtilityPipeLine);
  std::cout << std::endl << "MultimediaCapabilityInfo: " << ByteUtils::PrintDecHexString(atom_data_table.MultimediaCapabilityInfo);
  std::cout << std::endl << "MultimediaConfigInfo: " << ByteUtils::PrintDecHexString(atom_data_table.MultimediaConfigInfo);
  std::cout << std::endl << "StandardVESA_Timing: " << ByteUtils::PrintDecHexString(atom_data_table.StandardVESA_Timing);
  std::cout << std::endl << "FirmwareInfo: " << ByteUtils::PrintDecHexString(atom_data_table.FirmwareInfo);
  std::cout << std::endl << "PaletteData: " << ByteUtils::PrintDecHexString(atom_data_table.PaletteData);
  std::cout << std::endl << "LCD_Info: " << ByteUtils::PrintDecHexString(atom_data_table.LCD_Info);
  std::cout << std::endl << "DIGTransmitterInfo: " << ByteUtils::PrintDecHexString(atom_data_table.DIGTransmitterInfo);
  std::cout << std::endl << "SMU_Info: " << ByteUtils::PrintDecHexString(atom_data_table.SMU_Info);
  std::cout << std::endl << "SupportedDevicesInfo: " << ByteUtils::PrintDecHexString(atom_data_table.SupportedDevicesInfo);
  std::cout << std::endl << "GPIO_I2C_Info: " << ByteUtils::PrintDecHexString(atom_data_table.GPIO_I2C_Info);
  std::cout << std::endl << "VRAM_UsageByFirmware: " << ByteUtils::PrintDecHexString(atom_data_table.VRAM_UsageByFirmware);
  std::cout << std::endl << "GPIO_Pin_LUT: " << ByteUtils::PrintDecHexString(atom_data_table.GPIO_Pin_LUT);
  std::cout << std::endl << "VESA_ToInternalModeLUT: " << ByteUtils::PrintDecHexString(atom_data_table.VESA_ToInternalModeLUT);
  std::cout << std::endl << "GFX_Info: " << ByteUtils::PrintDecHexString(atom_data_table.GFX_Info);
  std::cout << std::endl << "PowerPlayInfo: " << ByteUtils::PrintDecHexString(atom_data_table.PowerPlayInfo);
  std::cout << std::endl << "GPUVirtualizationInfo: " << ByteUtils::PrintDecHexString(atom_data_table.GPUVirtualizationInfo);
  std::cout << std::endl << "SaveRestoreInfo: " << ByteUtils::PrintDecHexString(atom_data_table.SaveRestoreInfo);
  std::cout << std::endl << "PPLL_SS_Info: " << ByteUtils::PrintDecHexString(atom_data_table.PPLL_SS_Info);
  std::cout << std::endl << "OemInfo: " << ByteUtils::PrintDecHexString(atom_data_table.OemInfo);
  std::cout << std::endl << "XTMDS_Info: " << ByteUtils::PrintDecHexString(atom_data_table.XTMDS_Info);
  std::cout << std::endl << "MclkSS_Info: " << ByteUtils::PrintDecHexString(atom_data_table.MclkSS_Info);
  std::cout << std::endl << "Object_Header: " << ByteUtils::PrintDecHexString(atom_data_table.Object_Header);
  std::cout << std::endl << "IndirectIOAccess: " << ByteUtils::PrintDecHexString(atom_data_table.IndirectIOAccess);
  std::cout << std::endl << "MC_InitParameter: " << ByteUtils::PrintDecHexString(atom_data_table.MC_InitParameter);
  std::cout << std::endl << "ASIC_VDDC_Info: " << ByteUtils::PrintDecHexString(atom_data_table.ASIC_VDDC_Info);
  std::cout << std::endl << "ASIC_InternalSS_Info: " << ByteUtils::PrintDecHexString(atom_data_table.ASIC_InternalSS_Info);
  std::cout << std::endl << "TV_VideoMode: " << ByteUtils::PrintDecHexString(atom_data_table.TV_VideoMode);
  std::cout << std::endl << "VRAM_Info: " << ByteUtils::PrintDecHexString(atom_data_table.VRAM_Info);
  std::cout << std::endl << "MemoryTrainingInfo: " << ByteUtils::PrintDecHexString(atom_data_table.MemoryTrainingInfo);
  std::cout << std::endl << "IntegratedSystemInfo: " << ByteUtils::PrintDecHexString(atom_data_table.IntegratedSystemInfo);
  std::cout << std::endl << "ASIC_ProfilingInfo: " << ByteUtils::PrintDecHexString(atom_data_table.ASIC_ProfilingInfo);
  std::cout << std::endl << "VoltageObjectInfo: " << ByteUtils::PrintDecHexString(atom_data_table.VoltageObjectInfo);
  std::cout << std::endl << "PowerSourceInfoe: " << ByteUtils::PrintDecHexString(atom_data_table.PowerSourceInfo);
  std::cout << std::endl << "ServiceInfo: " << ByteUtils::PrintDecHexString(atom_data_table.ServiceInfo);
}

void MainApp::PrintAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE atom_powerplay_table)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_POWERPLAY_TABLE (dec,hex)";
  std::cout << std::endl << "ATOM_COMMON_TABLE_HEADER sHeader";
  std::cout << std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(atom_powerplay_table.sHeader.usStructureSize);
  std::cout << std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(atom_powerplay_table.sHeader.ucTableFormatRevision);
  std::cout << std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(atom_powerplay_table.sHeader.ucTableContentRevision);
  std::cout << std::endl << "ucTableRevision: " << ByteUtils::PrintDecHexString(atom_powerplay_table.ucTableRevision);
  std::cout << std::endl << "usTableSize: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usTableSize);
  std::cout << std::endl << "ulGoldenPPID: " << ByteUtils::PrintDecHexString(atom_powerplay_table.ulGoldenPPID);
  std::cout << std::endl << "ulGoldenRevision: " << ByteUtils::PrintDecHexString(atom_powerplay_table.ulGoldenRevision);
  std::cout << std::endl << "usFormatID: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usFormatID);
  std::cout << std::endl << "usVoltageTime: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usVoltageTime);
  std::cout << std::endl << "ulPlatformCaps: " << ByteUtils::PrintDecHexString(atom_powerplay_table.ulPlatformCaps);
  std::cout << std::endl << "ulMaxODEngineClock: " << ByteUtils::PrintDecHexString(atom_powerplay_table.ulMaxODEngineClock);
  std::cout << std::endl << "ulMaxODMemoryClock: " << ByteUtils::PrintDecHexString(atom_powerplay_table.ulMaxODMemoryClock);
  std::cout << std::endl << "usPowerControlLimit: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usPowerControlLimit);
  std::cout << std::endl << "usUlvVoltageOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usUlvVoltageOffset);
  std::cout << std::endl << "usStateArrayOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usStateArrayOffset);
  std::cout << std::endl << "usFanTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usFanTableOffset);
  std::cout << std::endl << "usThermalControllerOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usThermalControllerOffset);
  std::cout << std::endl << "usReserv: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usReserv);
  std::cout << std::endl << "usMclkDependencyTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usMclkDependencyTableOffset);
  std::cout << std::endl << "usSclkDependencyTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usSclkDependencyTableOffset);
  std::cout << std::endl << "usVddcLookupTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usVddcLookupTableOffset);
  std::cout << std::endl << "usVddgfxLookupTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usVddgfxLookupTableOffset);
  std::cout << std::endl << "usMMDependencyTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usMMDependencyTableOffset);
  std::cout << std::endl << "usVCEStateTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usVCEStateTableOffset);
  std::cout << std::endl << "usPPMTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usPPMTableOffset);
  std::cout << std::endl << "usPowerTuneTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usPowerTuneTableOffset);
  std::cout << std::endl << "usHardLimitTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usHardLimitTableOffset);
  std::cout << std::endl << "usPCIETableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usPCIETableOffset);
  std::cout << std::endl << "usGPIOTableOffset: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usGPIOTableOffset);
  std::cout << std::endl << "usReserved[0]: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usReserved[0]);
  std::cout << std::endl << "usReserved[1]: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usReserved[1]);
  std::cout << std::endl << "usReserved[2]: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usReserved[2]);
  std::cout << std::endl << "usReserved[3]: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usReserved[3]);
  std::cout << std::endl << "usReserved[4]: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usReserved[4]);
  std::cout << std::endl << "usReserved[5]: " << ByteUtils::PrintDecHexString(atom_powerplay_table.usReserved[5]);
}

void MainApp::OpenFile(const char* Filename)
{
    Buffer *buffer = new Buffer();;
    buffer->ReadFile(Filename);
    std::vector<BYTE> bufferSubset;
    RetrieveStruct* retriever = new RetrieveStruct();

    //printFileSizeWarning(buffer->FileData.size());
    //printFileDetails(Filename, buffer);

    atom_rom_header = retriever->AtomRomHeader(buffer);

    //PrintAtomRomHeaderInfo(atom_rom_header);

    //std::string configFileName = buffer->GetStringFromOffset(atom_rom_header.usConfigFilenameOffset);

    //std::cout << std::endl << "Config File Name: " << configFileName;

    //int zeroOffset = 0;
    //bufferSubset = buffer->GetSubset(zeroOffset);

//    buffer->FixChecksum(false, atom_rom_checksum_offset);
//    validateDeviceId(supportedDeviceIDs, atom_rom_header.usDeviceID);

    atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);

    int structInts[] = {16, 8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};
    std::vector<int> structSizes(structInts, structInts + sizeof(structInts) / sizeof(int));
    std::string tableResult = buffer->TableWalk(atom_rom_header.usMasterDataTableOffset, structSizes);

    std::cout << std::endl << "Table Result: " << tableResult;

    //PrintAtomDataTableInfo(atom_data_table);

    std::cout << std::endl <<  "atom_rom_header.usMasterDataTableOffset: " << atom_rom_header.usMasterDataTableOffset;
    std::cout << std::endl <<  "atom_data_table.PowerPlayInfo: " << atom_data_table.PowerPlayInfo;

    atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);

    int structIntsPowerplay[] = {16, 8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};
    std::vector<int> structSizesPowerplay(structIntsPowerplay, structIntsPowerplay + sizeof(structIntsPowerplay) / sizeof(int));
    std::string tableResultPowerplay = buffer->TableWalk(atom_rom_header.usMasterDataTableOffset, structSizesPowerplay);

    std::cout << std::endl << "Table Result Powerplay num: " << tableResultPowerplay;

    std::string tableResultPowerplayFreq = buffer->TableWalk(atom_data_table.PowerPlayInfo, structSizesPowerplay, true);

    std::cout << std::endl << "Table Result Powerplay freq : " << tableResultPowerplayFreq;

    //PrintAtomPowerplayTableInfo(atom_powerplay_table);

    // atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
    // atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));
    // atom_mclk_table_offset = atom_data_table.PowerPlayInfo + atom_powerplay_table.usMclkDependencyTableOffset;
    // atom_mclk_table = retriever->AtomMemClockTable(buffer, atom_mclk_table_offset);
    // atom_mclk_entries = retriever->AtomMemClockEntries(buffer, atom_mclk_table_offset, atom_mclk_table.ucNumEntries);
    // atom_sclk_table = retriever->AtomSysClockTable(buffer, atom_data_table.PowerPlayInfo + atom_powerplay_table.usSclkDependencyTableOffset);
    // atom_sclk_entries = retriever->AtomSysClockEntries(buffer, atom_sclk_table_offset, atom_sclk_table.ucNumEntries);
    // atom_vddc_table = retriever->AtomVoltageTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usVddcLookupTableOffset));
    // atom_vddc_entries = retriever->AtomVoltageEntries(buffer, atom_vddc_table_offset, atom_vddc_table.ucNumEntries);
    // atom_vram_info = retriever->AtomVramInfo(buffer, atom_data_table.VRAM_Info);
    //
    // AtomVramEntryOffset = atom_vram_info_offset + sizeof(ATOM_VRAM_INFO);
    // atom_vram_entries = retriever->AtomVramEntries(buffer, atom_vram_info.ucNumOfVRAMModule, AtomVramEntryOffset);
    //
    // atom_vram_timing_entries = retriever->AtomVramTimingEntries(buffer, AtomVramEntryOffset);

    std::cout << std::endl;
    std::cout << std::endl << "Vendor ID: " << ByteUtils::PrintDecHexString(atom_rom_header.usVendorID);
    std::cout << std::endl << "Device ID: " << ByteUtils::PrintDecHexString(atom_rom_header.usDeviceID);
    std::cout << std::endl << "Subsystem ID: " << ByteUtils::PrintDecHexString(atom_rom_header.usSubsystemID);
    std::cout << std::endl << "Subsystem Vendor ID: " << ByteUtils::PrintDecHexString(atom_rom_header.usSubsystemVendorID);
    std::cout << std::endl << "Firmware Signature: " << ByteUtils::PrintDecHexString(atom_rom_header.uaFirmWareSignature);

    std::cout << std::endl;
    std::cout << std::endl << "Max GPU Freq. : " << ByteUtils::PrintDecHexString(atom_powerplay_table.ulMaxODEngineClock);
    std::cout << std::endl << "Max Memory Freq.: " << ByteUtils::PrintDecHexString(atom_powerplay_table.ulMaxODMemoryClock);
    std::cout << std::endl << "Power Control Limit (%): " << ByteUtils::PrintDecHexString(atom_powerplay_table.usPowerControlLimit);
    std::cout << std::endl << "As int: " << (int)atom_powerplay_table.ulMaxODEngineClock;
    std::cout << std::endl << "As int: " << (int)atom_powerplay_table.ulMaxODMemoryClock;
    std::cout << std::endl << "As int: " << (int)atom_powerplay_table.usPowerControlLimit;

    // std::cout << std::endl;
    // std::cout << std::endl << "TDP (W): " << atom_powertune_table.usTDP;
    // std::cout << std::endl << "TDC (A): " << atom_powertune_table.usTDC;
    // std::cout << std::endl << "Max Power Limit (W): " << atom_powertune_table.usMaximumPowerDeliveryLimit;
    // std::cout << std::endl << "Max Temp. (C): " << atom_powertune_table.usTjMax;
    // std::cout << std::endl << "Shutdown Temp. (C): " << atom_powertune_table.usSoftwareShutdownTemp;
    // std::cout << std::endl << "Hotspot Temp. (C): " << atom_powertune_table.usTemperatureLimitHotspot;
    //
    // std::cout << std::endl;
    // std::cout << std::endl << "Temp. Hysteresis: " << atom_fan_table.ucTHyst;
    // std::cout << std::endl << "Min Temp. (C): " << atom_fan_table.usTMin / 100;
    // std::cout << std::endl << "Med Temp. (C): " << atom_fan_table.usTMed / 100;
    // std::cout << std::endl << "High Temp. (C): " << atom_fan_table.usTHigh / 100;
    // std::cout << std::endl << "Max Temp. (C): " << atom_fan_table.usTMax / 100;
    // std::cout << std::endl << "Min PWM (%): " << atom_fan_table.usPWMMin / 100;
    // std::cout << std::endl << "Med PWM (%): " << atom_fan_table.usPWMMed / 100;
    // std::cout << std::endl << "High PWM (%): " << atom_fan_table.usPWMHigh / 100;
    // std::cout << std::endl << "Max PWM (%): " << atom_fan_table.usFanPWMMax;
    // std::cout << std::endl << "Max RPM: " << atom_fan_table.usFanRPMMax;
    // std::cout << std::endl << "Sensitivity: " << atom_fan_table.usFanOutputSensitivity;
    // std::cout << std::endl << "Acoustic Limit (MHz): " << atom_fan_table.ulMinFanSCLKAcousticLimit / 100;

    std::cout << std::endl;
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
