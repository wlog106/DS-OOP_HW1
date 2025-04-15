#include "database.h"
#include "../task.h"
#include <string>

using namespace std;

// update
void Database::updateNameById(int *id, string *name){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: " + to_string(*id) + " Not Found");
        (*(db->begin()+*id))->setName(name);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCategoryById(int *id, string *categoery){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: " + to_string(*id) + " Not Found");
        (*(db->begin()+*id))->setCategory(categoery);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCompletedById(int *id, bool *completed){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: " + to_string(*id) + " Not Found");
        (*(db->begin()+*id))->setCompleted(completed);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateDueById(int *id, string *due){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: " + to_string(*id) + " Not Found");
        (*(db->begin()+*id))->setDue(due);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateNameByName(string *name, string *name_){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \"" + *name + "\" Not Found");
        (*itr)->setName(name_);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCategoryByName(string *name, string *category){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \"" + *name + "\" Not Found");
        (*itr)->setCategory(category);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCompletedByName(string *name, bool *completed){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \"" + *name + "\" Not Found");
        (*itr)->setCompleted(completed);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateDueByName(string *name, string *due){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \"" + *name + "\" Not Found");
        (*itr)->setDue(due);
        readAll(sortCriteria_Name);
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}