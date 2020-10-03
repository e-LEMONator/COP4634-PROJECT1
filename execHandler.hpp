#pragma once
#ifndef _COP_EXECHANDLER_
#define _COP_EXECHANDLER_

#include "param.hpp"
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

class ExecutableHandler {
    private:
        Param param;
        std::vector<char* const*> argvs;
        char* const* buildArgVec(const int&);
    public:
        ExecutableHandler(const Param&);
        ~ExecutableHandler();
        void executeAndWait();
};

#endif