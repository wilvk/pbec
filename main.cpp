#include "clioptions.h"
#include "argparse.hpp"

int main(int argc, const char** argv)
{
  CliOptions options;
  ArgumentParser parser;

  parser.appName("pbec");

  parser.addArgument("-i", "--inputFile", 1);
  parser.addArgument("-o", "--outputFile", 1);
  parser.addArgument("-h", "--help");
  parser.addArgument("-u", "--summary");
  parser.addArgument("-v", "--verbose");
  parser.addArgument("-e", "--printSectionNames");
  parser.addArgument("-l", "--printValueNames");
  parser.addArgument("-d", "--printSectionDetails", 1);
  parser.addArgument("-s", "--setValueName", 1);
  parser.addArgument("-t", "--setValueTo", 1);
  parser.addArgument("-c", "--copyStrapFrom", 1);
  parser.addArgument("-p", "--copyStrapTo", '+');

  parser.parse(argc, argv);

  return options.ParseCommandLine(parser);
}
