#pragma once

//========================================================================
// This conversion was produced by the Free Edition of
// C# to C++ Converter courtesy of Tangible Software Solutions.
// Order the Premium Edition at https://www.tangiblesoftwaresolutions.com
//========================================================================

#include <string>
#include <vector>
#include <stack>
#include <stdexcept>
#include <functional>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include "exceptionhelper.h"
#include <cstdint>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace PolarisBiosEditor { class ATOM_MCLK_ENTRY; }
namespace PolarisBiosEditor { class ATOM_SCLK_ENTRY; }
namespace PolarisBiosEditor { class ATOM_VOLTAGE_ENTRY; }
namespace PolarisBiosEditor { class ATOM_VRAM_ENTRY; }
namespace PolarisBiosEditor { class ATOM_VRAM_TIMING_ENTRY; }

namespace PolarisBiosEditor
{

	struct ATOM_COMMON_TABLE_HEADER
	{
		int16_t usStructureSize;
		unsigned char ucTableFormatRevision;
		unsigned char ucTableContentRevision;
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
		unsigned char ucExtendedFunctionCode;
		unsigned char ucReserved;
		int32_t ulPSPDirTableOffset;
		int16_t usVendorID;
		int16_t usDeviceID;
	};

	class MainWindow
	{
	private:
		std::vector<unsigned char> buffer;
		Int32Converter *int32 = new Int32Converter();
		std::vector<std::wstring> supportedDeviceID = {L"67DF", L"1002"};
		std::wstring deviceID = L"";

		int atom_rom_checksum_offset = 0x21;
		int atom_rom_header_ptr = 0x48;
		int atom_rom_header_offset = 0;
		ATOM_ROM_HEADER atom_rom_header;
		ATOM_DATA_TABLES atom_data_table;

