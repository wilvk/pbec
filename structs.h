#ifndef STRUCTS_H
#define STRUCTS_H

typedef unsigned char BYTE;

struct ATOM_COMMON_TABLE_HEADER
{
	int16_t usStructureSize;
	BYTE ucTableFormatRevision;
	BYTE ucTableContentRevision;
};

struct ATOM_ROM_HEADER
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	int32_t uaFirmWareSignature;
	int16_t usBiosRuntimeSegmentAddress;
	int16_t usProtectedModeInfoOffset;
	int16_t usConfigFilenameOffset;
	int16_t usCRC_BlockOffset;
	int16_t usBIOS_BootupMessageOffset;
	int16_t usInt10Offset;
	int16_t usPciBusDevInitCode;
	int16_t usIoBaseAddress;
	int16_t usSubsystemVendorID;
	int16_t usSubsystemID;
	int16_t usPCI_InfoOffset;
	int16_t usMasterCommandTableOffset;
	int16_t usMasterDataTableOffset;
	BYTE ucExtendedFunctionCode;
	BYTE ucReserved;
	int32_t ulPSPDirTableOffset;
	int16_t usVendorID;
	int16_t usDeviceID;
};

struct ATOM_DATA_TABLES
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	int16_t UtilityPipeLine;
	int16_t MultimediaCapabilityInfo;
	int16_t MultimediaConfigInfo;
	int16_t StandardVESA_Timing;
	int16_t FirmwareInfo;
	int16_t PaletteData;
	int16_t LCD_Info;
	int16_t DIGTransmitterInfo;
	int16_t SMU_Info;
	int16_t SupportedDevicesInfo;
	int16_t GPIO_I2C_Info;
	int16_t VRAM_UsageByFirmware;
	int16_t GPIO_Pin_LUT;
	int16_t VESA_ToInternalModeLUT;
	int16_t GFX_Info;
	int16_t PowerPlayInfo;
	int16_t GPUVirtualizationInfo;
	int16_t SaveRestoreInfo;
	int16_t PPLL_SS_Info;
	int16_t OemInfo;
	int16_t XTMDS_Info;
	int16_t MclkSS_Info;
	int16_t Object_Header;
	int16_t IndirectIOAccess;
	int16_t MC_InitParameter;
	int16_t ASIC_VDDC_Info;
	int16_t ASIC_InternalSS_Info;
	int16_t TV_VideoMode;
	int16_t VRAM_Info;
	int16_t MemoryTrainingInfo;
	int16_t IntegratedSystemInfo;
	int16_t ASIC_ProfilingInfo;
	int16_t VoltageObjectInfo;
	int16_t PowerSourceInfo;
	int16_t ServiceInfo;
};

struct ATOM_POWERPLAY_TABLE
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	BYTE ucTableRevision;
	int16_t usTableSize;
	int32_t ulGoldenPPID;
	int32_t ulGoldenRevision;
	int16_t usFormatID;
	int16_t usVoltageTime;
	int32_t ulPlatformCaps;
	int32_t ulMaxODEngineClock;
	int32_t ulMaxODMemoryClock;
	int16_t usPowerControlLimit;
	int16_t usUlvVoltageOffset;
	int16_t usStateArrayOffset;
	int16_t usFanTableOffset;
	int16_t usThermalControllerOffset;
	int16_t usReserv;
	int16_t usMclkDependencyTableOffset;
	int16_t usSclkDependencyTableOffset;
	int16_t usVddcLookupTableOffset;
	int16_t usVddgfxLookupTableOffset;
	int16_t usMMDependencyTableOffset;
	int16_t usVCEStateTableOffset;
	int16_t usPPMTableOffset;
	int16_t usPowerTuneTableOffset;
	int16_t usHardLimitTableOffset;
	int16_t usPCIETableOffset;
	int16_t usGPIOTableOffset;
	int16_t usReserved[6];
};


struct ATOM_MCLK_ENTRY
{
	BYTE ucVddcInd;
	int16_t usVddci;
	int16_t usVddgfxOffset;
	int16_t usMvdd;
	int32_t ulMclk;
	int16_t usReserved;
};

struct ATOM_MCLK_TABLE
{
	BYTE ucRevId;
	BYTE ucNumEntries;
	// ATOM_MCLK_ENTRY entries[ucNumEntries];
};

struct ATOM_SCLK_ENTRY
{
	BYTE ucVddInd;
	int16_t usVddcOffset;
	int32_t ulSclk;
	int16_t usEdcCurrent;
	BYTE ucReliabilityTemperature;
	BYTE ucCKSVOffsetandDisable;
	int32_t ulSclkOffset; // Polaris Only, remove for compatibility with Fiji
};

