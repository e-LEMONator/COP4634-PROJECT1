#pragma once
#ifndef _COP_PARAM_
#define _COP_PARAM_
#include <iostream>
#define MAXARGS 32
#define ptrprint(ptr) (ptr != nullptr) ? ptr : "NULL"
class Param {
    private:
        friend class Parser;
        char* inputRedirect;
        char* outputRedirect;
        int argumentCount; 
        char* argumentVector[MAXARGS];
    public:
        Param();
        void printParams();
};
#endif