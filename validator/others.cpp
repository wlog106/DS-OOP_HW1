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
            stoi(*value);
            return true;
        }
        catch(exception &error){
            cout << "error: Id should be integer\n";
            return false;
        }
    }

    // check due
    else if(*flag == "-d"){
        try{
            if(value->at(4) != '-' || value->at(7) != '-' || value->at(10) != '@' 
               || value->at(13) != ':' || value->at(16) != ':' || value->length() != 19){
                throw "invalid format: \"" + *value + "\" \nType \"help\" to see correct format";
            }
            // should add 0 <= hr < 24 etc
            stoi(value->substr(0, 4));
            stoi(value->substr(5, 2));
            stoi(value->substr(8, 2));
            stoi(value->substr(11, 2));
            stoi(value->substr(14, 2));
            stoi(value->substr(17, 2));
            return true;
        }
        catch(const string &error){
            cout << "error: " << error << "\n";
            return false;
        }
        catch(exception &error){
            cout << "error: fail to convert " << *value << " to proper format\n";
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