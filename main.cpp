#include <iostream>

#include "pbemain.h"

int main(int argc, const char** argv)
{
  MainWindow *mainApp = new MainWindow();

  const char *filename;

  filename = "test.rom";

  mainApp->OpenFile(filename);
}
