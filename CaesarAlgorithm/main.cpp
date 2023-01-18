#include <iostream>
#include "CaesarAlgorithm.h"
#include "check.h"

int main() {

    CaesarAlgorithm cs;
    std::string  command{};
    std::string lineForCode{};
    int step{};
    init_command(command);
    init_line(lineForCode);
    init_step(step);
    std::string code = cs(command, lineForCode, step);
    std::cout << code << std::endl;

}