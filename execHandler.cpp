/**
 * Contains implementation for class wrapper for process fork and execv system calls
 * @author Levi Shaffer Joshua Lemon
 * @date 10/05/2020
 * @info COP4634 Project I
 */
#include "execHandler.hpp"
ExecutableHandler::ExecutableHandler(const Param& _parm) {
    param = _parm; // cache the parameter object we are given
}

void ExecutableHandler::redirectInput(const int& id) {
    std::string fname = param.getInputRedirect() + std::to_string(id + 1);
    // freopen will redirect stdin to a filename that we built above
    freopen(fname.c_str(), "r", stdin); 
}

void ExecutableHandler::redirectOutput(const int& id) {
    
    std::string fname = param.getOutputRedirect() + std::to_string(id + 1);
    // freopen will redirect stdout to a filename that we built above
    freopen(fname.c_str(), "w", stdout);
}

void ExecutableHandler::childCode(const int& id) {
    // get the argument vector from the parameter object
    auto args = buildArgVec(id);
    // do we want to redirect input?
    if(param.getInputRedirect() != "") {
        redirectInput(id);
    } 
    // do we want to redirect output?
    if (param.getOutputRedirect() != "") {
        redirectOutput(id);
    }
    /*
       Here we have the magic sauce. execv() will run a program given a file path to it, and pass in 
       an array of arguments. If the system call does not error out, the child will die here. If it 
       does, then we know that something went wrong, probably that the input file was not found.

       Docs -> https://linux.die.net/man/3/execv
    */
    int retCode = execv(param.getArgv()[0].c_str(), &args[0]);
    // we know something went wrong here; see errors documented in above link
    if(retCode == -1 && (errno == ENOENT || errno == ENOTDIR || errno == EACCES)) {
        std::cout << "ERROR: program " << args[0] << " not found. Please enter a valid command.\n";
    } else {
        std::cout << "ERROR: execp() call unable to complete for reason code: " << errno << std::endl;
    }
}

std::vector<char*> ExecutableHandler::buildArgVec(const int& id) {
    auto pArgVec = param.getArgv();
    int argCount = param.getArgumentCount();
    // go ahead and size the vector to our needs. We need EXECMINARGS more than the count, as we have to ensure the 
    // final element in the vector is NULL & we must pass in the child ID
    std::vector<char*> strs(argCount + EXECMINARGS);
    if(argCount < MINARGS) {
        // This really should not happen; if we have reached this point, there is a deeper issue.
        
        return strs;
    } else {
        for(int i = 0; i < param.getArgumentCount(); i++) {
            // funky conversion process that results when you use C functions with C++ code
            strs.at(i) = const_cast<char*>(pArgVec[i].c_str());
        }
        // conver the ID to the character representation of itself and insert it into the vector in the correct location
        auto char_id = const_cast<char*>(std::to_string(id).c_str());
        strs.insert(strs.begin()+2, {char_id});
        return strs;
    }
}

void ExecutableHandler::executeAndWait() {
    pid_t pid, wpid; // the PID of the process from fork(), and the wait pid
    int status = 0; // used for waiting
    // creates numProcesses child processes
    for(int i = 0; i < param.getNumProcesses(); i++) {
        pid = fork();
        if(pid > 0) { 
            // parent ends up here
            continue;
        } else if(pid == 0) { 
            // child ends up here
            childCode(i); 
            break;
        } else {
            std::cout << "ERROR: Could not fork() process. \n";
            continue;
        }
    }
    if(pid > 0) { 
        // parent waits until all children are exit
        // https://stackoverflow.com/a/23872806
        while ((wpid = wait(&status)) > 0);
    } else {
        // the child has finished their job, there was some kind of error
        exit(0);
    }
}