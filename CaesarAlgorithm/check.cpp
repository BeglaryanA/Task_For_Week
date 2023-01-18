#include "check.h"
#include "CaesarAlgorithm.h"

bool isValidLine(const std::string& rhs) {
    for (int i = 0; i < rhs.size(); ++i) {
        if (!((rhs[i] >= 'a' && rhs[i] <= 'z') || (rhs[i] >= 'A' && rhs[i] <= 'Z'))) {
            return false;
        }
    }
    return true;
}

void init_command(std::string& command) {
    std::cout << "Enter command (decode/encode) : ";
    do {
        std::cin >> command;
        if (isValidCommand(command)) {
            break;
        }
        std::cout << "The line conntanes wrong componenets" << std::endl;
        std::cout << "Enter Line For decode/encode : ";
    } while (true);
}

void init_line(std::string& line) {
    std::cout << "Enter word For decode/encode : ";
    do {
        std::cin >> line;
        if (isValidLine(line)) {
            break;
        }
        std::cout << "The line conntanes  wrong componenets" << std::endl; 
        std::cout << "Enter Line For decode/encode : ";
    } while (true);

}

void init_step(int& step) {
    std::cout << "Enter step for decode/encode : ";
    do {
        std::cin >> step;
        if (step > 0) {
            break;
        }
        std::cout << "Step for coding can't be negativ number or zero!" << std::endl;
        std::cout << "Enter step for decode/encode : ";
    } while (true);
}


std::string toLowerCase(std::string& command) {
    for (int i = 0; i < command.size(); ++i) {
        if (command[i] >= 'A' && command[i] <= 'Z') {
            command[i] += 32;
        }
    }
    return command;
}

bool isValidCommand(std::string& rhs) {
    if ((toLowerCase(rhs) == "decode") || (toLowerCase(rhs) == "encode")) {
        return true;
    }
    return false;
}
