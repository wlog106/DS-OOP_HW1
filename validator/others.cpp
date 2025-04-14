#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool flagCheck(const deque<string> *command, const set<string> *flagSet){
    try{
        if(command->size() == 1 || (flagSet->find(command->at(1)) == flagSet->end())){
            throw invalid_argument("invalid flags");
        }
        return true;
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
        return false;
    }
}

bool flagCheck(const deque<string> *command, const set<set<string>> *flagSet){
    set<string> *flags = new set<string>;
    for(auto itr = command->begin()+1; itr != command->end(); itr++){
        if((*itr)[0] == '-') flags->insert(*itr);
    }
    try{
        if(flagSet->find(*flags) == flagSet->end()){
            throw invalid_argument("invalid flags");
        }
        delete flags;
        flags = nullptr;
        return true;
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
        delete flags;
        flags = nullptr;
        return false;
    }
}

bool valueCheck(const string *flag, const string *value){

    // check name and category
    if(*flag == "-n" || *flag == "-c"){
        try{
            if(value->length() > 20 || value->length() ==0 ){
                throw invalid_argument("Length should be between 1 and 20");
            }
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check all
    else if(*flag == "-a"){
        try{
            if(*value != "name" && *value != "category" && *value != "completed" && *value != "expire"){
                throw invalid_argument("invalid sort criteria");
            }
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check id
    else if(*flag == "-i"){
        try{
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
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check due
    else if(*flag == "-d"){
        try{
            if(value->at(4) != '-' || value->at(7) != '-' || value->at(10) != '@' 
               || value->at(13) != ':' || value->at(16) != ':' || value->length() != 19){
                throw invalid_argument("invalid format: \"" + *value + "\" \nType \"help\" to see correct format");
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
                    cout << value->at(0) << "\n";
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
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check complete
    else if(*flag == "-C"){
        try{
            if(*value != "yes" && *value != "no"){
                throw invalid_argument("invalid completed state");
            }
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // check expire
    else if(*flag == "-e"){
        try{
            if(*value != "true" && *value != "false"){
                throw invalid_argument("invalid completed state");
            }
            return true;
        }
        catch(exception &error){
            cout << "error: " << error.what() << "\n";
            return false;
        }
    }

    // because of flag check, program shouldn't reach this line
    return false;
}

bool isValidDay(const int *year, const int *mon, const int *day){
    cout << "year: " << *year << " mon: " << *mon << " day: " << *day << "\n";
    // big month
    if(*mon == 1 || *mon == 3 || *mon == 5 || *mon == 7 || *mon == 8 || *mon == 10 || *mon == 12){
        if(*day < 1 || *day > 31){
            return false;
        }
        return true;
    }
    // small month
    else if(*mon == 4 || *mon == 6 || *mon == 9 || *mon == 11){
        if(*day < 1 || *day > 30){
            return false;
        }
        return true;
    }
    // check leap year
    else if(*mon == 2){
        if(isLeapYear(year) && (*day < 1 || *day > 29)){
            return false;
        }
        else if(!isLeapYear(year) && (*day < 1 || *day > 28)){
            return false;
        }
        return true; 
    }
    // invalid month
    else{
        return false;
    }
}

bool isLeapYear(const int *year){
    if(*year%4 != 0){
        return false;
    }
    if(*year%100 != 0){
        return true;
    }
    if(*year%400 != 0){
        return false;
    }
    return true;
}

set<set<string>> *CreateFlagSet
    = new set<set<string>>{
        {"-n", "-c"},
        {"-n", "-c", "-C"},
        {"-n", "-c", "-d"},
        {"-n", "-c", "-d", "-C"}
    };

set<string> *ReadFlagSet 
    = new set<string>{
        "-a",
        "-i",
        "-n",
        "-c",
        "-C",
        "-e"
    };

set<set<string>> *UpdateFlagSet
    = new set<set<string>>{
        {"-i", "-n"},
        {"-i", "-c"},
        {"-i", "-C"},
        {"-i", "-d"},

        {"-n", "-c"},
        {"-n", "-C"},
        {"-n", "-d"}
    };

set<string> *DeleteFlagSet
    = new set<string>{
        "-i",
        "-n",
        "-c",
        "-C",
        "-e"
    };