#ifndef STRUCTS_H
#define STRUCTS_H

#include "typedefs.h"

struct ATOM_COMMON_TABLE_HEADER
{
	WORD usStructureSize;
	BYTE ucTableFormatRevision;
	BYTE ucTableContentRevision;
};

struct ATOM_ROM_HEADER
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	DWORD uaFirmWareSignature;
	WORD usBiosRuntimeSegmentAddress;
	WORD usProtectedModeInfoOffset;
	WORD usConfigFilenameOffset;
	WORD usCRC_BlockOffset;
	WORD usBIOS_BootupMessageOffset;
	WORD usInt10Offset;
	WORD usPciBusDevInitCode;
	WORD usIoBaseAddress;
	WORD usSubsystemVendorID;
	WORD usSubsystemID;
	WORD usPCI_InfoOffset;
	WORD usMasterCommandTableOffset;
	WORD usMasterDataTableOffset;
	BYTE ucExtendedFunctionCode;
	BYTE ucReserved;
	DWORD ulPSPDirTableOffset;
	WORD usVendorID;
	WORD usDeviceID;
};

struct ATOM_DATA_TABLES
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	WORD UtilityPipeLine;
	WORD MultimediaCapabilityInfo;
	WORD MultimediaConfigInfo;
	WORD StandardVESA_Timing;
	WORD FirmwareInfo;
	WORD PaletteData;
	WORD LCD_Info;
	WORD DIGTransmitterInfo;
	WORD SMU_Info;
	WORD SupportedDevicesInfo;
	WORD GPIO_I2C_Info;
	WORD VRAM_UsageByFirmware;
	WORD GPIO_Pin_LUT;
	WORD VESA_ToInternalModeLUT;
	WORD GFX_Info;
	WORD PowerPlayInfo;
	WORD GPUVirtualizationInfo;
	WORD SaveRestoreInfo;
	WORD PPLL_SS_Info;
	WORD OemInfo;
	WORD XTMDS_Info;
	WORD MclkSS_Info;
	WORD Object_Header;
	WORD IndirectIOAccess;
	WORD MC_InitParameter;
	WORD ASIC_VDDC_Info;
	WORD ASIC_InternalSS_Info;
	WORD TV_VideoMode;
	WORD VRAM_Info;
	WORD MemoryTrainingInfo;
	WORD IntegratedSystemInfo;
	WORD ASIC_ProfilingInfo;
	WORD VoltageObjectInfo;
	WORD PowerSourceInfo;
	WORD ServiceInfo;
};

struct ATOM_POWERPLAY_TABLE
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	BYTE ucTableRevision;
	WORD usTableSize;
	DWORD ulGoldenPPID;
	DWORD ulGoldenRevision;
	WORD usFormatID;
	WORD usVoltageTime;
	DWORD ulPlatformCaps;
	DWORD ulMaxODEngineClock;
	DWORD ulMaxODMemoryClock;
	WORD usPowerControlLimit;
	WORD usUlvVoltageOffset;
	WORD usStateArrayOffset;
	WORD usFanTableOffset;
	WORD usThermalControllerOffset;
	WORD usReserv;
	WORD usMclkDependencyTableOffset;
	WORD usSclkDependencyTableOffset;
	WORD usVddcLookupTableOffset;
	WORD usVddgfxLookupTableOffset;
	WORD usMMDependencyTableOffset;
	WORD usVCEStateTableOffset;
	WORD usPPMTableOffset;
	WORD usPowerTuneTableOffset;
	WORD usHardLimitTableOffset;
	WORD usPCIETableOffset;
	WORD usGPIOTableOffset;
	WORD usReserved[6];
};


struct ATOM_MCLK_ENTRY
{
	BYTE ucVddcInd;
	WORD usVddci;
	WORD usVddgfxOffset;
	WORD usMvdd;
	DWORD ulMclk;
	WORD usReserved;
};

struct ATOM_MCLK_TABLE
{
	BYTE ucRevId;
	BYTE ucNumEntries;
	//ATOM_MCLK_ENTRY entries[ucNumEntries];
};

struct ATOM_SCLK_ENTRY
{
	BYTE ucVddInd;
	WORD usVddcOffset;
	DWORD ulSclk;
	WORD usEdcCurrent;
	BYTE ucReliabilityTemperature;
	BYTE ucCKSVOffsetandDisable;
	DWORD ulSclkOffset; // Polaris Only, remove for compatibility with Fiji
};

