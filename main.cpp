#include <iostream>

#include "pbemain.h"

int main(int argc, const char** argv)
{
  const char *filename;
  
  if(argc == 1)
  {
    filename = "test.rom";
  }

  if(argc == 2)
  {
    std::cout << "Input filename: " << argv[1] << std::endl;
	filename = argv[1];
  }

  MainWindow *mainApp = new MainWindow();
  mainApp->OpenFile(filename);
}
