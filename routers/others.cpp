#include "router.h"
#include "../database/database.h"
#include <deque>
#include <string>

using namespace std;

void strTo_Completed(bool *completed, string &str){
    if(str == "yes") *completed = true;
    else if(str == "no") *completed = false;
}

void strTo_SortCriteria(int *sortCritetria, string &str){
    if(str == "name") *sortCritetria = sortCriteria::name;
    else if(str == "category") *sortCritetria = sortCriteria::category;
    else if(str == "completed") *sortCritetria = sortCriteria::completed;
    else if(str == "expire") *sortCritetria = sortCriteria::expire;
}

void strTo_ExpireState(int *expire, string &str){
    if(str == "true") *expire = expireState::True;
    else if(str == "false") *expire = expireState::False;
}