		int atom_powerplay_offset = 0;
		ATOM_POWERPLAY_TABLE atom_powerplay_table;

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

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_COMMON_TABLE_HEADER
//		unsafe struct ATOM_COMMON_TABLE_HEADER
//		{
//			Int16 usStructureSize;
//			Byte ucTableFormatRevision;
//			Byte ucTableContentRevision;
//		}

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_ROM_HEADER
//		unsafe struct ATOM_ROM_HEADER
//		{
//			public ATOM_COMMON_TABLE_HEADER sHeader;
//			public int32_t uaFirmWareSignature;
//			public int16_t usBiosRuntimeSegmentAddress;
//			public int16_t usProtectedModeInfoOffset;
//			public int16_t usConfigFilenameOffset;
//			public int16_t usCRC_BlockOffset;
//			public int16_t usBIOS_BootupMessageOffset;
//			public int16_t usInt10Offset;
//			public int16_t usPciBusDevInitCode;
//			public int16_t usIoBaseAddress;
//			public int16_t usSubsystemVendorID;
//			public int16_t usSubsystemID;
//			public int16_t usPCI_InfoOffset;
//			public int16_t usMasterCommandTableOffset;
//			public int16_t usMasterDataTableOffset;
//			public Byte ucExtendedFunctionCode;
//			public Byte ucReserved;
//			public int32_t ulPSPDirTableOffset;
//			public int16_t usVendorID;
//			public int16_t usDeviceID;
//		}

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_DATA_TABLES
//		unsafe struct ATOM_DATA_TABLES
//		{
//			public ATOM_COMMON_TABLE_HEADER sHeader;
//			public int16_t UtilityPipeLine;
//			public int16_t MultimediaCapabilityInfo;
//			public int16_t MultimediaConfigInfo;
//			public int16_t StandardVESA_Timing;
//			public int16_t FirmwareInfo;
//			public int16_t PaletteData;
//			public int16_t LCD_Info;
//			public int16_t DIGTransmitterInfo;
//			public int16_t SMU_Info;
//			public int16_t SupportedDevicesInfo;
//			public int16_t GPIO_I2C_Info;
//			public int16_t VRAM_UsageByFirmware;
//			public int16_t GPIO_Pin_LUT;
//			public int16_t VESA_ToInternalModeLUT;
//			public int16_t GFX_Info;
//			public int16_t PowerPlayInfo;
//			public int16_t GPUVirtualizationInfo;
//			public int16_t SaveRestoreInfo;
//			public int16_t PPLL_SS_Info;
//			public int16_t OemInfo;
//			public int16_t XTMDS_Info;
//			public int16_t MclkSS_Info;
//			public int16_t Object_Header;
//			public int16_t IndirectIOAccess;
//			public int16_t MC_InitParameter;
//			public int16_t ASIC_VDDC_Info;
//			public int16_t ASIC_InternalSS_Info;
//			public int16_t TV_VideoMode;
//			public int16_t VRAM_Info;
//			public int16_t MemoryTrainingInfo;
//			public int16_t IntegratedSystemInfo;
//			public int16_t ASIC_ProfilingInfo;
//			public int16_t VoltageObjectInfo;
//			public int16_t PowerSourceInfo;
//			public int16_t ServiceInfo;
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_POWERPLAY_TABLE
//		unsafe struct ATOM_POWERPLAY_TABLE
//		{
//			public ATOM_COMMON_TABLE_HEADER sHeader;
//			public Byte ucTableRevision;
//			public int16_t usTableSize;
//			public int32_t ulGoldenPPID;
//			public int32_t ulGoldenRevision;
//			public int16_t usFormatID;
//			public int16_t usVoltageTime;
//			public int32_t ulPlatformCaps;
//			public int32_t ulMaxODEngineClock;
//			public int32_t ulMaxODMemoryClock;
//			public int16_t usPowerControlLimit;
//			public int16_t usUlvVoltageOffset;
//			public int16_t usStateArrayOffset;
//			public int16_t usFanTableOffset;
//			public int16_t usThermalControllerOffset;
//			public int16_t usReserv;
//			public int16_t usMclkDependencyTableOffset;
//			public int16_t usSclkDependencyTableOffset;
//			public int16_t usVddcLookupTableOffset;
//			public int16_t usVddgfxLookupTableOffset;
//			public int16_t usMMDependencyTableOffset;
//			public int16_t usVCEStateTableOffset;
//			public int16_t usPPMTableOffset;
//			public int16_t usPowerTuneTableOffset;
//			public int16_t usHardLimitTableOffset;
//			public int16_t usPCIETableOffset;
//			public int16_t usGPIOTableOffset;
//			public fixed int16_t usReserved[6];
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_MCLK_ENTRY
//		unsafe struct ATOM_MCLK_ENTRY
//		{
//			public Byte ucVddcInd;
//			public int16_t usVddci;
//			public int16_t usVddgfxOffset;
//			public int16_t usMvdd;
//			public int32_t ulMclk;
//			public int16_t usReserved;
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_MCLK_TABLE
//		unsafe struct ATOM_MCLK_TABLE
//		{
//			public Byte ucRevId;
//			public Byte ucNumEntries;
//			// public ATOM_MCLK_ENTRY entries[ucNumEntries];
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_SCLK_ENTRY
//		unsafe struct ATOM_SCLK_ENTRY
//		{
//			public Byte ucVddInd;
//			public int16_t usVddcOffset;
//			public int32_t ulSclk;
//			public int16_t usEdcCurrent;
//			public Byte ucReliabilityTemperature;
//			public Byte ucCKSVOffsetandDisable;
//			public int32_t ulSclkOffset; // Polaris Only, remove for compatibility with Fiji
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_SCLK_TABLE
//		unsafe struct ATOM_SCLK_TABLE
//		{
//			public Byte ucRevId;
//			public Byte ucNumEntries;
//			// public ATOM_SCLK_ENTRY entries[ucNumEntries];
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_VOLTAGE_ENTRY
//		unsafe struct ATOM_VOLTAGE_ENTRY
//		{
//			public int16_t usVdd;
//			public int16_t usCACLow;
//			public int16_t usCACMid;
//			public int16_t usCACHigh;
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_VOLTAGE_TABLE
//		unsafe struct ATOM_VOLTAGE_TABLE
//		{
//			public Byte ucRevId;
//			public Byte ucNumEntries;
//			// public ATOM_VOLTAGE_ENTRY entries[ucNumEntries];
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_FAN_TABLE
//		unsafe struct ATOM_FAN_TABLE
//		{
//			public Byte ucRevId;
//			public Byte ucTHyst;
//			public int16_t usTMin;
//			public int16_t usTMed;
//			public int16_t usTHigh;
//			public int16_t usPWMMin;
//			public int16_t usPWMMed;
//			public int16_t usPWMHigh;
//			public int16_t usTMax;
//			public Byte ucFanControlMode;
//			public int16_t usFanPWMMax;
//			public int16_t usFanOutputSensitivity;
//			public int16_t usFanRPMMax;
//			public int32_t ulMinFanSCLKAcousticLimit;
//			public Byte ucTargetTemperature;
//			public Byte ucMinimumPWMLimit;
//			public int16_t usFanGainEdge;
//			public int16_t usFanGainHotspot;
//			public int16_t usFanGainLiquid;
//			public int16_t usFanGainVrVddc;
//			public int16_t usFanGainVrMvdd;
//			public int16_t usFanGainPlx;
//			public int16_t usFanGainHbm;
//			public int16_t usReserved;
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_POWERTUNE_TABLE
//		unsafe struct ATOM_POWERTUNE_TABLE
//		{
//			public Byte ucRevId;
//			public int16_t usTDP;
//			public int16_t usConfigurableTDP;
//			public int16_t usTDC;
//			public int16_t usBatteryPowerLimit;
//			public int16_t usSmallPowerLimit;
//			public int16_t usLowCACLeakage;
//			public int16_t usHighCACLeakage;
//			public int16_t usMaximumPowerDeliveryLimit;
//			public int16_t usTjMax;
//			public int16_t usPowerTuneDataSetID;
//			public int16_t usEDCLimit;
//			public int16_t usSoftwareShutdownTemp;
//			public int16_t usClockStretchAmount;
//			public int16_t usTemperatureLimitHotspot;
//			public int16_t usTemperatureLimitLiquid1;
//			public int16_t usTemperatureLimitLiquid2;
//			public int16_t usTemperatureLimitVrVddc;
//			public int16_t usTemperatureLimitVrMvdd;
//			public int16_t usTemperatureLimitPlx;
//			public Byte ucLiquid1_I2C_address;
//			public Byte ucLiquid2_I2C_address;
//			public Byte ucLiquid_I2C_Line;
//			public Byte ucVr_I2C_address;
//			public Byte ucVr_I2C_Line;
//			public Byte ucPlx_I2C_address;
//			public Byte ucPlx_I2C_Line;
//			public int16_t usReserved;
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_VRAM_TIMING_ENTRY
//		unsafe struct ATOM_VRAM_TIMING_ENTRY
//		{
//			public int32_t ulClkRange;
//			[MarshalAs(UnmanagedType.ByValArray, SizeConst = 0x30)] public Byte[] ucLatency;
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_VRAM_ENTRY
//		unsafe struct ATOM_VRAM_ENTRY
//		{
//			public int32_t ulChannelMapCfg;
//			public int16_t usModuleSize;
//			public int16_t usMcRamCfg;
//			public int16_t usEnableChannels;
//			public Byte ucExtMemoryID;
//			public Byte ucMemoryType;
//			public Byte ucChannelNum;
//			public Byte ucChannelWidth;
//			public Byte ucDensity;
//			public Byte ucBankCol;
//			public Byte ucMisc;
//			public Byte ucVREFI;
//			public int16_t usReserved;
//			public int16_t usMemorySize;
//			public Byte ucMcTunningSetId;
//			public Byte ucRowNum;
//			public int16_t usEMRS2Value;
//			public int16_t usEMRS3Value;
//			public Byte ucMemoryVenderID;
//			public Byte ucRefreshRateFactor;
//			public Byte ucFIFODepth;
//			public Byte ucCDR_Bandwidth;
//			public int32_t ulChannelMapCfg1;
//			public int32_t ulBankMapCfg;
//			public int32_t ulReserved;
//			[MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)] public Byte[] strMemPNString;
//		};

//C# TO C++ CONVERTER TODO TASK: C# 'unsafe' code is not converted by C# to C++ Converter:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//ORIGINAL LINE: [StructLayout(LayoutKind.Sequential, Pack = 1)] unsafe struct ATOM_VRAM_INFO
//		unsafe struct ATOM_VRAM_INFO
//		{
//			public ATOM_COMMON_TABLE_HEADER sHeader;
//			public int16_t usMemAdjustTblOffset;
//			public int16_t usMemClkPatchTblOffset;
//			public int16_t usMcAdjustPerTileTblOffset;
//			public int16_t usMcPhyInitTableOffset;
//			public int16_t usDramDataRemapTblOffset;
//			public int16_t usReserved1;
//			public Byte ucNumOfVRAMModule;
//			public Byte ucMemoryClkPatchTblVer;
//			public Byte ucVramModuleVer;
//			public Byte ucMcPhyTileNum;
//			// public ATOM_VRAM_ENTRY aVramInfo[ucNumOfVRAMModule];
//		}

