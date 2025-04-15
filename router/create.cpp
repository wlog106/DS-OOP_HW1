#include "router.h"
#include "../database/database.h"
#include <deque>
#include <string>

using namespace std;

void Create(Database *db, deque<string> *command){

    bool *completed = new bool(false);
    string *name = new string; 
    string *category = new string;
    string *due = new string("null");

    // decode command
    while(command->size() != 0){
        if(command->front() == "-d" || command->front() == "--due"){
            command->pop_front();
            *due = command->front();
            command->pop_front();
        }
        else if(command->front() == "-n" || command->front() == "--name"){
            command->pop_front();
            *name = command->front();
            command->pop_front();
        }
        else if(command->front() == "-c" || command->front() == "--category"){
            command->pop_front();
            *category = command->front();
            command->pop_front();
        }
        else if(command->front() == "-C" || command->front() == "--completed"){
            command->pop_front();
            strTo_Completed(completed, &command->front());
            command->pop_front();
        }
    }

    // routing it to right function
    if(*due == "null"){
        db->createWithoutDue(name, category, completed);
        delete due;
        due = nullptr;
    }
    else{
        db->createWithDue(name, category, due, completed);
    }
}