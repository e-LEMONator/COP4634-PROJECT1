#include "parse.hpp"

Parser::Parser () { } // we don't have anything to set

/**
* @brief Convert std::string to char* not const char*
* @param std::string standard string input
* @returns stack-allocated copy of string input
*/
char* stdStringToCharPtr(const std::string& str) {
    char* c_str = new char[str.length() + 1]; // stack allocated, will need to be deleted
    strcpy(c_str, str.c_str()); // strcopy is a no-no, but there's not much of an easier way than this
    return c_str;
}

void Parser::parseString(std::string str) {
    std::vector<std::string> tokens;
    // strtok is picky about delimiters, so we set all other delimiter types to spaces
    std::replace(str.begin(), str.end(), '\t', ' ');
    std::replace(str.begin(), str.end(), '\n', ' ');
    std::replace(str.begin(), str.end(), '\r', ' ');
    char delim[] = " ";
    // convert to char* instead of const char* for strtok's sake
    char* w_str = stdStringToCharPtr(str);
    char* res = strtok(w_str, delim);
    while(res != NULL) {
        int len = strnlen(res, str.size());
        tokens.push_back(std::string(res, len));
        res = strtok(NULL, " ");
    }
    delete w_str; // only you can prevent memory leaks
    tokensToParam(tokens);
}

void Parser::tokensToParam(const std::vector<std::string>& vec) {
    // see header comment in parser.hpp for more information. This is just tedious copying
    parms.argumentCount = (int)vec.size();
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec.at(i)[0] == '<') {
            parms.inputRedirect = vec.at(i);
        } else if (vec.at(i)[0] == '>') {
            parms.outputRedirect = vec.at(i);
        }
        parms.argumentVector[i] = vec.at(i);
    }
}

void Parser::print() {
    parms.printParams();
}

std::string Parser::getArg(int index) {
    if (index <= parms.argumentCount) { // index check
        return parms.argumentVector[index];
    }
} 