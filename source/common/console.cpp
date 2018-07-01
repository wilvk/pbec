#include "headers.h"

void Console::printSectionHeader(const char* headerText)
{
  std::cout << std::endl << "----";
  std::cout << std::endl << headerText;
  std::cout << std::endl << "----" << std::endl;
}

void Console::printSectionFooter()
{
  std::cout << std::endl << "----" << std::endl;
}

void Console::PrintAtomRomHeaderInfo(ATOM_ROM_HEADER AtomRomHeader)
{
  printSectionHeader("ATOM_ROM_HEADER (dec, hex)");
  std::cout << "ATOM_COMMON_TABLE_HEADER sHeader" <<
    std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(AtomRomHeader.sHeader.usStructureSize) <<
    std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(AtomRomHeader.sHeader.ucTableFormatRevision) <<
    std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(AtomRomHeader.sHeader.ucTableContentRevision) <<
    std::endl << "uaFirmWareSignature: " << ByteUtils::PrintDecHexString(AtomRomHeader.uaFirmWareSignature) <<
    std::endl << "usBiosRuntimeSegmentAddress: " << ByteUtils::PrintDecHexString(AtomRomHeader.usBiosRuntimeSegmentAddress) <<
    std::endl << "usProtectedModeInfoOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usProtectedModeInfoOffset) <<
    std::endl << "usConfigFilenameOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usConfigFilenameOffset) <<
    std::endl << "usCRC_BlockOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usCRC_BlockOffset) <<
    std::endl << "usBIOS_BootupMessageOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usBIOS_BootupMessageOffset) <<
    std::endl << "usInt10Offset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usInt10Offset) <<
    std::endl << "usPciBusDevInitCode: "<< ByteUtils::PrintDecHexString(AtomRomHeader.usPciBusDevInitCode) <<
    std::endl << "usIoBaseAddress: " << ByteUtils::PrintDecHexString(AtomRomHeader.usIoBaseAddress) <<
    std::endl << "usSubsystemVendorID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemVendorID) <<
    std::endl << "usSubsystemID: "<< ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemID) <<
    std::endl << "usPCI_InfoOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usPCI_InfoOffset) <<
    std::endl << "usMasterCommandTableOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usMasterCommandTableOffset) <<
    std::endl << "usMasterDataTableOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usMasterDataTableOffset) <<
    std::endl << "ucExtendedFunctionCode: " << ByteUtils::PrintDecHexString(AtomRomHeader.ucExtendedFunctionCode) <<
    std::endl << "ulPSPDirTableOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.ulPSPDirTableOffset) <<
    std::endl << "usVendorID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usVendorID) <<
    std::endl << "usDeviceID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usDeviceID);
  printSectionFooter();
}

