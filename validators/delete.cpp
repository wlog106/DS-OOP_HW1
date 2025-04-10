#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool DeleteValidator(string flag, string value){
    if(!flagCheck(flag, DeleteFlagSet)) return false;
    if(!valueCheck(flag, value)) return false;
    return true;
}