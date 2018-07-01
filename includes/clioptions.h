#pragma once

#include <iostream>
#include "CLI11.hpp"
#include "appdata.h"

class CliOptions
{

private:

    CLI::App *app;
    CLI::Option* optSummary;
    CLI::Option* optFull;
    CLI::Option* optAttributes;
    CLI::Option* optInputFileName;
    CLI::Option* optOutputFileName;
    CLI::Option* optAttributeToSet;
    CLI::Option* optNewAttributeValue;
    CLI::Option* optCopyStrapFrom;
    CLI::Option* optCopyStrapTo;
    CLI::Option* optReadArea;

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
    void setDefaultReadArea();
    void setOptionDependencies();
    void loadInputFile();
    void printSummary();
    void printVerbose();
    void printAttributes();
    void printHelp(int argc);
    void writeTimingStraps();

public:

    int ParseCommandLine(int argc, char** argv);

};
