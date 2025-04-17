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

set<set<string>> *CreateFlagSet
    = new set<set<string>>{
        {"-n", "-c"}, {"--name", "--category"},
        {"--name", "-c"}, {"-n", "--category"},

        {"-n", "-c", "-C"}, {"--name", "--category", "--completed"},
        {"--name", "-c", "-C"}, {"-n", "--category", "--completed"},
        {"-n", "--category", "-C"}, {"--name", "-c", "--completed"},
        {"-n", "-c", "--completed"}, {"--name", "--category", "-C"},
        {"--name", "--category", "-C"}, {"-n", "-c", "--completed"},
        {"--name", "-c", "--completed"}, {"-n", "--category", "-C"},
        {"-n", "--category", "--completed"}, {"--name", "-c", "-C"},

        {"-n", "-c", "-d"}, {"--name", "--category", "--due"},
        {"--name", "-c", "-d"}, {"-n", "--category", "--due"},
        {"-n", "--category", "-d"}, {"--name", "-c", "--due"},
        {"-n", "-c", "--due"}, {"--name", "--category", "-d"},
        {"--name", "--category", "-d"}, {"-n", "-c", "--due"},
        {"--name", "-c", "--due"}, {"-n", "--category", "-d"},
        {"-n", "--category", "--due"}, {"--name", "-c", "-d"},

        {"-n", "-c", "-d", "-C"}, {"--name", "--category", "--due", "--completed"},
        {"--name", "-c", "-d", "-C"}, {"-n", "--category", "--due", "--completed"},
        {"-n", "--category", "-d", "-C"}, {"--name", "-c", "--due", "--completed"},
        {"-n", "-c", "--due", "-C"}, {"--name", "--category", "-d", "--completed"},
        {"-n", "-c", "-d", "--completed"}, {"--name", "--category", "--due", "-C"},
        {"--name", "--category", "-d", "-C"}, {"-n", "-c", "--due", "--completed"},
        {"--name", "-c", "--due", "-C"}, {"-n", "--category", "-d", "--completed"},
        {"--name", "-c", "-d", "--completed"}, {"-n", "--category", "--due", "-C"},
        {"-n", "--category", "--due", "-C"}, {"--name", "-c", "-d", "--completed"},
        {"-n", "--category", "-d", "--completed"}, {"--name", "-c", "--due", "-C"},
        {"-n", "-c", "--due", "--completed"}, {"--name", "--category", "-d", "-C"},
        {"--name", "--category", "--due", "-C"}, {"-n", "-c", "-d", "--completed"},
        {"--name", "--category", "-d", "--completed"}, {"-n", "-c", "--due", "-C"},
        {"--name", "-c", "--due", "--completed"}, {"-n", "--category", "-d", "-C"},
        {"-n", "--category", "--due", "--completed"}, {"--name", "-c", "-d", "-C"}
    };

set<string> *ReadFlagSet 
    = new set<string>{
        "-a", "--all",
        "-i", "--id",
        "-n", "--name",
        "-c", "--category",
        "-C", "--completed",
        "-e", "--expire"
    };

set<set<string>> *UpdateFlagSet
    = new set<set<string>>{
        {"-i", "-n"}, {"--id", "--name"},
        {"--id", "-n"}, {"-i", "--name"},

        {"-i", "-c"}, {"--id", "--category"}, 
        {"--id", "-c"}, {"-i", "--category"},

        {"-i", "-C"}, {"--id", "--completed"},
        {"--id", "-C"}, {"-i", "--completed"},

        {"-i", "-d"}, {"--id", "--due"},
        {"--id", "-d"}, {"-i", "--due"},

        {"-n", "-n"}, {"--name", "--name"},
        {"--name", "-n"}, {"-n", "--name"},

        {"-n", "-c"}, {"--name", "--category"},
        {"--name", "-c"}, {"-n", "--category"},

        {"-n", "-C"}, {"--name", "--completed"},
        {"--name", "-C"}, {"-n", "--completed"},
        
        {"-n", "-d"}, {"--name", "--due"},
        {"--name", "-d"}, {"-n", "--due"}
    };

set<string> *DeleteFlagSet
    = new set<string>{
        "-i", "--id",
        "-n", "--name",
        "-c", "--category",
        "-C", "--completed",
        "-e", "--expire"
    };