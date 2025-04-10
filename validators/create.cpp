#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool CreateValidator(deque<string> &command){
    
    if(!flagCheck(command, CreateFlagSet)) return false;

    string flag, value;
    for(auto itr = command.begin(); itr - prev(command.end()) < 0; itr++){
        flag = *itr;
        itr++;
        value = *itr;
        if(!valueCheck(flag, value)) return false;
    }
    return true;
}