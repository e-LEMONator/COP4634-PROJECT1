#include <iostream>
#include <string>
#include "parse.hpp"
int main(int argc, char** args) {
    bool dbug = argc > 1;
    bool cont = true;
    do {
        std::cout << "$$$ ";
        std::string userInput; // treat with gloves
        getline(std::cin, userInput);
        Parser parse;
        parse.parseString(userInput);
        if(dbug)
            parse.print();
        if(parse.getArg(0) == "exit") {
            cont = false;
        }
    } while(cont);
    std::cout << std::endl;
    return 0;
}