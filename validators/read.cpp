#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool ReadValidator(const string &flag, const string &value){
    if(!flagCheck(flag, ReadFlagSet)) return false;
    if(!valueCheck(flag, value)) return false;
    return true;
}