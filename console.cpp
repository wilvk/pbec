#include "console.h"

void Console::PrintAtomRomHeaderInfo(ATOM_ROM_HEADER AtomRomHeader)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_ROM_HEADER (dec,hex)";
  std::cout << std::endl << "ATOM_COMMON_TABLE_HEADER sHeader";
  std::cout << std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(AtomRomHeader.sHeader.usStructureSize);
  std::cout << std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(AtomRomHeader.sHeader.ucTableFormatRevision);
  std::cout << std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(AtomRomHeader.sHeader.ucTableContentRevision);
  std::cout << std::endl << "uaFirmWareSignature: " << ByteUtils::PrintDecHexString(AtomRomHeader.uaFirmWareSignature);
  std::cout << std::endl << "usBiosRuntimeSegmentAddress: " << ByteUtils::PrintDecHexString(AtomRomHeader.usBiosRuntimeSegmentAddress);
  std::cout << std::endl << "usProtectedModeInfoOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usProtectedModeInfoOffset);
  std::cout << std::endl << "usConfigFilenameOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usConfigFilenameOffset);
  std::cout << std::endl << "usCRC_BlockOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usCRC_BlockOffset);
  std::cout << std::endl << "usBIOS_BootupMessageOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usBIOS_BootupMessageOffset);
  std::cout << std::endl << "usInt10Offset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usInt10Offset);
  std::cout << std::endl << "usPciBusDevInitCode: "<< ByteUtils::PrintDecHexString(AtomRomHeader.usPciBusDevInitCode);
  std::cout << std::endl << "usIoBaseAddress: " << ByteUtils::PrintDecHexString(AtomRomHeader.usIoBaseAddress);
  std::cout << std::endl << "usSubsystemVendorID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemVendorID);
  std::cout << std::endl << "usSubsystemID: "<< ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemID);
  std::cout << std::endl << "usPCI_InfoOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usPCI_InfoOffset);
  std::cout << std::endl << "usMasterCommandTableOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usMasterCommandTableOffset);
  std::cout << std::endl << "usMasterDataTableOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.usMasterDataTableOffset);
  std::cout << std::endl << "ucExtendedFunctionCode: " << ByteUtils::PrintDecHexString(AtomRomHeader.ucExtendedFunctionCode);
  std::cout << std::endl << "ulPSPDirTableOffset: " << ByteUtils::PrintDecHexString(AtomRomHeader.ulPSPDirTableOffset);
  std::cout << std::endl << "usVendorID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usVendorID);
  std::cout << std::endl << "usDeviceID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usDeviceID);
}

