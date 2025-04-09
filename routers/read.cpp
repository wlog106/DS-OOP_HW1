#include "router.h"
#include "../databaseOp/database.h"
#include <deque>
#include <string>

using namespace std;

void Read(Database &db, deque<string> &command){
    int id, expire, sortCriteria;
    bool completed;
    string name, category;

    // list all, sort by sortCriteria 
    if(command.front() == "-a"){
        command.pop_front();
        sortCriteria = strTo_SortCriteria(command.front());
        command.pop_front();
        db.readAll(sortCriteria);
    }

    // list a part, search by id
    else if(command.front() == "-i"){
        command.pop_front();
        id = stoi(command.front());
        command.pop_front();
        db.readById(id);
    }

    // list a part, search by name
    else if(command.front() == "-n"){
        command.pop_front();
        name = command.front();
        command.pop_front();
        db.readByName(name);
    }

    // list a part, search by category
    else if(command.front() == "-c"){
        command.pop_front();
        category = command.front();
        command.pop_front();
        db.readByCategory(category);
    }

    // list a part, search by completed
    else if(command.front() == "-C"){
        command.pop_front();
        completed = strTo_Completed(command.front());
        command.pop_front();
        db.readByCompleted(completed);
    }

    // list a part, search by expire
    else if(command.front() == "-e"){
        command.pop_front();
        expire = strTo_ExpireState(command.front());
        command.pop_front();
        db.readByExpire(expire);
    }
}