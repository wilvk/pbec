#include "buffer.h"

std::vector<BYTE> Buffer::ReadFile(const char* Filename)
{
    std::streampos fileSize;
    std::ifstream file(Filename, std::ios::binary);

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<BYTE> FileData(fileSize);
    file.read((char*) &FileData[0], fileSize);

    return FileData;
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


int Buffer::GetValueAtPosition(int bits, int position, bool isFrequency)
{
	int value = 0;
	if (position <= FileData.size() - 4)
	{
		switch (bits)
		{
			case 8:
			default:
				value = FileData[position];
				break;
			case 16:
				value = (FileData[position + 1] << 8) | FileData[position];
				break;
			case 24:
				value = (FileData[position + 2] << 16) | (FileData[position + 1] << 8) | FileData[position];
				break;
			case 32:
				value = (FileData[position + 3] << 24) | (FileData[position + 2] << 16) | (FileData[position + 1] << 8) | FileData[position];
				break;
		}

		if (isFrequency)
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
				FileData[position + 3] = static_cast<unsigned char>(value >> 32);
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

void Buffer::FixChecksum(bool save, int atom_rom_checksum_offset)
{
  	unsigned char checksum = FileData[atom_rom_checksum_offset];
  	int size = FileData[0x02] * 512;
  	unsigned char offset = 0;

  	for (int i = 0; i < size; i++)
  	{
  		offset += FileData[i];
  	}

  	if (checksum == (FileData[atom_rom_checksum_offset] - offset))
  	{
  		std::cout << "Checksum is valid.";
  	}
  	else
  	{
  		std::cout << "WARNING: Invalid checksum.";
  	}

  	if (save)
  	{
  		FileData[atom_rom_checksum_offset] -= offset;
  	}

  	std::cout << "checksum: " << FileData[atom_rom_checksum_offset];   //int_to_hex( FileData[atom_rom_checksum_offset] );
}
