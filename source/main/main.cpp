#include "headers.h"

int main(int argc, char** argv)
{
  CliOptions options;
  return options.ParseCommandLine(argc, argv);
}
