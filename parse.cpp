#include "parse.hpp"

Parser::Parser () { }

void Parser::parseString(std::string str) {
    std::vector<char*> tokens;
    std::replace(str.begin(), str.end(), '\t', ' ');
    std::replace(str.begin(), str.end(), '\n', ' ');
    std::replace(str.begin(), str.end(), '\r', ' ');
    char delim[] = " ";
    char* w_str = new char[str.length() + 1];
    strcpy(w_str, str.c_str()); // ew
    char* res = strtok(w_str, delim);
    while(res != NULL) {
        std::cout << res << std::endl;
        tokens.push_back(res);
        res = strtok(NULL, " ");
    }
    delete w_str; // only you can prevent memory leaks
    tokensToParam(tokens);
}

void Parser::tokensToParam(const std::vector<char*>& vec) {
    parms.argumentCount = vec.size();
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec.at(i)[0] == '<') {
            parms.inputRedirect = vec.at(i);
        } else if (vec.at(i)[0] == '>') {
            parms.outputRedirect = vec.at(i);
        }
        parms.argumentVector[i] = vec.at(i);
    }
    parms.printParams();
}

int main() {
    Parser parse;
    std::string testStr = "prog arg1\targ2\narg3    >arg4";
    parse.parseString(testStr);
}