void Console::PrintAtomDataTableInfo(ATOM_DATA_TABLES AtomDataTable)
{
  printSectionHeader("ATOM_ATOM_DATA_TABLE (dec, hex)");
  std::cout << "ATOM_COMMON_TABLE_HEADER sHeader" <<
    std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(AtomDataTable.sHeader.usStructureSize) <<
    std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(AtomDataTable.sHeader.ucTableFormatRevision) <<
    std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(AtomDataTable.sHeader.ucTableContentRevision) <<
    std::endl << "UtilityPipeLine: " << ByteUtils::PrintDecHexString(AtomDataTable.UtilityPipeLine) <<
    std::endl << "MultimediaCapabilityInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.MultimediaCapabilityInfo) <<
    std::endl << "MultimediaConfigInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.MultimediaConfigInfo) <<
    std::endl << "StandardVESA_Timing: " << ByteUtils::PrintDecHexString(AtomDataTable.StandardVESA_Timing) <<
    std::endl << "FirmwareInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.FirmwareInfo) <<
    std::endl << "PaletteData: " << ByteUtils::PrintDecHexString(AtomDataTable.PaletteData) <<
    std::endl << "LCD_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.LCD_Info) <<
    std::endl << "DIGTransmitterInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.DIGTransmitterInfo) <<
    std::endl << "SMU_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.SMU_Info) <<
    std::endl << "SupportedDevicesInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.SupportedDevicesInfo) <<
    std::endl << "GPIO_I2C_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.GPIO_I2C_Info) <<
    std::endl << "VRAM_UsageByFirmware: " << ByteUtils::PrintDecHexString(AtomDataTable.VRAM_UsageByFirmware) <<
    std::endl << "GPIO_Pin_LUT: " << ByteUtils::PrintDecHexString(AtomDataTable.GPIO_Pin_LUT) <<
    std::endl << "VESA_ToInternalModeLUT: " << ByteUtils::PrintDecHexString(AtomDataTable.VESA_ToInternalModeLUT) <<
    std::endl << "GFX_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.GFX_Info) <<
    std::endl << "PowerPlayInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.PowerPlayInfo) <<
    std::endl << "GPUVirtualizationInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.GPUVirtualizationInfo) <<
    std::endl << "SaveRestoreInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.SaveRestoreInfo) <<
    std::endl << "PPLL_SS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.PPLL_SS_Info) <<
    std::endl << "OemInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.OemInfo) <<
    std::endl << "XTMDS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.XTMDS_Info) <<
    std::endl << "MclkSS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.MclkSS_Info) <<
    std::endl << "Object_Header: " << ByteUtils::PrintDecHexString(AtomDataTable.Object_Header) <<
    std::endl << "IndirectIOAccess: " << ByteUtils::PrintDecHexString(AtomDataTable.IndirectIOAccess) <<
    std::endl << "MC_InitParameter: " << ByteUtils::PrintDecHexString(AtomDataTable.MC_InitParameter) <<
    std::endl << "ASIC_VDDC_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.ASIC_VDDC_Info) <<
    std::endl << "ASIC_InternalSS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.ASIC_InternalSS_Info) <<
    std::endl << "TV_VideoMode: " << ByteUtils::PrintDecHexString(AtomDataTable.TV_VideoMode) <<
    std::endl << "VRAM_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.VRAM_Info) <<
    std::endl << "MemoryTrainingInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.MemoryTrainingInfo) <<
    std::endl << "IntegratedSystemInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.IntegratedSystemInfo) <<
    std::endl << "ASIC_ProfilingInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.ASIC_ProfilingInfo) <<
    std::endl << "VoltageObjectInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.VoltageObjectInfo) <<
    std::endl << "PowerSourceInfoe: " << ByteUtils::PrintDecHexString(AtomDataTable.PowerSourceInfo) <<
    std::endl << "ServiceInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.ServiceInfo);
  printSectionFooter();
}

void Console::PrintAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE AtomPowerplayTable)
{
  printSectionHeader("ATOM_POWERPLAY_TABLE (dec, hex)");
  std::cout << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.sHeader.usStructureSize) <<
    std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.sHeader.ucTableFormatRevision) <<
    std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.sHeader.ucTableContentRevision) <<
    std::endl << "ucTableRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ucTableRevision) <<
    std::endl << "usTableSize: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usTableSize) <<
    std::endl << "ulGoldenPPID: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulGoldenPPID) <<
    std::endl << "ulGoldenRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulGoldenRevision) <<
    std::endl << "usFormatID: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usFormatID) <<
    std::endl << "usVoltageTime: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVoltageTime) <<
    std::endl << "ulPlatformCaps: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulPlatformCaps) <<
    std::endl << "ulMaxODEngineClock: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODEngineClock) <<
    std::endl << "ulMaxODMemoryClock: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODMemoryClock) <<
    std::endl << "usPowerControlLimit: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPowerControlLimit) <<
    std::endl << "usUlvVoltageOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usUlvVoltageOffset) <<
    std::endl << "usStateArrayOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usStateArrayOffset) <<
    std::endl << "usFanTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usFanTableOffset) <<
    std::endl << "usThermalControllerOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usThermalControllerOffset) <<
    std::endl << "usReserv: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserv) <<
    std::endl << "usMclkDependencyTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usMclkDependencyTableOffset) <<
    std::endl << "usSclkDependencyTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usSclkDependencyTableOffset) <<
    std::endl << "usVddcLookupTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVddcLookupTableOffset) <<
    std::endl << "usVddgfxLookupTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVddgfxLookupTableOffset) <<
    std::endl << "usMMDependencyTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usMMDependencyTableOffset) <<
    std::endl << "usVCEStateTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVCEStateTableOffset) <<
    std::endl << "usPPMTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPPMTableOffset) <<
    std::endl << "usPowerTuneTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPowerTuneTableOffset) <<
    std::endl << "usHardLimitTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usHardLimitTableOffset) <<
    std::endl << "usPCIETableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPCIETableOffset) <<
    std::endl << "usGPIOTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usGPIOTableOffset) <<
    std::endl << "usReserved[0]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[0]) <<
    std::endl << "usReserved[1]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[1]) <<
    std::endl << "usReserved[2]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[2]) <<
    std::endl << "usReserved[3]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[3]) <<
    std::endl << "usReserved[4]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[4]) <<
    std::endl << "usReserved[5]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[5]);
  printSectionFooter();
}