void Console::PrintAtomDataTableInfo(ATOM_DATA_TABLES AtomDataTable)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_DATA_TABLE (dec,hex)";
  std::cout << std::endl << "ATOM_COMMON_TABLE_HEADER sHeader";
  std::cout << std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(AtomDataTable.sHeader.usStructureSize);
  std::cout << std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(AtomDataTable.sHeader.ucTableFormatRevision);
  std::cout << std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(AtomDataTable.sHeader.ucTableContentRevision);
  std::cout << std::endl << "UtilityPipeLine: " << ByteUtils::PrintDecHexString(AtomDataTable.UtilityPipeLine);
  std::cout << std::endl << "MultimediaCapabilityInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.MultimediaCapabilityInfo);
  std::cout << std::endl << "MultimediaConfigInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.MultimediaConfigInfo);
  std::cout << std::endl << "StandardVESA_Timing: " << ByteUtils::PrintDecHexString(AtomDataTable.StandardVESA_Timing);
  std::cout << std::endl << "FirmwareInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.FirmwareInfo);
  std::cout << std::endl << "PaletteData: " << ByteUtils::PrintDecHexString(AtomDataTable.PaletteData);
  std::cout << std::endl << "LCD_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.LCD_Info);
  std::cout << std::endl << "DIGTransmitterInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.DIGTransmitterInfo);
  std::cout << std::endl << "SMU_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.SMU_Info);
  std::cout << std::endl << "SupportedDevicesInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.SupportedDevicesInfo);
  std::cout << std::endl << "GPIO_I2C_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.GPIO_I2C_Info);
  std::cout << std::endl << "VRAM_UsageByFirmware: " << ByteUtils::PrintDecHexString(AtomDataTable.VRAM_UsageByFirmware);
  std::cout << std::endl << "GPIO_Pin_LUT: " << ByteUtils::PrintDecHexString(AtomDataTable.GPIO_Pin_LUT);
  std::cout << std::endl << "VESA_ToInternalModeLUT: " << ByteUtils::PrintDecHexString(AtomDataTable.VESA_ToInternalModeLUT);
  std::cout << std::endl << "GFX_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.GFX_Info);
  std::cout << std::endl << "PowerPlayInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.PowerPlayInfo);
  std::cout << std::endl << "GPUVirtualizationInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.GPUVirtualizationInfo);
  std::cout << std::endl << "SaveRestoreInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.SaveRestoreInfo);
  std::cout << std::endl << "PPLL_SS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.PPLL_SS_Info);
  std::cout << std::endl << "OemInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.OemInfo);
  std::cout << std::endl << "XTMDS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.XTMDS_Info);
  std::cout << std::endl << "MclkSS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.MclkSS_Info);
  std::cout << std::endl << "Object_Header: " << ByteUtils::PrintDecHexString(AtomDataTable.Object_Header);
  std::cout << std::endl << "IndirectIOAccess: " << ByteUtils::PrintDecHexString(AtomDataTable.IndirectIOAccess);
  std::cout << std::endl << "MC_InitParameter: " << ByteUtils::PrintDecHexString(AtomDataTable.MC_InitParameter);
  std::cout << std::endl << "ASIC_VDDC_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.ASIC_VDDC_Info);
  std::cout << std::endl << "ASIC_InternalSS_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.ASIC_InternalSS_Info);
  std::cout << std::endl << "TV_VideoMode: " << ByteUtils::PrintDecHexString(AtomDataTable.TV_VideoMode);
  std::cout << std::endl << "VRAM_Info: " << ByteUtils::PrintDecHexString(AtomDataTable.VRAM_Info);
  std::cout << std::endl << "MemoryTrainingInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.MemoryTrainingInfo);
  std::cout << std::endl << "IntegratedSystemInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.IntegratedSystemInfo);
  std::cout << std::endl << "ASIC_ProfilingInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.ASIC_ProfilingInfo);
  std::cout << std::endl << "VoltageObjectInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.VoltageObjectInfo);
  std::cout << std::endl << "PowerSourceInfoe: " << ByteUtils::PrintDecHexString(AtomDataTable.PowerSourceInfo);
  std::cout << std::endl << "ServiceInfo: " << ByteUtils::PrintDecHexString(AtomDataTable.ServiceInfo);
}

void Console::PrintAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE AtomPowerplayTable)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_POWERPLAY_TABLE (dec,hex)";
  std::cout << std::endl << "sHeader.usStructureSize: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.sHeader.usStructureSize);
  std::cout << std::endl << "sHeader.ucTableFormatRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.sHeader.ucTableFormatRevision);
  std::cout << std::endl << "sHeader.ucTableContentRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.sHeader.ucTableContentRevision);
  std::cout << std::endl << "ucTableRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ucTableRevision);
  std::cout << std::endl << "usTableSize: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usTableSize);
  std::cout << std::endl << "ulGoldenPPID: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulGoldenPPID);
  std::cout << std::endl << "ulGoldenRevision: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulGoldenRevision);
  std::cout << std::endl << "usFormatID: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usFormatID);
  std::cout << std::endl << "usVoltageTime: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVoltageTime);
  std::cout << std::endl << "ulPlatformCaps: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulPlatformCaps);
  std::cout << std::endl << "ulMaxODEngineClock: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODEngineClock);
  std::cout << std::endl << "ulMaxODMemoryClock: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODMemoryClock);
  std::cout << std::endl << "usPowerControlLimit: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPowerControlLimit);
  std::cout << std::endl << "usUlvVoltageOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usUlvVoltageOffset);
  std::cout << std::endl << "usStateArrayOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usStateArrayOffset);
  std::cout << std::endl << "usFanTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usFanTableOffset);
  std::cout << std::endl << "usThermalControllerOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usThermalControllerOffset);
  std::cout << std::endl << "usReserv: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserv);
  std::cout << std::endl << "usMclkDependencyTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usMclkDependencyTableOffset);
  std::cout << std::endl << "usSclkDependencyTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usSclkDependencyTableOffset);
  std::cout << std::endl << "usVddcLookupTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVddcLookupTableOffset);
  std::cout << std::endl << "usVddgfxLookupTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVddgfxLookupTableOffset);
  std::cout << std::endl << "usMMDependencyTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usMMDependencyTableOffset);
  std::cout << std::endl << "usVCEStateTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usVCEStateTableOffset);
  std::cout << std::endl << "usPPMTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPPMTableOffset);
  std::cout << std::endl << "usPowerTuneTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPowerTuneTableOffset);
  std::cout << std::endl << "usHardLimitTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usHardLimitTableOffset);
  std::cout << std::endl << "usPCIETableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPCIETableOffset);
  std::cout << std::endl << "usGPIOTableOffset: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usGPIOTableOffset);
  std::cout << std::endl << "usReserved[0]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[0]);
  std::cout << std::endl << "usReserved[1]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[1]);
  std::cout << std::endl << "usReserved[2]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[2]);
  std::cout << std::endl << "usReserved[3]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[3]);
  std::cout << std::endl << "usReserved[4]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[4]);
  std::cout << std::endl << "usReserved[5]: " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usReserved[5]);
}

