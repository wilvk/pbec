#include "clioptions.h"
#include "CLI11.hpp"

int CliOptions::ParseCommandLine(int argc, char** argv)
{
  // parser.addArgument("-i", "--inputFile", 1);
  // parser.addArgument("-o", "--outputFile", 1);
  // parser.addArgument("-h", "--help");
  // parser.addArgument("-u", "--summary");
  // parser.addArgument("-v", "--verbose");
  // parser.addArgument("-e", "--sections");
  // parser.addArgument("-l", "--values");
  // parser.addArgument("-d", "--sectionDetails", 1);
  // parser.addArgument("-s", "--setValue", 1);
  // parser.addArgument("-t", "--setValueTo", 1);
  // parser.addArgument("-c", "--copyStrapFrom", 1);
  // parser.addArgument("-p", "--copyStrapTo", '+');

  CLI::App app("Polaris Bios Editor for the Console");

  bool summary;
  app.add_flag("--summary,-u", summary, "Print a summary of the ROM image");

  bool verbose;
  app.add_flag("--full,-f", verbose, "Print (relatively) full details of the ROM image");

  bool printSectionNames;
  app.add_flag("--sections,-s", printSectionNames, "Print a list of sections that can be printed");

  bool printAttributeNames;
  app.add_flag("--attributes,-t", printAttributeNames, "Print a list of attributes that can be modified");

  std::string inputFileName;
  app.add_option("--inputFile,-i", inputFileName, "Specifies the input ROM image filename")->expected(1)->check(CLI::ExistingFile);

  std::string outputFileName;
  app.add_option("--outputFile,-o", inputFileName, "Specifies the output ROM image filename")->expected(1);

  std::string sectionToPrint;
  app.add_option("--sectionDetails,-d", sectionToPrint, "Prints only the details for a specified section")->expected(1);

  std::string attributeToSet;
  app.add_option("--setAttribute,-a", attributeToSet, "Specify the name of the attribute to set")->expected(1);

  std::string newAttributeValue;
  app.add_option("--setValue,-v", newAttributeValue, "Specify the value for the attribute specified with -s")->expected(1);

  std::string copyStrapFrom;
  app.add_option("--copyStrapFrom,-c", copyStrapFrom, "Specify the array number of the timing strap to copy from")->expected(1);

  std::string copyStrapTo;
  app.add_option("--copyStrapTo,-p", copyStrapTo, "Specify the array number. of the timing strap to copy to specified in -c. Can accept multiple values.")->expected(1);

  std::string inputFile = "test.rom";

  CLI11_PARSE(app, argc, argv);

  AppData *appData = new AppData();
  appData->OpenFile(inputFile);

  return 0;
}
