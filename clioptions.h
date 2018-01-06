#pragma once

#include <iostream>
#include "CLI11.hpp"
#include "appdata.h"
#include "console.h"

class CliOptions
{

private:

  CLI::App *app;

  AppData *appData;

  bool summary;
  
  bool verbose;

  bool attributes;

  std::string inputFileName;
  
  std::string outputFileName;
  
  std::string attributeToSet;
  
  std::string newAttributeValue;
  
  std::string copyStrapFrom;
  
  std::vector<std::string> copyStrapTo;

  std::string readArea;

  void setCliOptions();

  void loadInputFile();

  void printSummary();

  void printVerbose();

  void printAttributes();

  void printHelp(int argc);

public:

  int ParseCommandLine(int argc, char** argv);

};
