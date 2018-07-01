#pragma once
#include "headers.h"

class InvalidDataException : public std::exception
{
private:
  std::string msg;

public:
  InvalidDataException(const std::string& message = "") : msg(message) { }
  const char * what() const throw() { return msg.c_str(); }
};
