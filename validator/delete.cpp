#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool DeleteValidator(const deque<string> *command){
    if(!flagCheck(command, DeleteFlagSet)) return false;
    if(!valueCheck(&command->at(1), &command->at(2))) return false;
    return true;
}