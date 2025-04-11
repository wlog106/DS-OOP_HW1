#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool flagCheck(const string &flag, const set<string> &flagSet){
    if(flagSet.find(flag) != flagSet.end()) return true;
    return false;
}

bool flagCheck(const deque<string> &command, const set<set<string>> &flagSet){
    set<string> *flags = new set<string>;
    for(auto itr = command.begin()+1; itr != command.end(); itr++){
        if((*itr)[0] == '-') (*flags).insert(*itr);
    }
    if(flagSet.find(*flags) != flagSet.end()){
        delete flags;
        return true;
    }
    delete flags;
    return false;
}

bool valueCheck(const string &flag, const string &value){

    // check name and category
    if(flag == "-n" || flag == "-c"){
        if(value.length() <= 20 && value.length() != 0){
            return true;
        }
        return false;
    }

    // check all
    else if(flag == "-a"){
        if(value == "name" || value == "category" 
            || value == "completed" || value == "expire" ){
            return true;
        }
        return false;
    }

    // check id
    else if(flag == "-i"){
        try{
            stoi(value);
            return true;
        }
        catch(exception &error){
            cout << error.what();
            return false;
        }
    }

    // check due
    else if(flag == "-d"){
        if(value.length() == 19){
            return true;
        }
        return false;
    }

    // check complete
    else if(flag == "-C"){
        if(value == "yes" || value == "no"){
            return true;
        }
        return false;
    }

    // check expire
    else if(flag == "-e"){
        if(value == "true" || value == "false"){
            return true;
        }
        return false;
    }
}

set<string> 

    ReadFlagSet = {
        "-a",
        "-i",
        "-n",
        "-c",
        "-C",
        "-e"
    },
    
    DeleteFlagSet = {
        "-i",
        "-n",
        "-c",
        "-C",
        "-e"
    };


set<set<string>> 

    CreateFlagSet = {
        {"-n", "-c"},
        {"-n", "-c", "-C"},
        {"-n", "-c", "-d"},
        {"-n", "-c", "-d", "-C"}
    },

    UpdateFlagSet = {
        {"-i", "-n"},
        {"-i", "-c"},
        {"-i", "-C"},
        {"-i", "-d"},

        {"-n", "-c"},
        {"-n", "-C"},
        {"-n", "-d"}
    };