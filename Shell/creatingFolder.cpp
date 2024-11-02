#include "creatingFolder.h"

void createDir(std::string pt) {
	std::filesystem::path crD = pt;

	std::filesystem::create_directory(crD);
}