#include "database.h"
#include "../task/task.h"
#include <string>

using namespace std;

// create
void Database::createWithoutDue(string *name, string *category, bool *completed){
    try{
        if(existedName->find(*name) != existedName->end()){
            throw invalid_argument("Name: \'" + *name + "\' conflict, task name should be unique");
        }
        Task *task = new Task(name, category, completed);
        db->push_back(task);
        existedName->insert(*name);
        readByName(name);
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
    
}

void Database::createWithDue(string *name, string *category, string *due, bool *completed){
    try{
        if(existedName->find(*name) != existedName->end()){
            throw invalid_argument("Name: \'" + *name + "\' conflict\nTask name should be unique");
        }
        Task *task = new Task(name, category, due, completed);
        db->push_back(task);
        existedName->insert(*name);
        readByName(name);
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
    
}