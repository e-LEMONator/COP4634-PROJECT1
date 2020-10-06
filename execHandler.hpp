/**
 * Contains definition for class wrapper for process fork and execv system calls
 * @author Levi Shaffer Joshua Lemon
 * @date 10/05/2020
 * @info COP4634 Project I
 */
#pragma once
#ifndef _COP_EXECHANDLER_
#define _COP_EXECHANDLER_

#include "param.hpp"
#include <vector>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#define EXECMINARGS 2 // the minimum args that the execv() system call requires

/**
 * @brief This class handles the behavior for creating child processes to `execv()` the desired program with the passed-in arguments
 */
class ExecutableHandler {
    private:
        Param param; // Internal wrapper for the passed-in Param object

        /**
         * @brief Helper function that contains all of the code that the child process will execute
         * @param id The ID of the child that is running this function
         */
        void childCode(const int&);

        /**
         * @brief Converts the `std::string*` argument vector into values that `execv()` will accept
         * @param id The ID of the child that is running this function
         * @returns std::vector<char*> 
         */
        std::vector<char*> buildArgVec(const int&);

        /**
         * @brief Performs all of the steps to redirect input files to `stdin`
         * @param id The ID of the child that is running this function
         */
        void redirectInput(const int&);

        /**
         * @brief Performs all of the steps to redirect output from `stdout` to an output file
         * @param id The ID of the child that is running this function
         */
        void redirectOutput(const int&);
    public:
        /**
         * @brief Default constructor
         * @param Param Parameter object that contains arguments needed to `execv()`
         */
        ExecutableHandler(const Param&);
        
        /**
         * @brief As the parent process, create the number of children processes, and have them `execv()` the command passed
         */
        void executeAndWait();
};

#endif