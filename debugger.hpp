/**
 * @brief Simple debugger that can be turned off by simply adding a `DEBUG` flag. Allows for verbose output
 */
#pragma once
#ifndef _COP_DEBUGGER_
    #define _COP_DEBUGGER_
    #ifdef DEBUG
        #include <iostream>
        #define dbg(origin, message) std::cout << "[" << origin << "]: " << message << "\n";
    #else
        #define dbg(origin, message)
    #endif
#endif