void Console::PrintAtomPowertuneTableInfo(ATOM_POWERTUNE_TABLE AtomPowertuneTable)
{
  printSectionHeader("ATOM_POWERTUNE_TABLE (dec, hex)");
  std::cout << "ucRevId: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucRevId) <<
    std::endl << "usTDP: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTDP) <<
    std::endl << "usConfigurableTDP: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usConfigurableTDP) <<
    std::endl << "usTDC: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTDC) <<
    std::endl << "usBatteryPowerLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usBatteryPowerLimit) <<
    std::endl << "usSmallPowerLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usSmallPowerLimit) <<
    std::endl << "usLowCACLeakage: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usLowCACLeakage) <<
    std::endl << "usHighCACLeakage: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usHighCACLeakage) <<
    std::endl << "usMaximumPowerDeliveryLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usMaximumPowerDeliveryLimit) <<
    std::endl << "usTjMax: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTjMax) <<
    std::endl << "usPowerTuneDataSetID: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usPowerTuneDataSetID) <<
    std::endl << "usEDCLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usEDCLimit) <<
    std::endl << "usSoftwareShutdownTemp: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usSoftwareShutdownTemp) <<
    std::endl << "usClockStretchAmount: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usClockStretchAmount) <<
    std::endl << "usTemperatureLimitHotspot: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitHotspot) <<
    std::endl << "usTemperatureLimitLiquid1: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitLiquid1) <<
    std::endl << "usTemperatureLimitLiquid2: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitLiquid2) <<
    std::endl << "usTemperatureLimitVrVddc: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitVrVddc) <<
    std::endl << "usTemperatureLimitVrMvdd: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitVrMvdd) <<
    std::endl << "usTemperatureLimitPlx: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitPlx) <<
    std::endl << "ucLiquid1_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucLiquid1_I2C_address) <<
    std::endl << "ucLiquid2_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucLiquid2_I2C_address) <<
    std::endl << "ucLiquid_I2C_Line: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucLiquid_I2C_Line) <<
    std::endl << "ucVr_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucVr_I2C_address) <<
    std::endl << "ucVr_I2C_Line: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucVr_I2C_Line) <<
    std::endl << "ucPlx_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucPlx_I2C_address) <<
    std::endl << "ucPlx_I2C_Line: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucPlx_I2C_Line) <<
    std::endl << "usReserved: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usReserved);
  printSectionFooter();
}

