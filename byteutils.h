#pragma once

#include <vector>
#include <iomanip>
#include <sstream>

#include "typedefs.h"

class ByteUtils
{

private:

public:

	std::vector<BYTE> GetBytes(void *Object);

	static std::string ConvertIntToHexString(WORD* Data, int Len);

};
