/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: Provides basic file-system utility methods.
*/
#pragma once
#include <string>
#include <vector>

class FileSystem
{
public:
	static bool fileExists(std::string file);
	static bool directoryExists(std::string directory);
	static void createDirectory(std::string directory);

	static std::string getStartupUpath();
	static std::vector<std::string> getFile(std::string directory);
	static std::vector<std::string> getDirectories(std::string directory);
};