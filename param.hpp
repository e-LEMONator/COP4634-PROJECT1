/**
 * Contains definition for class wrapper for information parsed from user input
 * @author Levi Shaffer Joshua Lemon
 * @date 10/05/2020
 * @info COP4634 Project I
 */
#pragma once
#ifndef _COP_PARAM_
#define _COP_PARAM_
#include <string>
#include <iostream>
#define MAXARGS 32  // maximum args to be accepted, per Project 1.pdf
#define MINARGS 2   // minimum args for shell to execv() a process.

/**
 * @brief Class that contains the parsed information from a command
 */
class Param {
    private:
        friend class Parser;                    // we want the Parser class to write to this object, but everyone else is read-only
        std::string inputRedirect;              // file name if input redirection is used
        std::string outputRedirect;             // file name if ouput redirection is used
        int argumentCount;                      // Keep track of number of arguments we have total
        int numProcesses;                       // number of processes the shell is supposed to spawn
        std::string argumentVector[MAXARGS];    // array of strings to represent arguments
    public:
        /**
         * @brief Default constructor. Initializes all variables empty
         */
        Param();
        /**
         * @brief prints a representation of the parameters object for debugging purposes.
         */
        void printParams();

        /**
         * @brief Getter for value of `inputRedirect`
         * @returns std::string
         */        
        std::string getInputRedirect() {
            return this->inputRedirect;
        };
        /**
         * @brief Getter for value of `outputRedirect`
         * @returns std::string
         */
        std::string getOutputRedirect() {
            return this->outputRedirect;
        }
        /**
         * @brief Getter for value of `argumentCount`
         * @returns int
         */
        int getArgumentCount() {
            return this->argumentCount;
        }
        /**
         * @brief Getter for value of `numProcesses`
         * @returns int
         */
        int getNumProcesses() {
            return this->numProcesses;
        }
        /**
         * @brief Getter for value of `argumentVector`
         * @returns std::string*
         */        
        std::string* getArgv() {
            return argumentVector;
        }
};
#endif