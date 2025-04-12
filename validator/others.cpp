#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool flagCheck(const string *flag, const set<string> *flagSet){
    try{
        if(flagSet->find(*flag) == flagSet->end()){
            throw new invalid_argument("invalid flags");
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
        if((*itr)[0] == '-') (*flags).insert(*itr);
    }
    try{
        if(flagSet->find(*flags) == flagSet->end()){
            throw new invalid_argument("invalid flags");
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
                throw new invalid_argument("Length should be between 1 and 20");
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
        if(*value == "name" || *value == "category" 
            || *value == "completed" || *value == "expire" ){
            return true;
        }
        return false;
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

        }
        catch(exception &error){
            
        }
        if(value->length() == 19){
            return true;
        }
        return false;
    }

    // check complete
    else if(*flag == "-C"){
        if(*value == "yes" || *value == "no"){
            return true;
        }
        return false;
    }

    // check expire
    else if(*flag == "-e"){
        if(*value == "true" || *value == "false"){
            return true;
        }
        return false;
    }

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