#include "router.h"
#include "../databaseOp/database.h"
#include <deque>
#include <string>

using namespace std;

bool strTo_Completed(string str){
    if(str == "yes") return true;
    else if(str == "no") return false;
}

int strTo_SortCriteria(string str){
    if(str == "name") return sortCriteria::name;
    else if(str == "category") return sortCriteria::category;
    else if(str == "completed") return sortCriteria::completed;
    else if(str == "expire") return sortCriteria::expire;
}

int strTo_ExpireState(string str){
    if(str == "true") return expireState::True;
    else if(str == "false") return expireState::False;
}