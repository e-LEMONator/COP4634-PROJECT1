#include "param.hpp"

Param::Param() {
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    argumentCount = 0;
}

void Param::printParams() {
    std::cout << "InputRedirect: [" << ((inputRedirect) ? inputRedirect : "NULL") << "]" << std::endl;
    std::cout << "OutputRedirect: [" << ((outputRedirect) ? outputRedirect : "NULL") << "]" << std::endl;
    std::cout << "ArgumentCount: " << argumentCount << std::endl;
    for (size_t i = 0; i < argumentCount; i++) {
        std::cout << "\tArgumentVector[" << i << "]: " << argumentVector[i] << std::endl;
    }
}