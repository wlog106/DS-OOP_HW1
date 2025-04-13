#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool ReadValidator(const deque<string> *command){
    if(!flagCheck(command, ReadFlagSet)) return false;
    if(!valueCheck(&command->at(1), &command->at(2))) return false;
    return true;
}