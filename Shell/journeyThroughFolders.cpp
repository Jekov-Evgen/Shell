#include "journeyThroughFolders.h"


void transition(std::string pt) {
	std::filesystem::path tn = pt;

	std::filesystem::current_path(tn);
}