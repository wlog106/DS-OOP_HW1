#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool valueCheck(const string *flag, const string *value){

    // check name and category
    if(*flag == "-n" || *flag == "-c" || *flag == "--name" || *flag == "--category"){
        try{
            nameNcategoryCheck(value);
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check all
    else if(*flag == "-a" || *flag == "--all"){
        try{
            allCheck(value);
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check id
    else if(*flag == "-i" || *flag == "--id"){
        try{
            idCheck(value);
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check due
    else if(*flag == "-d" || *flag == "--due"){
        try{
            dueCheck(value);
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check complete
    else if(*flag == "-C" || *flag == "--completed"){
        try{
            completedStatusCheck(value);
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check expire
    else if(*flag == "-e" || *flag == "--expire"){
        try{
            expireStatusCheck(value);
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }
    if(*value != "true" && *value != "false"){
        throw invalid_argument("invalid expire Status");
    }
    // because of flag check, program shouldn't reach this line
    return false;
}


// --all checker
void allCheck(const string *value){
    if(*value != "name" && *value != "category" && *value != "completed" && *value != "expire"){
        throw invalid_argument("invalid sort criteria");
    }
}

// --name, --category checker
void nameNcategoryCheck(const string *value){
    if(value->length() > 15 || value->length() == 0){
        throw invalid_argument("Length should be between 1 and 15");
    }
}

// --id checker
void idCheck(const string *value){
    int *i = new int;
    for(*i = 0; *i < value->length(); (*i)++){
        if(static_cast<int>(value->at(*i)) > 57 || static_cast<int>(value->at(*i)) < 48){
            delete i;
            i = nullptr;
            throw invalid_argument("Id should be integer");
        }
    }
    delete i;
    i = nullptr;
}


// --due checker
void dueCheck(const string *value){
    if(value->length() != 19){
        throw invalid_argument("invalid format: \'" + *value + "\' \nFormat: YYYY-MM-DD@hr:min:sec");
    }
    if(value->at(4) != '-' || value->at(7) != '-' || value->at(10) != '@' 
        || value->at(13) != ':' || value->at(16) != ':'){
        throw invalid_argument("invalid format: \'" + *value + "\' \nFormat: YYYY-MM-DD@hr:min:sec");
    }
    // check 0 ~ 9
    if(    static_cast<int>(value->at(0))  > 57 || static_cast<int>(value->at(1))  > 57
        || static_cast<int>(value->at(2))  > 57 || static_cast<int>(value->at(3))  > 57
        || static_cast<int>(value->at(5))  > 57 || static_cast<int>(value->at(6))  > 57
        || static_cast<int>(value->at(8))  > 57 || static_cast<int>(value->at(9))  > 57
        || static_cast<int>(value->at(11)) > 57 || static_cast<int>(value->at(12)) > 57
        || static_cast<int>(value->at(14)) > 57 || static_cast<int>(value->at(15)) > 57
        || static_cast<int>(value->at(17)) > 57 || static_cast<int>(value->at(18)) > 57
        || static_cast<int>(value->at(0))  < 48 || static_cast<int>(value->at(1))  < 48
        || static_cast<int>(value->at(2))  < 48 || static_cast<int>(value->at(3))  < 48
        || static_cast<int>(value->at(5))  < 48 || static_cast<int>(value->at(6))  < 48
        || static_cast<int>(value->at(8))  < 48 || static_cast<int>(value->at(9))  < 48
        || static_cast<int>(value->at(11)) < 48 || static_cast<int>(value->at(12)) < 48
        || static_cast<int>(value->at(14)) < 48 || static_cast<int>(value->at(15)) < 48
        || static_cast<int>(value->at(17)) < 48 || static_cast<int>(value->at(18)) < 48){
            throw invalid_argument("fail to convert " + *value + " to proper format");
    }
    // check hr, min, sec
    if(    stoi(value->substr(11, 2)) < 0 || stoi(value->substr(11, 2)) > 23
        || stoi(value->substr(14, 2)) < 0 || stoi(value->substr(14, 2)) > 59
        || stoi(value->substr(17, 2)) < 0 || stoi(value->substr(17, 2)) > 59){
        throw invalid_argument("invalid time value");
    }
    // check day (leap year)
    int *year = new int(stoi(value->substr(0, 4)));
    int *mon = new int(stoi(value->substr(5, 2)));
    int *day = new int(stoi(value->substr(8, 2)));
    if(!isValidDay(year, mon, day)){
        delete year;
        delete mon;
        delete day;
        year = nullptr;
        mon = nullptr;
        day = nullptr;
        throw invalid_argument("invalid date value");
    }
    delete year;
    delete mon;
    delete day;
    year = nullptr;
    mon = nullptr;
    day = nullptr;
}

// --completed checker
void completedStatusCheck(const string *value){
    if(*value != "true" && *value != "false"){
        throw invalid_argument("invalid completed status, status should be true/false");
    }
}

// --expire checker
void expireStatusCheck(const string *value){
    if(*value != "true" && *value != "false"){
        throw invalid_argument("invalid expire status, status should be true/false");
    }
}