void Console::PrintAtomPowertuneTableInfo(ATOM_POWERTUNE_TABLE AtomPowertuneTable)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_POWERTUNE_TABLE (dec,hex)";
  std::cout << std::endl << "ucRevId: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucRevId);
  std::cout << std::endl << "usTDP: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTDP);
  std::cout << std::endl << "usConfigurableTDP: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usConfigurableTDP);
  std::cout << std::endl << "usTDC: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTDC);
  std::cout << std::endl << "usBatteryPowerLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usBatteryPowerLimit);
  std::cout << std::endl << "usSmallPowerLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usSmallPowerLimit);
  std::cout << std::endl << "usLowCACLeakage: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usLowCACLeakage);
  std::cout << std::endl << "usHighCACLeakage: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usHighCACLeakage);
  std::cout << std::endl << "usMaximumPowerDeliveryLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usMaximumPowerDeliveryLimit);
  std::cout << std::endl << "usTjMax: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTjMax);
  std::cout << std::endl << "usPowerTuneDataSetID: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usPowerTuneDataSetID);
  std::cout << std::endl << "usEDCLimit: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usEDCLimit);
  std::cout << std::endl << "usSoftwareShutdownTemp: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usSoftwareShutdownTemp);
  std::cout << std::endl << "usClockStretchAmount: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usClockStretchAmount);
  std::cout << std::endl << "usTemperatureLimitHotspot: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitHotspot);
  std::cout << std::endl << "usTemperatureLimitLiquid1: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitLiquid1);
  std::cout << std::endl << "usTemperatureLimitLiquid2: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitLiquid2);
  std::cout << std::endl << "usTemperatureLimitVrVddc: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitVrVddc);
  std::cout << std::endl << "usTemperatureLimitVrMvdd: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitVrMvdd);
  std::cout << std::endl << "usTemperatureLimitPlx: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usTemperatureLimitPlx);
  std::cout << std::endl << "ucLiquid1_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucLiquid1_I2C_address);
  std::cout << std::endl << "ucLiquid2_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucLiquid2_I2C_address);
  std::cout << std::endl << "ucLiquid_I2C_Line: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucLiquid_I2C_Line);
  std::cout << std::endl << "ucVr_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucVr_I2C_address);
  std::cout << std::endl << "ucVr_I2C_Line: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucVr_I2C_Line);
  std::cout << std::endl << "ucPlx_I2C_address: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucPlx_I2C_address);
  std::cout << std::endl << "ucPlx_I2C_Line: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.ucPlx_I2C_Line);
  std::cout << std::endl << "usReserved: " << ByteUtils::PrintDecHexString(AtomPowertuneTable.usReserved);
}

