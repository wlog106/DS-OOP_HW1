#include "router.h"
#include "../database/database.h"
#include <deque>
#include <string>

using namespace std;

void strTo_Completed(bool *completed, string *str){
    if(*str == "true") *completed = true;
    else if(*str == "false") *completed = false;
}

void strTo_SortCriteria(int *sortCritetria, string *str){
    if(*str == "name") *sortCritetria = sortCriteria_Name;
    else if(*str == "category") *sortCritetria = sortCriteria_Category;
    else if(*str == "completed") *sortCritetria = sortCriteria_Completed;
    else if(*str == "expire") *sortCritetria = sortCriteria_Expire;
}

void strTo_ExpireState(int *expire, string *str){
    if(*str == "true") *expire = expireState_True;
    else if(*str == "false") *expire = expireState_False;
}