void Console::PrintAtomFanTableInfo(ATOM_FAN_TABLE AtomFanTable)
{
  printSectionHeader("ATOM_FAN_TABLE (dec, hex)");
  std::cout << "ucRevId: " << ByteUtils::PrintDecHexString(AtomFanTable.ucRevId) <<
    std::endl << "ucTHyst: " << ByteUtils::PrintDecHexString(AtomFanTable.ucTHyst) <<
    std::endl << "usTMin: " << ByteUtils::PrintDecHexString(AtomFanTable.usTMin) <<
    std::endl << "usTMed: " << ByteUtils::PrintDecHexString(AtomFanTable.usTMed) <<
    std::endl << "usTHigh: " << ByteUtils::PrintDecHexString(AtomFanTable.usTHigh) <<
    std::endl << "usPWMMin: " << ByteUtils::PrintDecHexString(AtomFanTable.usPWMMin) <<
    std::endl << "usPWMMed: " << ByteUtils::PrintDecHexString(AtomFanTable.usPWMMed) <<
    std::endl << "usPWMHigh: " << ByteUtils::PrintDecHexString(AtomFanTable.usPWMHigh) <<
    std::endl << "usTMax: " << ByteUtils::PrintDecHexString(AtomFanTable.usTMax) <<
    std::endl << "ucFanControlMode: " << ByteUtils::PrintDecHexString(AtomFanTable.ucFanControlMode) <<
    std::endl << "usFanPWMMax: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanPWMMax) <<
    std::endl << "usFanOutputSensitivity: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanOutputSensitivity) <<
    std::endl << "usFanRPMMax: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanRPMMax) <<
    std::endl << "ulMinFanSCLKAcousticLimit: " << ByteUtils::PrintDecHexString(AtomFanTable.ulMinFanSCLKAcousticLimit) <<
    std::endl << "ucTargetTemperature: " << ByteUtils::PrintDecHexString(AtomFanTable.ucTargetTemperature) <<
    std::endl << "ucMinimumPWMLimit: " << ByteUtils::PrintDecHexString(AtomFanTable.ucMinimumPWMLimit) <<
    std::endl << "usFanGainEdge: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainEdge) <<
    std::endl << "usFanGainHotspot: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainHotspot) <<
    std::endl << "usFanGainLiquid: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainLiquid) <<
    std::endl << "usFanGainVrVddc: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainVrVddc) <<
    std::endl << "usFanGainVrMvdd: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainVrMvdd) <<
    std::endl << "usFanGainPlx: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainPlx) <<
    std::endl << "usFanGainHbm: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainHbm) <<
    std::endl << "usReserved: " << ByteUtils::PrintDecHexString(AtomFanTable. usReserved);
  printSectionFooter();
}

void Console::PrintDefaultAtomRomHeaderInfo(ATOM_ROM_HEADER AtomRomHeader)
{
  printSectionHeader("[DEFAULT] ATOM_ROM_HEADER (dec, hex)");
  std::cout << "Vendor ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usVendorID) <<
    std::endl << "Device ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usDeviceID) <<
    std::endl << "Subsystem ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemID) <<
    std::endl << "Subsystem Vendor ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemVendorID) <<
    std::endl << "Firmware Signature: " << ByteUtils::PrintDecHexString(AtomRomHeader.uaFirmWareSignature);
  printSectionFooter();
}

void Console::PrintDefaultAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE AtomPowerplayTable)
{
  printSectionHeader("[DEFAULT] ATOM_POWERPLAY_TABLE (dec, hex)");
  std::cout << "Max GPU Freq. (MHz * 100): " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODEngineClock) <<
    std::endl << "Max Memory Freq.(MHz * 100): " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODMemoryClock) <<
    std::endl << "Power Control Limit (%): " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPowerControlLimit);
  printSectionFooter();
}

void Console::PrintDefaultAtomPowertuneTableInfo(ATOM_POWERTUNE_TABLE AtomPowertuneTable)
{
  printSectionHeader("[DEFAULT] ATOM_POWERTUNE_TABLE (dec, hex)");
  std::cout << "TDP (W): " << AtomPowertuneTable.usTDP <<
    std::endl << "TDC (A): " << AtomPowertuneTable.usTDC <<
    std::endl << "Max Power Limit (W): " << AtomPowertuneTable.usMaximumPowerDeliveryLimit <<
    std::endl << "Max Temp. (C): " << AtomPowertuneTable.usTjMax <<
    std::endl << "Shutdown Temp. (C): " << AtomPowertuneTable.usSoftwareShutdownTemp <<
    std::endl << "Hotspot Temp. (C): " << AtomPowertuneTable.usTemperatureLimitHotspot;
  printSectionFooter();
}