struct ATOM_SCLK_TABLE
{
	BYTE ucRevId;
	BYTE ucNumEntries;
	// ATOM_SCLK_ENTRY entries[ucNumEntries];
};

struct ATOM_VOLTAGE_ENTRY
{
	WORD usVdd;
	WORD usCACLow;
	WORD usCACMid;
	WORD usCACHigh;
};

struct ATOM_VOLTAGE_TABLE
{
	BYTE ucRevId;
	BYTE ucNumEntries;
	// ATOM_VOLTAGE_ENTRY entries[ucNumEntries];
};

struct ATOM_FAN_TABLE
{
	BYTE ucRevId;
	BYTE ucTHyst;
	WORD usTMin;
	WORD usTMed;
	WORD usTHigh;
	WORD usPWMMin;
	WORD usPWMMed;
	WORD usPWMHigh;
	WORD usTMax;
	BYTE ucFanControlMode;
	WORD usFanPWMMax;
	WORD usFanOutputSensitivity;
	WORD usFanRPMMax;
	DWORD ulMinFanSCLKAcousticLimit;
	BYTE ucTargetTemperature;
	BYTE ucMinimumPWMLimit;
	WORD usFanGainEdge;
	WORD usFanGainHotspot;
	WORD usFanGainLiquid;
	WORD usFanGainVrVddc;
	WORD usFanGainVrMvdd;
	WORD usFanGainPlx;
	WORD usFanGainHbm;
	WORD usReserved;
};

struct ATOM_POWERTUNE_TABLE
{
	BYTE ucRevId;
	WORD usTDP;
	WORD usConfigurableTDP;
	WORD usTDC;
	WORD usBatteryPowerLimit;
	WORD usSmallPowerLimit;
	WORD usLowCACLeakage;
	WORD usHighCACLeakage;
	WORD usMaximumPowerDeliveryLimit;
	WORD usTjMax;
	WORD usPowerTuneDataSetID;
	WORD usEDCLimit;
	WORD usSoftwareShutdownTemp;
	WORD usClockStretchAmount;
	WORD usTemperatureLimitHotspot;
	WORD usTemperatureLimitLiquid1;
	WORD usTemperatureLimitLiquid2;
	WORD usTemperatureLimitVrVddc;
	WORD usTemperatureLimitVrMvdd;
	WORD usTemperatureLimitPlx;
	BYTE ucLiquid1_I2C_address;
	BYTE ucLiquid2_I2C_address;
	BYTE ucLiquid_I2C_Line;
	BYTE ucVr_I2C_address;
	BYTE ucVr_I2C_Line;
	BYTE ucPlx_I2C_address;
	BYTE ucPlx_I2C_Line;
	WORD usReserved;
};

struct ATOM_VRAM_TIMING_ENTRY
{
	DWORD ulClkRange;
	BYTE ucLatency[48];
};

struct ATOM_VRAM_ENTRY
{
	DWORD ulChannelMapCfg;
	WORD usModuleSize;
	WORD usMcRamCfg;
	WORD usEnableChannels;
	BYTE ucExtMemoryID;
	BYTE ucMemoryType;
	BYTE ucChannelNum;
	BYTE ucChannelWidth;
	BYTE ucDensity;
	BYTE ucBankCol;
	BYTE ucMisc;
	BYTE ucVREFI;
	WORD usReserved;
	WORD usMemorySize;
	BYTE ucMcTunningSetId;
	BYTE ucRowNum;
	WORD usEMRS2Value;
	WORD usEMRS3Value;
	BYTE ucMemoryVenderID;
	BYTE ucRefreshRateFactor;
	BYTE ucFIFODepth;
	BYTE ucCDR_Bandwidth;
	DWORD ulChannelMapCfg1;
	DWORD ulBankMapCfg;
	DWORD ulReserved;
	BYTE strMemPNString[20];
};

struct ATOM_VRAM_INFO
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	WORD usMemAdjustTblOffset;
	WORD usMemClkPatchTblOffset;
	WORD usMcAdjustPerTileTblOffset;
	WORD usMcPhyInitTableOffset;
	WORD usDramDataRemapTblOffset;
	WORD usReserved1;
	BYTE ucNumOfVRAMModule;
	BYTE ucMemoryClkPatchTblVer;
	BYTE ucVramModuleVer;
	BYTE ucMcPhyTileNum;
	// ATOM_VRAM_ENTRY aVramInfo[ucNumOfVRAMModule];
};

#endif /* end of include guard: STRUCTS_H */
