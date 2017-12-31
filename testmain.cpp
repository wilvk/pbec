#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "mainapp.h"
#include "structs.h"

// atom rom header

TEST_CASE( "Vendor is valid", "[VendorId]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  std::vector<BYTE> bufferSubset;
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.usVendorID == 0x1002 );
}

TEST_CASE( "Device Id is correct", "[DeviceId]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

	REQUIRE( atom_rom_header.usDeviceID == 0x67DF );
}

TEST_CASE( "Subsystem Id is correct", "[SubsystemId]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.usSubsystemID == 0x3418 );
}

TEST_CASE( "Subsystem Vendor Id is correct", "[SubsystemVendorId]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.usSubsystemVendorID == 0x1462 );
}

TEST_CASE( "Firmware Signature is correct", "[SubsystemVendorId]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.uaFirmWareSignature == 0x4D4F5441 );
}

// powerplay

TEST_CASE( "Max GPU Freq. (x10 Hz):", "[ulMaxODEngineClock]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);

  REQUIRE( atom_powerplay_table.ulMaxODEngineClock == 200000 );
}

TEST_CASE( "Max Memory Freq.:", "[ulMaxODMemoryClock]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);

  REQUIRE( atom_powerplay_table.ulMaxODMemoryClock == 225000 );
}

TEST_CASE( "Power Control Limit (%):", "[usPowerControlLimit]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);

  REQUIRE( atom_powerplay_table.usPowerControlLimit == 50 );
}

// powertune

TEST_CASE( "TDP (W):", "[usTDP]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));

  REQUIRE( atom_powertune_table.usTDP == 145 );
}

TEST_CASE( "TDC (A):", "[usTDC]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));

  REQUIRE( atom_powertune_table.usTDC == 132 );
}

TEST_CASE( "Max Power Limit (W):", "[usMaximumPowerDeliveryLimit]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));

  REQUIRE( atom_powertune_table.usMaximumPowerDeliveryLimit == 135 );
}

TEST_CASE( "Max Temp. (C):", "[usTjMax]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));

  REQUIRE( atom_powertune_table.usTjMax == 90 );
}

TEST_CASE( "Shutdown Temp. (C):", "[usSoftwareShutdownTemp]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));

  REQUIRE( atom_powertune_table.usSoftwareShutdownTemp == 94 );
}

TEST_CASE( "Hotspot Temp. (C):", "[usTemperatureLimitHotspot]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));

  REQUIRE( atom_powertune_table.usTemperatureLimitHotspot == 105 );
}

//  atom_fan_table

TEST_CASE( "Temp. Hysteresis:", "[ucTHyst]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.ucTHyst == 3 );
}

TEST_CASE( "Min Temp. (C * 100)", "[usTMin]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usTMin == 4000 );
}

TEST_CASE( "Med Temp. (C * 100):", "[usTMed]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usTMed == 6500 );
}

TEST_CASE( "High Temp. (C * 100):", "[usTHigh]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usTHigh == 8500 );
}

TEST_CASE( "Max Temp. (C * 100):", "[usTMax]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usTMax == 10900 );
}

TEST_CASE( "Min PWM (% * 100):", "[usPWMMin]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usPWMMin == 2000 );
}

TEST_CASE( "Med PWM (% * 100):", "[usPWMMed]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usPWMMed == 4000 );
}

TEST_CASE( "High PWM (% * 100):", "[usPWMHigh]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usPWMHigh == 6000 );
}

TEST_CASE( "Max PWM (%):", "[usFanPWMMax]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usFanPWMMax == 100 );
}

TEST_CASE( "Max RPM:", "[usFanRPMMax]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usFanRPMMax == 3000 );
}

TEST_CASE( "Sensitivity:", "[usFanOutputSensitivity]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.usFanOutputSensitivity == 4836 );
}

TEST_CASE( "Acoustic Limit (MHz * 100):", "[ulMinFanSCLKAcousticLimit]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.ulMinFanSCLKAcousticLimit == 91800 );
}

TEST_CASE( "Acoustic Limit (MHz * 100):", "[ulMinFanSCLKAcousticLimit]" )
{
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);
  ATOM_POWERTUNE_TABLE atom_powertune_table = retriever->AtomPowertuneTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usPowerTuneTableOffset));
  ATOM_FAN_TABLE atom_fan_table = retriever->AtomFanTable(buffer, (atom_data_table.PowerPlayInfo + atom_powerplay_table.usFanTableOffset));

  REQUIRE( atom_fan_table.ulMinFanSCLKAcousticLimit == 91800 );
}
