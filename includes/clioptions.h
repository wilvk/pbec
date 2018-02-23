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
    int copyStrapFrom;
    std::vector<int> copyStrapTo;
    std::string readArea;

    void setCliOptions();
    void loadInputFile();
    void printSummary();
    void printVerbose();
    void printAttributes();
    void printHelp(int argc);
    void writeTimingStraps();

public:

    int ParseCommandLine(int argc, char** argv);

};
