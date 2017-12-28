#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "mainapp.h"
#include "structs.h"

TEST_CASE( "DeviceId is correct", "[DeviceId]" ) {
  Buffer *buffer = new Buffer();
  RetrieveStruct* retriever = new RetrieveStruct();
  buffer->ReadFile("test.rom");
  std::vector<BYTE> bufferSubset;
  ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

	REQUIRE( atom_rom_header.usDeviceID == 0x67DF );
}

TEST_CASE( "File is loaded with correct size", "[VendorId]" ) {
    Buffer *buffer = new Buffer();
    RetrieveStruct* retriever = new RetrieveStruct();
    buffer->ReadFile("test.rom");
    std::vector<BYTE> bufferSubset;
    ATOM_ROM_HEADER atom_rom_header = retriever->AtomRomHeader(buffer);

    REQUIRE( atom_rom_header.usVendorID == 0x1002 );
}