void Console::PrintDefaultAtomFanTableInfo(ATOM_FAN_TABLE AtomFanTable)
{
  printSectionHeader("[DEFAULT] ATOM_FAN_TABLE (dec, hex)");
  std::cout << "Temp. Hysteresis: " << AtomFanTable.ucTHyst <<
    std::endl << "Min Temp. (C * 100): " << AtomFanTable.usTMin <<
    std::endl << "Med Temp. (C * 100): " << AtomFanTable.usTMed <<
    std::endl << "High Temp. (C * 100): " << AtomFanTable.usTHigh <<
    std::endl << "Max Temp. (C * 100): " << AtomFanTable.usTMax <<
    std::endl << "Min PWM (% * 100): " << AtomFanTable.usPWMMin <<
    std::endl << "Med PWM (% * 100): " << AtomFanTable.usPWMMed <<
    std::endl << "High PWM (% * 100): " << AtomFanTable.usPWMHigh <<
    std::endl << "Max PWM (%): " << AtomFanTable.usFanPWMMax <<
    std::endl << "Max RPM: " << AtomFanTable.usFanRPMMax <<
    std::endl << "Sensitivity: " << AtomFanTable.usFanOutputSensitivity <<
    std::endl << "Acoustic Limit (MHz * 100): " << AtomFanTable.ulMinFanSCLKAcousticLimit;
  printSectionFooter();
}

void Console::PrintDeviceValidation(std::vector<WORD> SupportedDeviceIDs, WORD DeviceId)
{
  bool exists = std::find(std::begin(SupportedDeviceIDs), std::end(SupportedDeviceIDs), DeviceId) != std::end(SupportedDeviceIDs);
  std::string deviceIdString = ByteUtils::ToHexString(DeviceId);

  if(!exists)
  {
    std::cout << std::endl << "WARNING: Unsupported DeviceID: " << deviceIdString;
  }
  else
  {
    std::cout << std::endl << "DeviceId is valid:" << deviceIdString;
  }
}

void Console::PrintFileSizeWarning(int FileSize)
{
  if (FileSize < EXPECTED_FILE_SIZE_BYTES)
  {
    std::cout << std::endl << std::endl <<
      "WARNING: This BIOS is less than the standard 512KB size." << std::endl <<
      "Flashing this BIOS may corrupt your graphics card." << std::endl;
  }
}

void Console::PrintBiosWarning()
{
  std::cout <<
    "WARNING: Modifying your BIOS is dangerous and could cause irreversible damage to your GPU." << std::endl <<
    "Using a modified BIOS may void your warranty." << std::endl <<
    "The author will not be held accountable for your actions." << std::endl;
}

void Console::PrintFileDetails(const char* Filename, int Filesize)
{
  std::cout << std::endl << "File Name: " << Filename;
  std::cout << std::endl << "File size: " << Filesize << " bytes" << std::endl;
}

void Console::PrintDefaultAtomSysClockEntriesInfo(ATOM_SCLK_TABLE AtomSysClockTable, std::vector<ATOM_SCLK_ENTRY> AtomSysClockEntries,
  std::vector<ATOM_VOLTAGE_ENTRY> AtomVoltageEntries)
{
  printSectionHeader("[DEFAULT] ATOM_SCLK_ENTRY Array");
  for (int i = 0; i < AtomSysClockTable.ucNumEntries; i++)
  {
    std::cout << std::endl <<
      "Entry: " << i << std::endl <<
      "\tFrequency: " << AtomSysClockEntries[i].ulSclk / 100 << " Mhz." << std::endl <<
      "\tVoltage: " << AtomVoltageEntries[AtomSysClockEntries[i].ucVddInd].usVdd << " MV";
  }
  printSectionFooter();
}

void Console::PrintDefaultAtomMemClockEntriesInfo(ATOM_MCLK_TABLE AtomMemClockTable, std::vector<ATOM_MCLK_ENTRY> AtomMemClockEntries)
{
  printSectionHeader("[DEFAULT] ATOM_MCLK_ENTRY Array");
  for (int i = 0; i < AtomMemClockTable.ucNumEntries; i++)
  {
    std::cout << std::endl <<
      "Entry: " << i << std::endl <<
      "\tFrequency: " << AtomMemClockEntries[i].ulMclk / 100 << " MHz." << std::endl <<
      "\tVoltage:. " << AtomMemClockEntries[i].usMvdd << " MV";
  }
  printSectionFooter();
}

