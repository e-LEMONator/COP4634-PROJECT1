#include "param.hpp"

Param::Param() {
    inputRedirect = "";
    outputRedirect = "";
    argumentCount = 0;
}

void Param::printParams() {
    std::cout << "InputRedirect: [" << ((inputRedirect != "") ? inputRedirect : "NULL") << "]" << std::endl;
    std::cout << "OutputRedirect: [" << ((outputRedirect != "") ? outputRedirect : "NULL") << "]" << std::endl;
    std::cout << "ArgumentCount: " << argumentCount << std::endl;
    for (int i = 0; i < argumentCount; i++) {
        std::cout << "ArgumentVector[" << i << "]: " << argumentVector[i] << std::endl;
    }
}