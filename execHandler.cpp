#include "execHandler.hpp"
#include "debugger.hpp"

ExecutableHandler::ExecutableHandler(const Param& _parm) {
    param = _parm;
}

ExecutableHandler::~ExecutableHandler() {
    dbg("ExecutableHandler::~ExecutableHandler", "Cleaning up created argvs...");
    for(auto& ptr : argvs) {
        if (ptr)
            delete ptr;
    }
}

char* const* ExecutableHandler::buildArgVec(const int& id) {
    dbg("ExecutableHandler::buildArgVec", "Building argument vector for id: " << id);
    auto pArgVec = param.getArgv();
    int argCount = param.getArgumentCount();
    char* const* nArgV = new char*[MAXARGS+EXECMINARGS];
    if(argCount < MINARGS) {
        // todo: they have not given us a correctly formatted command
        dbg("ExecutableHandler::buildArgVec", "Argcount < MINARGS");
        delete nArgV;
        return nullptr;
    } else {
        // nArgV[2] = std::to_string(id).c_str();
        strcpy(nArgV[MINARGS],pArgVec[id].c_str());
        for(int i = 0; i < argCount; i++) {
            if(i == 2) {
                continue; // skip item 3, we already set that
            }
            strcpy(nArgV[i],pArgVec[i].c_str());
        }
        argvs.push_back(nArgV); // no matter what, we want to track this memory so we can delete it
        return nArgV;
    }
}

void ExecutableHandler::executeAndWait() {
    dbg("ExecutableHandler::executeAndWait", "Forking " << param.getNumProcesses() << " processes...");
    pid_t pid, wpid;
    int status = 0;
    // creates numProcesses child processes
    // credit: https://stackoverflow.com/a/10911719
    for(int i = 0; i < param.getNumProcesses(); i++) {
        pid = fork();
        if(pid > 0) { // parent
            continue;
        } else if(pid == 0) { // child
            char* const* args = buildArgVec(i);
            #ifdef DEBUG
            // FILE* file;
            // std::string fname = "output" + std::to_string(i) + ".txt";
            // file = freopen(fname.c_str(), "w", stdout);
            // std::cout << file << std::endl;
            for(int j = 0; j < param.getArgumentCount() + EXECMINARGS; j++) {
                dbgf("output.txt","ExecutableHandler::executeAndWait", "argV[" << j << "]: " << args[j]);
            }
            // fflush(stdout);
            // fclose(file);
            #endif
            execv(param.getArgv()[0].c_str(), args);
            break;
        } else {
            // TODO: throw error in fork
            continue;
        }
    }
    // parent wait
    if(pid > 0) {
        // parent waits until all children are exit
        // https://stackoverflow.com/a/23872806
        while ((wpid = wait(&status)) > 0);
    } else { // the child has finished their job, they are no longer needed
        return;
    }
}