void Console::PrintDefaultAtomVramInfo(ATOM_VRAM_INFO AtomVramInfo, std::vector<ATOM_VRAM_ENTRY> AtomVramEntries)
{
  printSectionHeader("[DEFAULT] ATOM_VRAM_INFO Array");
  for (int i = 0; i < AtomVramInfo.ucNumOfVRAMModule; i++)
  {
    std::cout << std::endl << "(" << i << ")[VRAM Table " << i << " Name: " << AtomVramEntries[i].strMemPNString << "]";
  }
  printSectionFooter();
}

void Console::PrintDefaultAtomVramEntriesInfo(ATOM_VRAM_INFO AtomVramInfo, std::vector<ATOM_VRAM_ENTRY> AtomVramEntries)
{
  printSectionHeader("[DEFAULT] ATOM_VRAM_ENTRY Array");
  for (int i = 0; i < AtomVramInfo.ucNumOfVRAMModule; i++)
  {
    std::cout << std::endl << "VRAM Table: " << i << std::endl <<
      "\tVendorId: 0x" << std::hex << (int)AtomVramEntries[i].ucMemoryVenderID << std::endl <<
      "\tSize (MB): " << std::dec << (int)AtomVramEntries[i].usMemorySize << std::endl <<
      "\tDensity: 0x"  << std::hex << (int)AtomVramEntries[i].ucDensity << std::endl <<
      "\tType: 0x"  << std::hex << (int)AtomVramEntries[i].ucMemoryType;
  }
  printSectionFooter();
}

void Console::PrintDefaultAtomVramTimingEntriesInfo(std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries)
{
  printSectionHeader("[DEFAULT] ATOM_VRAM_TIMING_ENTRY Array");
  for (int i = 0; i < AtomVramTimingEntries.size(); i++)
  {
    DWORD table = AtomVramTimingEntries[i].ulClkRange >> 24;
    std::cout <<
      std::endl <<
      "Strap: " << std::dec << i << std::endl <<
      "\tTable: " << std::to_string(table) << std::endl <<
      "\tMHz: " << std::to_string( (AtomVramTimingEntries[i].ulClkRange & 0x00FFFFFF) / 100) << std::endl <<
      "\tTiming Strap: " << ByteUtils::PrintByteArray(AtomVramTimingEntries[i].ucLatency, 48);
  }
  printSectionFooter();
}

