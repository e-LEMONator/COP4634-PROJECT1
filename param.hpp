#pragma once
#ifndef _COP_PARAM_
#define _COP_PARAM_
#include <iostream>
#define MAXARGS 32
#define MINARGS 2

class Param {
    private:
        friend class Parser;
        std::string inputRedirect;
        std::string outputRedirect;
        int argumentCount;
        int numProcesses;
        std::string argumentVector[MAXARGS];
    public:
        Param();
        void printParams();
        std::string getInputRedirect();

        std::string getOutputRedirect() {
            return this->outputRedirect;
        }
        int getArgumentCount() {
            return this->argumentCount;
        }
        int getNumProcesses() {
            return this->numProcesses;
        }

        std::string* getArgv() {
            return argumentVector;
        }
};
#endif