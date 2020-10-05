/**
 * @brief Simple debugger that can be turned off by simply adding a `DEBUG` flag. Allows for verbose output
 */
#pragma once
#ifndef _COP_DEBUGGER_
    #define _COP_DEBUGGER_
    #ifdef DEBUG
        #include <fstream>
        #include <iostream>
        #define dbg(origin, message) std::cout << "[" << origin << "]: " << message << "\n";
        #define dbgf(filename, origin, message) std::ofstream fout; fout.open(filename); if (!fout.fail() && fout.is_open()) { fout <<  "[" << origin << "]: " << message << "\n";}; fout.close();
    #else
        #define dbg(origin, message)
        #define dbgf(filename, origin, message)
    #endif
#endif