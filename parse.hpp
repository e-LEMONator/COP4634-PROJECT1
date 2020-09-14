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
        /**
        * @brief Takes tokens and uses them to set values inside internal Param object `parms`
        * @param std::string standard string input
        * @returns stack-allocated copy of string input
        */
        void tokensToParam(const std::vector<std::string>& vec);
    public:
        Parser();
        /**
         * @brief Parses a std::string into tokens delimited on spaces, tabs, and newlines
         * @param std::string standard string input
         */
        void parseString(std::string str);
        void print();
        /**
         * @brief Returns an argument at a given index
         * @param int Index of argument
         * @returns String of argument at index
         */
        std::string getArg(int index);
};
#endif