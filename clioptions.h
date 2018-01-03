#pragma once

#include <iostream>
#include "CLI11.hpp"
#include "appdata.h"

class CliOptions
{

private:

  CLI::App *app;

  AppData *appData;

  bool summary;
  
  bool verbose;
  
  bool printSectionNames;
  
  bool printAttributeNames;
  
  std::string inputFileName;
  
  std::string outputFileName;
  
  std::string sectionToPrint;
  
  std::string attributeToSet;
  
  std::string newAttributeValue;
  
  std::string copyStrapFrom;
  
  std::vector<std::string> copyStrapTo;

  void setCliOptions();

  void loadInputFile();

  void printSummary();

  void printVerbose();
public:

  int ParseCommandLine(int argc, char** argv);

};
