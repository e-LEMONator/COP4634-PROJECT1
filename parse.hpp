#pragma once
#ifndef _COP_PARSE_
#define _COP_PARSE_
#include "param.hpp"
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
class Parser {
    private:
        Param parms;
        void tokensToParam(const std::vector<char*>& vec);
    public:
        Parser();
        void parseString(std::string str);
        Param getParms();
};
#endif