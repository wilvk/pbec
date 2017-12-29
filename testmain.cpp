#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "mainapp.h"
#include "structs.h"

TEST_CASE( "Vendor is valid", "[VendorId]" ) {
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  std::vector<BYTE> bufferSubset;
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.usVendorID == 0x1002 );
}

TEST_CASE( "Device Id is correct", "[DeviceId]" ) {
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

	REQUIRE( atom_rom_header.usDeviceID == 0x67DF );
}


TEST_CASE( "Subsystem Id is correct", "[SubsystemId]" ) {
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.usSubsystemID == 0x3418 );
}


TEST_CASE( "Subsystem Vendor Id is correct", "[SubsystemVendorId]" ) {
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.usSubsystemVendorID == 0x1462 );
}

TEST_CASE( "Firmware Signature is correct", "[SubsystemVendorId]" ) {
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

  REQUIRE( atom_rom_header.uaFirmWareSignature == 0x4D4F5441 );
}

TEST_CASE( "Max GPU Freq. (Hz):", "[SubsystemVendorId]" ) {
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);
  ATOM_DATA_TABLES atom_data_table = retriever->AtomDataTables(buffer, atom_rom_header.usMasterDataTableOffset);
  ATOM_POWERPLAY_TABLE atom_powerplay_table = retriever->AtomPowerplayTable(buffer, atom_data_table.PowerPlayInfo);

  REQUIRE( atom_powerplay_table.ulMaxODEngineClock == 2000000 );
}
