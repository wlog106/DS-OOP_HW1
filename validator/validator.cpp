#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool validator(const deque<string> *command){
    if(command->size()%2 == 0){
        cout << "error: Invalid Command\n";
        return false;
    }
    else if(command->front() == "add"){
        return CreateValidator(command);
    }
    else if(command->front() == "ls"){
        return ReadValidator(command);
    }
    else if(command->front() == "upt"){
        return UpdateValidator(command);
    }
    else if(command->front() == "rm"){
        return DeleteValidator(command);
    }
    else if(command->front() == "help"){
        return true;
    }
    else if(command->front() == "exit"){
        delete CreateFlagSet;
        delete ReadFlagSet;
        delete UpdateFlagSet;
        delete DeleteFlagSet;
        CreateFlagSet = nullptr;
        ReadFlagSet = nullptr;
        UpdateFlagSet = nullptr;
        DeleteFlagSet = nullptr;
        return true;
    }
    else if(command->size() == 0){
        return true;
    }
    else {
        cout << "error: Unknown command: \"" << command->front() 
             << "\"\nNeed help? Type 'help' to see the available commands\n";
        return false;
    }
}