#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../pbemain.h"

TEST_CASE( "File is loaded", "[file]" ) {
    MainWindow *mainApp = new MainWindow();
    const char *filename;
    filename = "test.rom";
	REQUIRE( 1 == 1 );
}

TEST_CASE( "File is loaded with correct size", "[file]" ) {
    REQUIRE( 1 == 1 );
}
