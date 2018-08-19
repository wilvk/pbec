#include "headers.h"

int CliOptions::ParseCommandLine(int argc, char** argv)
{
  app = new CLI::App("Polaris Bios Editor for the Console (PBEC)");
  setCliOptions();
  setOptionDependencies();
  setDefaultReadArea();
  CLI11_PARSE(*app, argc, argv);
  printHelp(argc);
  printAttributes();
  loadInputFile();
  printSummary();
  printVerbose();
  writeTimingStraps();
  return 0;
}

void CliOptions::printHelp(int argc)
{
  if(argc == 1)
  {
    std::cout << app->help();
  }
}

void CliOptions::loadInputFile()
{
  if(!inputFileName.empty())
  {
    appData = new AppData();
    appData->OpenFile(inputFileName);
  }
}

void CliOptions::setDefaultReadArea()
{
  if(readArea == "")
  {
    readArea = "ALL";
  }
}

void CliOptions::printSummary()
{
  if(summary)
  {
    appData->PrintSummary(readArea);
  }
}

void CliOptions::printVerbose()
{
  if(verbose)
  {
    appData->PrintVerbose(readArea);
  }
}

void CliOptions::printAttributes()
{
  if(attributes)
  {
    Console::PrintAttributes();
  }
}

void CliOptions::writeTimingStraps()
{
  if(copyStrapTo.size() > 0)
  {
    if(copyStrapFrom >= 0)
    {
      appData->SetTimingStraps(copyStrapFrom, copyStrapTo);
    }
    else if(insertStrapData.length() > 0)
    {
      appData->SetTimingStraps(insertStrapData, copyStrapTo);
    }
    appData->WriteTimingStrapsToBuffer();
    appData->WriteBufferToFile(outputFileName);
  }
}

void CliOptions::setCliOptions()
{
  optSummary =           app->add_flag("--summary,-s", summary, "Print summary details of the ROM image")
                           ->group("File Read")
                           ->ignore_case();
  optFull =              app->add_flag("--full,-f", verbose, "Print verbose details of the ROM image")->group("File Read")
                           ->ignore_case();
  optAttributes =        app->add_flag("--attributes,-t", attributes, "Print a list of attributes that can be modified")
                           ->group("Information")
                           ->ignore_case();
  optInputFileName =     app->add_option("--inputFile,-i", inputFileName, "Specifies the input ROM image filename")
                           ->expected(1)
                           ->check(CLI::ExistingFile)
                           ->group("File Read/Write")
                           ->ignore_case();
  optOutputFileName =    app->add_option("--outputFile,-o", outputFileName, "Specifies the output ROM image filename")
                           ->expected(1)
                           ->group("File Write")
                           ->ignore_case();
  optAttributeToSet =    app->add_option("--setAttribute,-a", attributeToSet, "Specify the name of the attribute to set")
                           ->expected(1)
                           ->group("File Write")
                           ->ignore_case();
  optNewAttributeValue = app->add_option("--setValue,-v", newAttributeValue, "Specify the value for the attribute specified with -s")
                           ->expected(1)
                           ->group("File Write")
                           ->ignore_case();
  optInsertStrapData   = app->add_option("--insertStrapData,-n", insertStrapData, "Specify a string of values to insert as a timing strap")
                           ->expected(1)
                           ->group("File Write")
                           ->ignore_case();
  optCopyStrapFrom =     app->add_option("--copyStrapFrom,-c", copyStrapFrom, "Specify the array number of the timing strap to copy from")
                           ->expected(1)
                           ->group("File Write")
                           ->ignore_case();
  optCopyStrapTo =       app->add_option("--copyStrapTo,-p", copyStrapTo, "Specify the array number(s) of the timing strap to copy to")
                           ->group("File Write")
                           ->ignore_case();
  optReadArea =          app->add_set("-r,--readArea", readArea,
                           { "ALL",
                             "HEADER",
                             "DATA",
                             "POWERPLAY",
                             "POWERTUNE",
                             "FAN",
                             "SYSTEM_CLOCK",
                             "MEMORY_CLOCK",
                             "VRAM_INFO",
                             "VRAM_TIMING",
                             "STRINGS"
                            },
                              "",
                              "ALL" )
                          ->group("File Read");
}

void CliOptions::setOptionDependencies()
{
  optSummary
    ->requires(optInputFileName)
    ->excludes(optOutputFileName);
  optFull
    ->requires(optInputFileName)
    ->excludes(optOutputFileName)
    ->excludes(optReadArea);
  optAttributes
    ->excludes(optInputFileName)
    ->excludes(optOutputFileName);
  optAttributeToSet
    ->requires(optInputFileName)
    ->requires(optOutputFileName)
    ->requires(optNewAttributeValue);
  optNewAttributeValue
    ->requires(optInputFileName)
    ->requires(optOutputFileName)
    ->requires(optAttributeToSet);
  optInsertStrapData
    ->requires(optInputFileName)
    ->requires(optOutputFileName)
    ->requires(optCopyStrapTo)
    ->excludes(optCopyStrapFrom);
  optCopyStrapFrom
    ->requires(optInputFileName)
    ->requires(optOutputFileName)
    ->requires(optCopyStrapTo)
    ->excludes(optInsertStrapData);
  optCopyStrapTo
    ->requires(optInputFileName)
    ->requires(optOutputFileName);
}
