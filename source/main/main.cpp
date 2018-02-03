#include "clioptions.h"
#include "CLI11.hpp"

int main(int argc, char** argv)
{
  CliOptions options;
  return options.ParseCommandLine(argc, argv);
}
