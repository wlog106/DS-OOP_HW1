#include "router.h"
#include "../database/database.h"
#include <deque>
#include <string>

using namespace std;

void Delete(Database *db, deque<string> *command){

    int *id = new int;
    int *expire = new int;
    string *name = new string; 
    string *category = new string;
    bool *completed = new bool;
    
    while(command->size() != 0){

        // delete a task, search by id
        if(command->front() == "-i" || command->front() == "--id"){
            command->pop_front();
            *id = stoi(command->front());
            command->pop_front();
            db->deleteById(id);
        }

        // delete a task, search by name
        else if(command->front() == "-n" ||  command->front() == "--name"){
            command->pop_front();
            *name = command->front();
            command->pop_front();
            db->deleteByName(name);
        }

        // delete some tasks, search by category
        else if(command->front() == "-c" || command->front() == "--category"){
            command->pop_front();
            *category = command->front();
            command->pop_front();
            db->deleteByCategory(category);
        }

        // delete some tasks, search by completed
        else if(command->front() == "-C" || command->front() == "--completed"){
            command->pop_front();
            strTo_Completed(completed, &command->front());
            command->pop_front();
            db->deleteByCompleted(completed);
        }

        // list a part, search by expire
        else if(command->front() == "-e" || command->front() == "--expire"){
            command->pop_front();
            strTo_ExpireStatus(expire, &command->front());
            command->pop_front();
            db->deleteByExpire(expire);
        }
    }

    delete id;
    delete expire;
    delete name;
    delete category;
    delete completed;
    id = nullptr;
    expire = nullptr;
    name = nullptr;
    category = nullptr;
    completed = nullptr;
}