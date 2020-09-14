#include "parse.hpp"
#include <string.h>
#include <iostream>

Parser::Parser () { }

void Parser::parseString(char* str) {
    // std::vector<char*> tokens;
    const char delim[2] = " ";
    char* res = strtok(str, delim);
    // tokens.push_back(res);
    // int len = 1;
    while(res != NULL) {
        std::cout << res << std::endl;
        res = strtok(str, " ");
    }
}

int main() {
    Parser parse;
    char* testStr = "prog arg1 arg2 arg3 arg4";
    parse.parseString(testStr);
}