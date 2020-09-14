# COP4634-PROJECT1
The first project for Systems and Networks I

Included files:

* myshell.cpp
* parse.cpp
* parse.hpp
* param.cpp
* param.hpp
* MAKEFILE.
* README.md

Compiling and running:

Summary:  
Start with user input loop and take the user input string and send to `Parser` object. We then replace all tab, newline, and carriage return characters into space characters within the `parseString()` method and then feed that into the `strtok()` function delimited by spaces to split our arguments. Then the `tokensToParam()` method will convert those tokenized strings into acceptable types to be read into the parameter vector `parms.argumentVector` which is assigned to the `param` object.  
Inside the `main()` loop we check if we are in debug mode, and if we are, then we print the `param` object to the console using `stdout`. If we parse an 'exit' argument, we then free the memory and exit the process.

Plan Forward:  
Our plan to continue is to extend the argument parser functionality of part 1 and allow it to utilize the `fork()` method to run multiple instances of a computational process to solve a problem cooperatively. By parallelizing our processes, we are able to utilize a divide and conquer approach to solve such a problem in a faster manner. By taking input from a single file and then outputting to multiple output files, labeled sequentially, we are able to see how each process handled the problem.