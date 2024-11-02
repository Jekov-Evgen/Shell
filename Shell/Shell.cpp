#include "connect.h"

std::string separation(std::string);
std::string savingCommand(std::string);

int main() {
    setlocale(LC_ALL, "ru");

    std::string command;
    std::filesystem::path root = "C://Program Files (x86)";
    std::filesystem::current_path(root);

    std::map<std::string, int> checkCommand;
    checkCommand["cdF"] = 1;
    checkCommand["lsF"] = 2;
    checkCommand["crDF"] = 3;

    std::cout << std::filesystem::current_path() << " ";
    std::getline(std::cin, command);

    do {
        std::string ck = savingCommand(command);
        std::string pat;

        if (ck == "cdF" && command.size() > 4) {
            pat = separation(command);
        }

        switch (checkCommand[ck]) {
        case 1:
            if (!pat.empty()) {
                transition(pat);
            }
            else {
                std::cout << "Ошибка: не указан путь для команды cdF" << std::endl;
            }
            break;
        case 2:
            fileOutput(std::filesystem::current_path().string());
            break;
        case 3:
            createDir(std::filesystem::current_path().string());
        default:
            std::cout << "Неизвестная команда" << std::endl;
            break;
        }

        std::cout << std::filesystem::current_path() << " ";
        std::getline(std::cin, command);

    } while (command != "exit");

    return 0;
}


std::string separation(std::string np) {
    std::string result;

    for (int i = 4; i < np.size(); i++) {
        result.push_back(np[i]);
    }

    return result;
}

std::string savingCommand(std::string save) {
    std::string result;

    for (int i = 0; i < 3; i++) {
        result.push_back(save[i]);
    }

    return result;
}