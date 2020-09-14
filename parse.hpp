#pragma once
#ifndef _COP_PARSE_
#define _COP_PARSE_
#include "param.hpp"
class Parser {
    private:
        friend class Param;
        Param parms;
    public:
        Parser();
        void parseString(char* str);
        Param getParms();
};
#endif