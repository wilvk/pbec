#include "clioptions.h"

int CliOptions::ParseCommandLine(int argc, char** argv)
{
  app = new CLI::App("Polaris Bios Editor for the Console");
  setCliOptions();
  CLI11_PARSE(*app, argc, argv);

  loadInputFile();
  printSummary();
  printVerbose();

  return 0;
}

void CliOptions::loadInputFile()
{
  if(!inputFileName.empty())
  {
    appData = new AppData();
    appData->OpenFile(inputFileName);
  }
}

void CliOptions::printSummary()
{
  if(summary)
  {
    appData->PrintSummary();
  }
}

void CliOptions::printVerbose()
{
  if(verbose)
  {
	  appData->PrintVerbose();
  }
}

void CliOptions::setCliOptions()
{
  app->add_flag("--summary,-u", summary, "Print a summary of the ROM image");
  app->add_flag("--full,-f", verbose, "Print verbose details of the ROM image");
  app->add_flag("--sections,-s", printSectionNames, "Print a list of sections that can be printed");
  app->add_flag("--attributes,-t", printAttributeNames, "Print a list of attributes that can be modified");
  app->add_option("--inputFile,-i", inputFileName, "Specifies the input ROM image filename")->expected(1)->check(CLI::ExistingFile);
  app->add_option("--outputFile,-o", inputFileName, "Specifies the output ROM image filename")->expected(1);
  app->add_option("--sectionDetails,-d", sectionToPrint, "Prints only the details for a specified section")->expected(1);
  app->add_option("--setAttribute,-a", attributeToSet, "Specify the name of the attribute to set")->expected(1);
  app->add_option("--setValue,-v", newAttributeValue, "Specify the value for the attribute specified with -s")->expected(1);
  app->add_option("--copyStrapFrom,-c", copyStrapFrom, "Specify the array number of the timing strap to copy from")->expected(1);
  app->add_option("--copyStrapTo,-p", copyStrapTo, "Specify the array number. of the timing strap to copy to specified in -c. Can accept multiple values.")->expected(1);
  
}
