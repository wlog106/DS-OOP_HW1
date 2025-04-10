#include "database.h"
#include "../task.h"
#include <string>

using namespace std;

// update
void Database::updateNameById(int id, string name){
    (*((*db).begin()+id))->setName(name);
}
void Database::updateCategoryById(int id, string categoery){
    (*((*db).begin()+id))->setCategory(categoery);
}
void Database::updateCompletedById(int id, bool completed){
    (*((*db).begin()+id))->setCompleted(completed);
}
void Database::updateDueById(int id, string due){
    (*((*db).begin()+id))->setDue(due);
}
void Database::updateCategoryByName(string name, string category){
    auto itr = searchByName(name);
    (*itr)->setCategory(category);
}
void Database::updateCompletedByName(string name, bool completed){
    auto itr = searchByName(name);
    (*itr)->setCompleted(completed);
}
void Database::updateDueByName(string name, string due){
    auto itr = searchByName(name);
    (*itr)->setDue(due);
}