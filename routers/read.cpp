#include "router.h"
#include "../database/database.h"
#include <deque>
#include <string>

using namespace std;

void Read(Database &db, deque<string> &command){
    int *id = new int;
    int *expire = new int;
    int *sortCriteria = new int;
    bool *completed = new bool;
    string *name = new string;
    string *category = new string;

    // list all, sort by sortCriteria 
    if(command.front() == "-a"){
        command.pop_front();
        strTo_SortCriteria(sortCriteria, command.front());
        command.pop_front();
        db.readAll(sortCriteria);
    }

    // list a part, search by id
    else if(command.front() == "-i"){
        command.pop_front();
        *id = stoi(command.front());
        command.pop_front();
        db.readById(id);
    }

    // list a part, search by name
    else if(command.front() == "-n"){
        command.pop_front();
        *name = command.front();
        command.pop_front();
        db.readByName(name);
    }

    // list a part, search by category
    else if(command.front() == "-c"){
        command.pop_front();
        *category = command.front();
        command.pop_front();
        db.readByCategory(category);
    }

    // list a part, search by completed
    else if(command.front() == "-C"){
        command.pop_front();
        strTo_Completed(completed, command.front());
        command.pop_front();
        db.readByCompleted(completed);
    }

    // list a part, search by expire
    else if(command.front() == "-e"){
        command.pop_front();
        strTo_ExpireState(expire, command.front());
        command.pop_front();
        db.readByExpire(expire);
    }

    delete id;
    delete expire;
    delete sortCriteria;
    delete completed;
    delete name;
    delete category;
    name = nullptr;
    category = nullptr;
    sortCriteria = nullptr;
    id = nullptr;
    expire = nullptr;
    completed = nullptr;
    
}