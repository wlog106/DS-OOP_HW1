#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool DeleteValidator(const string &flag, const string &value){
    if(!flagCheck(flag, DeleteFlagSet)) return false;
    if(!valueCheck(flag, value)) return false;
    return true;
}