void Console::PrintAtomFanTableInfo(ATOM_FAN_TABLE AtomFanTable)
{
  std::cout << std::endl;
  std::cout << std::endl << "ATOM_FAN_TABLE (dec,hex)";
  std::cout << std::endl << "ucRevId: " << ByteUtils::PrintDecHexString(AtomFanTable.ucRevId);
  std::cout << std::endl << "ucTHyst: " << ByteUtils::PrintDecHexString(AtomFanTable.ucTHyst);
  std::cout << std::endl << "usTMin: " << ByteUtils::PrintDecHexString(AtomFanTable.usTMin);
  std::cout << std::endl << "usTMed: " << ByteUtils::PrintDecHexString(AtomFanTable.usTMed);
  std::cout << std::endl << "usTHigh: " << ByteUtils::PrintDecHexString(AtomFanTable.usTHigh);
  std::cout << std::endl << "usPWMMin: " << ByteUtils::PrintDecHexString(AtomFanTable.usPWMMin);
  std::cout << std::endl << "usPWMMed: " << ByteUtils::PrintDecHexString(AtomFanTable.usPWMMed);
  std::cout << std::endl << "usPWMHigh: " << ByteUtils::PrintDecHexString(AtomFanTable.usPWMHigh);
  std::cout << std::endl << "usTMax: " << ByteUtils::PrintDecHexString(AtomFanTable.usTMax);
  std::cout << std::endl << "ucFanControlMode: " << ByteUtils::PrintDecHexString(AtomFanTable.ucFanControlMode);
  std::cout << std::endl << "usFanPWMMax: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanPWMMax);
  std::cout << std::endl << "usFanOutputSensitivity: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanOutputSensitivity);
  std::cout << std::endl << "usFanRPMMax: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanRPMMax);
  std::cout << std::endl << "ulMinFanSCLKAcousticLimit: " << ByteUtils::PrintDecHexString(AtomFanTable.ulMinFanSCLKAcousticLimit);
  std::cout << std::endl << "ucTargetTemperature: " << ByteUtils::PrintDecHexString(AtomFanTable.ucTargetTemperature);
  std::cout << std::endl << "ucMinimumPWMLimit: " << ByteUtils::PrintDecHexString(AtomFanTable.ucMinimumPWMLimit);
  std::cout << std::endl << "usFanGainEdge: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainEdge);
  std::cout << std::endl << "usFanGainHotspot: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainHotspot);
  std::cout << std::endl << "usFanGainLiquid: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainLiquid);
  std::cout << std::endl << "usFanGainVrVddc: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainVrVddc);
  std::cout << std::endl << "usFanGainVrMvdd: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainVrMvdd);
  std::cout << std::endl << "usFanGainPlx: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainPlx);
  std::cout << std::endl << "usFanGainHbm: " << ByteUtils::PrintDecHexString(AtomFanTable.usFanGainHbm);
  std::cout << std::endl << "usReserved: " << ByteUtils::PrintDecHexString(AtomFanTable. usReserved);
}

void Console::PrintDefaultAtomRomHeaderInfo(ATOM_ROM_HEADER AtomRomHeader)
{
  std::cout << std::endl << "Vendor ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usVendorID);
  std::cout << std::endl << "Device ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usDeviceID);
  std::cout << std::endl << "Subsystem ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemID);
  std::cout << std::endl << "Subsystem Vendor ID: " << ByteUtils::PrintDecHexString(AtomRomHeader.usSubsystemVendorID);
  std::cout << std::endl << "Firmware Signature: " << ByteUtils::PrintDecHexString(AtomRomHeader.uaFirmWareSignature);
}

void Console::PrintDefaultAtomPowerplayTableInfo(ATOM_POWERPLAY_TABLE AtomPowerplayTable)
{
  std::cout << std::endl << "Max GPU Freq. (MHz * 100): " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODEngineClock);
  std::cout << std::endl << "Max Memory Freq.(MHz * 100): " << ByteUtils::PrintDecHexString(AtomPowerplayTable.ulMaxODMemoryClock);
  std::cout << std::endl << "Power Control Limit (%): " << ByteUtils::PrintDecHexString(AtomPowerplayTable.usPowerControlLimit);
}

void Console::PrintDefaultAtomPowertuneTableInfo(ATOM_POWERTUNE_TABLE AtomPowertuneTable)
{
  std::cout << std::endl << "TDP (W): " << AtomPowertuneTable.usTDP;
  std::cout << std::endl << "TDC (A): " << AtomPowertuneTable.usTDC;
  std::cout << std::endl << "Max Power Limit (W): " << AtomPowertuneTable.usMaximumPowerDeliveryLimit;
  std::cout << std::endl << "Max Temp. (C): " << AtomPowertuneTable.usTjMax;
  std::cout << std::endl << "Shutdown Temp. (C): " << AtomPowertuneTable.usSoftwareShutdownTemp;
  std::cout << std::endl << "Hotspot Temp. (C): " << AtomPowertuneTable.usTemperatureLimitHotspot;
}

