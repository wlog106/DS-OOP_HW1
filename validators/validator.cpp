#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool validator(deque<string>& command){
    if(command.front() == "add"){
        return CreateValidator(command);
    }
    else if(command.front() == "ls"){
        return ReadValidator(command[0], command[1]);
    }
    else if(command.front() == "upt"){
        return UpdateValidator(command);
    }
    else if(command.front() == "rm"){
        return DeleteValidator(command[0], command[1]);
    }
    else if(command.front() == "help" || command.front() == "exit"){
        return true;
    }
    else {
        return false;
    }
}