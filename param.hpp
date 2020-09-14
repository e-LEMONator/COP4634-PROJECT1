#pragma once
#ifndef _COP_PARAM_
#define _COP_PARAM_
#include <iostream>
#define MAXARGS 32

class Param {
    private:
        friend class Parser;
        std::string inputRedirect;
        std::string outputRedirect;
        int argumentCount; 
        std::string argumentVector[MAXARGS];
    public:
        Param();
        void printParams();
};
#endif