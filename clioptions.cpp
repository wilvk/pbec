#include "clioptions.h"

int CliOptions::ParseCommandLine(ArgumentParser Parser)
{
  std::string inputFile = Parser.retrieve<std::string>("inputFile");
  // bool listValue = Parser.retrieve<bool>("help");
  // bool printSummary = Parser.retrieve<bool>("summary");
  // bool printVerbose = Parser.retrieve<bool>("verbose");
  // bool printSectionNames = Parser.retrieve<bool>("printSectionNames");
  // bool printValueNames = Parser.retrieve<bool>("printValueNames");
  // std::string printSectionDetails = Parser.retrieve<std::string>("printSectionDetails");

  if(inputFile.empty())
  {
    std::cout << "ERROR: No Input File Specified." << std::endl << "Please specify an input file with the --inputFile switch.";
    //return 1;
    inputFile = "test.rom";
  }

  AppData *appData = new AppData();
  appData->OpenFile(inputFile);

  return 0;
}