struct ATOM_SCLK_TABLE
{
	BYTE ucRevId;
	BYTE ucNumEntries;
	// ATOM_SCLK_ENTRY entries[ucNumEntries];
};

struct ATOM_VOLTAGE_ENTRY
{
	int16_t usVdd;
	int16_t usCACLow;
	int16_t usCACMid;
	int16_t usCACHigh;
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
	int16_t usTMin;
	int16_t usTMed;
	int16_t usTHigh;
	int16_t usPWMMin;
	int16_t usPWMMed;
	int16_t usPWMHigh;
	int16_t usTMax;
	BYTE ucFanControlMode;
	int16_t usFanPWMMax;
	int16_t usFanOutputSensitivity;
	int16_t usFanRPMMax;
	int32_t ulMinFanSCLKAcousticLimit;
	BYTE ucTargetTemperature;
	BYTE ucMinimumPWMLimit;
	int16_t usFanGainEdge;
	int16_t usFanGainHotspot;
	int16_t usFanGainLiquid;
	int16_t usFanGainVrVddc;
	int16_t usFanGainVrMvdd;
	int16_t usFanGainPlx;
	int16_t usFanGainHbm;
	int16_t usReserved;
};

struct ATOM_POWERTUNE_TABLE
{
	BYTE ucRevId;
	int16_t usTDP;
	int16_t usConfigurableTDP;
	int16_t usTDC;
	int16_t usBatteryPowerLimit;
	int16_t usSmallPowerLimit;
	int16_t usLowCACLeakage;
	int16_t usHighCACLeakage;
	int16_t usMaximumPowerDeliveryLimit;
	int16_t usTjMax;
	int16_t usPowerTuneDataSetID;
	int16_t usEDCLimit;
	int16_t usSoftwareShutdownTemp;
	int16_t usClockStretchAmount;
	int16_t usTemperatureLimitHotspot;
	int16_t usTemperatureLimitLiquid1;
	int16_t usTemperatureLimitLiquid2;
	int16_t usTemperatureLimitVrVddc;
	int16_t usTemperatureLimitVrMvdd;
	int16_t usTemperatureLimitPlx;
	BYTE ucLiquid1_I2C_address;
	BYTE ucLiquid2_I2C_address;
	BYTE ucLiquid_I2C_Line;
	BYTE ucVr_I2C_address;
	BYTE ucVr_I2C_Line;
	BYTE ucPlx_I2C_address;
	BYTE ucPlx_I2C_Line;
	int16_t usReserved;
};

struct ATOM_VRAM_TIMING_ENTRY
{
	int32_t ulClkRange;
	BYTE ucLatency[48];
};

struct ATOM_VRAM_ENTRY
{
	int32_t ulChannelMapCfg;
	int16_t usModuleSize;
	int16_t usMcRamCfg;
	int16_t usEnableChannels;
	BYTE ucExtMemoryID;
	BYTE ucMemoryType;
	BYTE ucChannelNum;
	BYTE ucChannelWidth;
	BYTE ucDensity;
	BYTE ucBankCol;
	BYTE ucMisc;
	BYTE ucVREFI;
	int16_t usReserved;
	int16_t usMemorySize;
	BYTE ucMcTunningSetId;
	BYTE ucRowNum;
	int16_t usEMRS2Value;
	int16_t usEMRS3Value;
	BYTE ucMemoryVenderID;
	BYTE ucRefreshRateFactor;
	BYTE ucFIFODepth;
	BYTE ucCDR_Bandwidth;
	int32_t ulChannelMapCfg1;
	int32_t ulBankMapCfg;
	int32_t ulReserved;
	BYTE strMemPNString[20];
};

struct ATOM_VRAM_INFO
{
	ATOM_COMMON_TABLE_HEADER sHeader;
	int16_t usMemAdjustTblOffset;
	int16_t usMemClkPatchTblOffset;
	int16_t usMcAdjustPerTileTblOffset;
	int16_t usMcPhyInitTableOffset;
	int16_t usDramDataRemapTblOffset;
	int16_t usReserved1;
	BYTE ucNumOfVRAMModule;
	BYTE ucMemoryClkPatchTblVer;
	BYTE ucVramModuleVer;
	BYTE ucMcPhyTileNum;
	// ATOM_VRAM_ENTRY aVramInfo[ucNumOfVRAMModule];
};


#endif /* end of include guard: STRUCTS_H */
