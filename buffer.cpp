#include "buffer.h"

std::vector<BYTE> Buffer::ReadFile(const char* Filename)
{
   std::ifstream file(Filename, std::ios::binary);
   file.unsetf(std::ios::skipws);
   std::streampos fileSize;

   file.seekg(0, std::ios::end);
   fileSize = file.tellg();
   file.seekg(0, std::ios::beg);

   std::vector<BYTE> vec;
   vec.reserve(fileSize);

   vec.insert(vec.begin(), std::istream_iterator<BYTE>(file), std::istream_iterator<BYTE>());
   this->FileData = vec;

   return vec;
}

std::vector<BYTE> Buffer::GetSubset(int &Offset)
{
    std::vector<BYTE> subset(FileData.begin() + Offset, FileData.end());

    return subset;
}

void Buffer::SetBufferPosition(int NewPosition)
{
    bufferPosition = NewPosition;
}

int Buffer::GetBufferPosition()
{
    return bufferPosition;
}

BYTE Buffer::GetByteAtPosition(int Position)
{
	if (Position <= FileData.size() - 4)
  {
    return (BYTE)FileData[Position];
	}

	return -1;
}

int Buffer::GetValueAtPosition(int Bits, int Position, bool IsFrequency)
{
	int value = 0;

	if (Position <= FileData.size() - 4)
	{
		switch (Bits)
		{
			case 8:
			default:
				value = FileData[Position];
				break;
			case 16:
				value = (FileData[Position + 1] << 8) | FileData[Position];
				break;
			case 24:
				value = (FileData[Position + 2] << 16) | (FileData[Position + 1] << 8) | FileData[Position];
				break;
			case 32:
				value = (FileData[Position + 3] << 24) | (FileData[Position + 2] << 16) | (FileData[Position + 1] << 8) | FileData[Position];
				break;
		}

		if (IsFrequency)
		{
			return value / 100;
		}

		return value;
	}

	return -1;
}

bool Buffer::SetValueAtPosition(int value, int bits, int position, bool isFrequency)
{
	if (isFrequency)
	{
		value *= 100;
	}

	if (position <= FileData.size() - 4)
	{
		switch (bits)
		{
			case 8:
			default:
				FileData[position] = static_cast<unsigned char>(value);
				break;
			case 16:
				FileData[position] = static_cast<unsigned char>(value);
				FileData[position + 1] = static_cast<unsigned char>(value >> 8);
				break;
			case 24:
				FileData[position] = static_cast<unsigned char>(value);
				FileData[position + 1] = static_cast<unsigned char>(value >> 8);
				FileData[position + 2] = static_cast<unsigned char>(value >> 16);
				break;
			case 32:
				FileData[position] = static_cast<unsigned char>(value);
				FileData[position + 1] = static_cast<unsigned char>(value >> 8);
				FileData[position + 2] = static_cast<unsigned char>(value >> 16);
				FileData[position + 3] = static_cast<unsigned char>(value >> 24);
				break;
		}
		return true;
	}
	return false;
}

bool Buffer::SetValueAtPosition(const std::wstring &text, int bits, int position, bool isFrequency)
{
  	int value = std::stoi(text);

  	return this->SetValueAtPosition(value, bits, position, isFrequency);
}

void Buffer::FixChecksum(bool Save, int AtomRomChecksumOffset)
{
  	unsigned char checksum = FileData[AtomRomChecksumOffset];
  	int size = FileData[0x02] * 512;
  	unsigned char offset = 0;

  	for (int i = 0; i < size; i++)
  	{
      offset += FileData[i];
  	}

  	if (checksum == (FileData[AtomRomChecksumOffset] - offset))
  	{
      std::cout << std::endl << "Checksum is valid: ";
  	}
  	else
  	{
      std::cout << std::endl << "WARNING: Invalid checksum: ";
  	}

  	if (Save)
  	{
      FileData[AtomRomChecksumOffset] -= offset;
  	}

    std::cout << ByteUtils::ToHexString((WORD)FileData[AtomRomChecksumOffset]) << std::endl;
}

std::string Buffer::GetStringFromOffset(int Offset)
{
  std::string resultString;

  int bufferOffset = 0;
  int prevTempVal = -1;

  while(true)
  {
    int tempVal = GetValueAtPosition(8, (Offset + bufferOffset), false);

    if( prevTempVal == 0 && tempVal == 0 )
    {
      break;
    }

    if(bufferOffset >= 10000)
    {
      break;
    }

    prevTempVal = tempVal;

    resultString += (char)tempVal;

    bufferOffset++;
  }

  return resultString;
}

std::string Buffer::TableWalk(int Offset, std::vector<int> ByteSizes)
{
  return TableWalk(Offset, ByteSizes, false);
}

std::string Buffer::TableWalk(int Offset, std::vector<int> ByteSizes, bool IsFrequency)
{
  std::string resultString;
  int bufferOffset = 0;

  for(std::vector<int>::iterator it = ByteSizes.begin(); it != ByteSizes.end(); ++it)
  {
    int tempVal = GetValueAtPosition(*it, (Offset + bufferOffset), false);
    resultString += "(" + std::to_string(tempVal) + "," + ByteUtils::ToHexString((WORD)tempVal) + ")";
    resultString += " ";
    bufferOffset += *it/8;
  }

  return resultString;
}
