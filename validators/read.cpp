#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool ReadValidator(string flag, string value){
    if(!flagCheck(flag, ReadFlagSet)) return false;
    if(!valueCheck(flag, value)) return false;
    return true;
}