void Console::PrintDefaultAtomFanTableInfo(ATOM_FAN_TABLE AtomFanTable)
{
  std::cout << std::endl << "Temp. Hysteresis: " << AtomFanTable.ucTHyst;
  std::cout << std::endl << "Min Temp. (C * 100): " << AtomFanTable.usTMin;
  std::cout << std::endl << "Med Temp. (C * 100): " << AtomFanTable.usTMed;
  std::cout << std::endl << "High Temp. (C * 100): " << AtomFanTable.usTHigh;
  std::cout << std::endl << "Max Temp. (C * 100): " << AtomFanTable.usTMax;
  std::cout << std::endl << "Min PWM (% * 100): " << AtomFanTable.usPWMMin;
  std::cout << std::endl << "Med PWM (% * 100): " << AtomFanTable.usPWMMed;
  std::cout << std::endl << "High PWM (% * 100): " << AtomFanTable.usPWMHigh;
  std::cout << std::endl << "Max PWM (%): " << AtomFanTable.usFanPWMMax;
  std::cout << std::endl << "Max RPM: " << AtomFanTable.usFanRPMMax;
  std::cout << std::endl << "Sensitivity: " << AtomFanTable.usFanOutputSensitivity;
  std::cout << std::endl << "Acoustic Limit (MHz * 100): " << AtomFanTable.ulMinFanSCLKAcousticLimit;
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
  if (FileSize < 524288)
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
  for (int i = 0; i < AtomSysClockTable.ucNumEntries; i++)
  {
      std::cout << std::endl << "(" << i << ")[ System Clock: " << AtomSysClockEntries[i].ulSclk / 100 <<
        " MHz, " << AtomVoltageEntries[AtomSysClockEntries[i].ucVddInd].usVdd << " MV ]";
  }
}

void Console::PrintDefaultAtomMemClockEntriesInfo(ATOM_MCLK_TABLE AtomMemClockTable, std::vector<ATOM_MCLK_ENTRY> AtomMemClockEntries)
{
  for (int i = 0; i < AtomMemClockTable.ucNumEntries; i++)
  {
    std::cout << std::endl << "(" << i << ")[ Memory Clock. MHz " << AtomMemClockEntries[i].ulMclk / 100;
    std::cout << ", Memory Clock. " << AtomMemClockEntries[i].usMvdd << " MV ] ";
  }
}

void Console::PrintDefaultAtomVramInfo(ATOM_VRAM_INFO AtomVramInfo, std::vector<ATOM_VRAM_ENTRY> AtomVramEntries)
{
  for (int i = 0; i < AtomVramInfo.ucNumOfVRAMModule; i++)
  {
    std::cout << std::endl << "(" << i << ")[VRAM Table " << i << " Name: " << AtomVramEntries[i].strMemPNString << "]";
  }
}

void Console::PrintDefaultAtomVramEntriesInfo(ATOM_VRAM_INFO AtomVramInfo, std::vector<ATOM_VRAM_ENTRY> AtomVramEntries)
{
  for (int i = 0; i < AtomVramInfo.ucNumOfVRAMModule; i++)
  {
    std::cout << std::endl << "(" << i << ")[VRAM Table " << i <<
    " -- VendorId: 0x" << std::hex << (int)AtomVramEntries[i].ucMemoryVenderID <<
    ", Size (MB): " << std::dec << (int)AtomVramEntries[i].usMemorySize <<
    ", Density: 0x"  << std::hex << (int)AtomVramEntries[i].ucDensity <<
    ", Type: 0x"  << std::hex << (int)AtomVramEntries[i].ucMemoryType << "]";
  }
}

void Console::PrintDefaultAtomVramTimingEntriesInfo(std::vector<ATOM_VRAM_TIMING_ENTRY> AtomVramTimingEntries)
{
  for (int i = 0; i < AtomVramTimingEntries.size(); i++)
  {
    DWORD table = AtomVramTimingEntries[i].ulClkRange >> 24;
    std::cout << std::endl << "(" << i << ")[{Table: " << std::to_string(table) << " , MHz: " << std::to_string((AtomVramTimingEntries[i].ulClkRange & 0x00FFFFFF) / 100);
    std::cout << "}, Timing Strap: " << ByteUtils::PrintByteArray(AtomVramTimingEntries[i].ucLatency, 48) << "]";
  }
}
