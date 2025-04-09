#include "router.h"
#include "../databaseOp/database.h"
#include <deque>
#include <string>

using namespace std;

void Create(Database &db, deque<string> &command){
    bool completed;
    string name, category, due = "null";

    // decode command
    while(command.size() != 0){
        if(command.front() == "-d"){
            command.pop_front();
            due = command.front();
            command.pop_front();
        }
        else if(command.front() == "-n"){
            command.pop_front();
            name = command.front();
            command.pop_front();
        }
        else if(command.front() == "-c"){
            command.pop_front();
            category = command.front();
            command.pop_front();
        }
        else if(command.front() == "-C"){
            command.pop_front();
            completed = strTo_Completed(command.front());
            command.pop_front();
        }
    }

    // routing it to right function
    if(due == "null"){
        db.createWithoutDue(name, category, completed);
    }
    else{
        db.createWithDue(name, category, due, completed);
    }
}