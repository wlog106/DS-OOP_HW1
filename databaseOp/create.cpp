#include "database.h"
#include "../task.h"
#include <string>

using namespace std;

// create
void Database::createWithoutDue(string name, string category, bool completed){
    Task *task = new Task(name, category, completed);
    (*db).push_back(task);
}

void Database::createWithDue(string name, string category, string due, bool completed){
    Task *task = new Task(name, category, due, completed);
    (*db).push_back(task);
}