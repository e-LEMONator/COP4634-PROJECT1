/**
 * Myshell is a shell program that creates multiple process instances of the program the user specifies.
 * @author Levi Shaffer Joshua Lemon
 * @date 10/05/2020
 * @info COP4634 Project I
 */
#include <iostream>
#include <string>
#include "parse.hpp"
#include "execHandler.hpp"
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
            break;
        }
        auto parms = parse.getParsedParms();
        if(parms.getArgumentCount() < MINARGS) {
            std::cout << "Bad command syntax; should be './myprogram <numInstances> [args]'\n";
            continue; // skip this guy; he doesn't want to play ball
        }
        auto exec = ExecutableHandler(parms);
        exec.executeAndWait();
    } while(cont);
    std::cout << std::endl;
    return 0;
}