void Console::PrintAttributes()
{
  printSectionHeader("Currently supported areas for modification");
  std::cout <<
    "\tHEADER" << std::endl <<
    "\tDATA" << std::endl <<
    "\tPOWERPLAY" << std::endl <<
    "\tPOWERTUNE" << std::endl <<
    "\tFAN" << std::endl <<
    "\tSYSTEM_CLOCK" << std::endl <<
    "\tMEMORY_CLOCK" << std::endl <<
    "\tVRAM_INFO" << std::endl <<
    "\tVRAM_TIMING" << std::endl <<
    "\tSTRINGS";

  printSectionHeader("Currently supported attributes for modification by area");

  std::cout <<
    "\tHEADER:" << std::endl <<
    "\t\tHEADER.uaFirmWareSignature" << std::endl <<
    "\t\tHEADER.usBiosRuntimeSegmentAddress" << std::endl <<
    "\t\tHEADER.usProtectedModeInfoOffset" << std::endl <<
    "\t\tHEADER.usConfigFilenameOffset" << std::endl <<
    "\t\tHEADER.usCRC_BlockOffset" << std::endl <<
    "\t\tHEADER.usBIOS_BootupMessageOffset" << std::endl <<
    "\t\tHEADER.usInt10Offset" << std::endl <<
    "\t\tHEADER.usPciBusDevInitCode" << std::endl <<
    "\t\tHEADER.usIoBaseAddress" << std::endl <<
    "\t\tHEADER.usSubsystemVendorID" << std::endl <<
    "\t\tHEADER.usSubsystemID" << std::endl <<
    "\t\tHEADER.usPCI_InfoOffset" << std::endl <<
    "\t\tHEADER.usMasterCommandTableOffset" << std::endl <<
    "\t\tHEADER.usMasterDataTableOffset" << std::endl <<
    "\t\tHEADER.ucExtendedFunctionCode" << std::endl <<
    "\t\tHEADER.ulPSPDirTableOffset" << std::endl <<
    "\t\tHEADER.usVendorID" << std::endl <<
    "\t\tHEADER.usDeviceID" << std::endl <<
    "\tDATA:" << std::endl <<
    "\tPOWERPLAY:" << std::endl <<
    "\t\tPOWERPLAY.ucTableRevision" << std::endl <<
    "\t\tPOWERPLAY.usTableSize" << std::endl <<
    "\t\tPOWERPLAY.ulGoldenPPID" << std::endl <<
    "\t\tPOWERPLAY.ulGoldenRevision" << std::endl <<
    "\t\tPOWERPLAY.usFormatID" << std::endl <<
    "\t\tPOWERPLAY.usVoltageTime" << std::endl <<
    "\t\tPOWERPLAY.ulPlatformCaps" << std::endl <<
    "\t\tPOWERPLAY.ulMaxODEngineClock" << std::endl <<
    "\t\tPOWERPLAY.ulMaxODMemoryClock" << std::endl <<
    "\t\tPOWERPLAY.usPowerControlLimit" << std::endl <<
    "\t\tPOWERPLAY.usUlvVoltageOffset" << std::endl <<
    "\t\tPOWERPLAY.usStateArrayOffset" << std::endl <<
    "\t\tPOWERPLAY.usFanTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usThermalControllerOffset" << std::endl <<
    "\t\tPOWERPLAY.usReserv" << std::endl <<
    "\t\tPOWERPLAY.usMclkDependencyTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usSclkDependencyTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usVddcLookupTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usVddgfxLookupTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usMMDependencyTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usVCEStateTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usPPMTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usPowerTuneTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usHardLimitTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usPCIETableOffset" << std::endl <<
    "\t\tPOWERPLAY.usGPIOTableOffset" << std::endl <<
    "\t\tPOWERPLAY.usReserved[0]" << std::endl <<
    "\t\tPOWERPLAY.usReserved[1]" << std::endl <<
    "\t\tPOWERPLAY.usReserved[2]" << std::endl <<
    "\t\tPOWERPLAY.usReserved[3]" << std::endl <<
    "\t\tPOWERPLAY.usReserved[4]" << std::endl <<
    "\t\tPOWERPLAY.usReserved[5]" << std::endl <<
    "\tPOWERTUNE:" << std::endl <<
    "\tFAN:" << std::endl <<
    "\t\tFAN.ucRevId" << std::endl <<
    "\t\tFAN.ucTHyst" << std::endl <<
    "\t\tFAN.usTMin" << std::endl <<
    "\t\tFAN.usTMed" << std::endl <<
    "\t\tFAN.usTHigh" << std::endl <<
    "\t\tFAN.usPWMMin" << std::endl <<
    "\t\tFAN.usPWMMed" << std::endl <<
    "\t\tFAN.usPWMHigh" << std::endl <<
    "\t\tFAN.usTMax" << std::endl <<
    "\t\tFAN.ucFanControlMode" << std::endl <<
    "\t\tFAN.usFanPWMMax" << std::endl <<
    "\t\tFAN.usFanOutputSensitivity" << std::endl <<
    "\t\tFAN.ulMinFanSCLKAcousticLimit" << std::endl <<
    "\t\tFAN.ucTargetTemperature" << std::endl <<
    "\t\tFAN.ucMinimumPWMLimit" << std::endl <<
    "\t\tFAN.usFanGainEdge" << std::endl <<
    "\t\tFAN.usFanGainHotspot" << std::endl <<
    "\t\tFAN.usFanGainLiquid" << std::endl <<
    "\t\tFAN.usFanGainVrVddc" << std::endl <<
    "\t\tFAN.usFanGainVrMvdd" << std::endl <<
    "\t\tFAN.usFanGainPlx" << std::endl <<
    "\t\tFAN.usFanGainHbm" << std::endl <<
    "\t\tFAN.usReserved" << std::endl <<
    "\tSYSTEM_CLOCK:" << std::endl <<
    "\tMEMORY_CLOCK:" << std::endl <<
    "\tVRAM_INFO:" << std::endl <<
    "\tVRAM_TIMING:" << std::endl <<
    "\tSTRINGS:";
  printSectionFooter();
}
