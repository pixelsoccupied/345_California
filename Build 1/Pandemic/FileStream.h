#pragma once
#include <string>
#include <fstream>

enum FileMode : int
{
	Read,
	Write
};

class FileStream
{
public:
	static FileStream* Open(std::string fileName, FileMode mode);
	~FileStream();


	// Functions that read and write from the appropriate file streams.
	void write(std::string line);
	std::string readString();

	void write(int value);
	int readInt();

private:
	std::ifstream* _inputFileStream;
	std::ofstream* _outputFileStream;

	FileStream();
};