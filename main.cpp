#include <iostream>

#include "mainapp.h"

int main(int argc, const char** argv)
{
  const char *filename;

  if(argc == 1)
  {
    filename = "test.rom";
  }

  if(argc == 2)
  {
    filename = argv[1];
  }

  std::cout << "Input filename: " << filename << std::endl;

  MainApp *mainApp = new MainApp();
  mainApp->OpenFile(filename);
}
