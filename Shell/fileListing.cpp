#include "fileListing.h"

void fileOutput(const std::string& path) {
    std::filesystem::directory_iterator begin(path), end;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::cout << "FILE: " << entry.path().filename().string() << std::endl;
        }
        else if (entry.is_directory()) {
            std::cout << "DIR: " << entry.path().filename().string() << std::endl;
        }
        else if (entry.is_symlink()) {
            std::cout << "SYMLINK: " << entry.path().filename().string() << std::endl;
        }
        else {
            std::cout << "OTHER: " << entry.path().filename().string() << std::endl;
        }
    }
}