	public:
		virtual ~MainWindow()
		{
			delete int32;
		}

	private:
		static std::vector<unsigned char> getBytes(void *obj);

		template<typename T>
		static T fromBytes(std::vector<unsigned char> &arr);

	public:
		template<typename T>
		std::wstring GetPropertyName(Expression<std::function<T()>*> *propertyLambda);

		void setBytesAtPosition(std::vector<unsigned char> &dest, int ptr, std::vector<unsigned char> &src);

		MainWindow();

	private:
		void OpenFileDialog_Click(void *sender, RoutedEventArgs *e);

	public:
		int getValueAtPosition(int bits, int position, bool isFrequency = false);

		bool setValueAtPosition(int value, int bits, int position, bool isFrequency = false);

	private:
		bool setValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency = false);

		void SaveFileDialog_Click(void *sender, RoutedEventArgs *e);

		void fixChecksum(bool save);

		FrameworkElement *FindByName(const std::wstring &name, FrameworkElement *root);

	public:
		static std::wstring ByteArrayToString(std::vector<unsigned char> &ba);

		static std::vector<unsigned char> StringToByteArray(const std::wstring &hex);

		void updateVRAM_entries();

	private:
		void listVRAM_SelectionChanged(void *sender, SelectionChangedEventArgs *e);
	};
}
