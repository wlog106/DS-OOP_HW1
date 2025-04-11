#include "database.h"
#include "../task.h"
#include <string>

using namespace std;

// create
void Database::createWithoutDue(string name, string category, bool completed){
    try{
        Task *task = new Task(name, category, completed);
        (*db).push_back(task);
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
    
}

void Database::createWithDue(string name, string category, string due, bool completed){
    try{
        Task *task = new Task(name, category, due, completed);
        (*db).push_back(task);
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
    
}