#include <iostream>

#include "mainapp.h"

#include "argparse.hpp"

int main(int argc, const char** argv)
{
  ArgumentParser parser;

  parser.appName("pbec");

  parser.addArgument("-i", "--inputFile", 1, true);
  parser.addArgument("-o", "--outputFile", 1);
  parser.addArgument("-h", "--help");
  parser.addArgument("-u", "--summary");
  parser.addArgument("-v", "--verbose");
  parser.addArgument("-l", "--ListValueNames");
  parser.addArgument("-s", "--setValueName", 1);
  parser.addArgument("-t", "--setValueTo", 1);
  parser.addArgument("-c", "--copyStrapFrom", 1);
  parser.addArgument("-p", "--copyStrapTo", '+');

  parser.parse(argc, argv);

  std::string inputFile = parser.retrieve<std::string>("inputFile");

  if(inputFile.empty())
  {
	  std::cout << std::endl << "ERROR: No Input File Specified." << std::endl;
	  //return 1;
	  inputFile = "test.rom";
  }

  std::cout << "Input filename: " << inputFile << std::endl;

  MainApp *mainApp = new MainApp();
  mainApp->OpenFile(inputFile);
}
