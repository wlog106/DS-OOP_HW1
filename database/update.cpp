#include "database.h"
#include "../task/task.h"
#include <string>

using namespace std;

void Database::updateNameById(int *id, string *name){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: \'" + to_string(*id) + "\' Not Found");
        (*(db->begin()+*id))->setName(name);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCategoryById(int *id, string *categoery){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: \'" + to_string(*id) + "\' Not Found");
        (*(db->begin()+*id))->setCategory(categoery);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCompletedById(int *id, bool *completed){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: \'" + to_string(*id) + "\' Not Found");
        (*(db->begin()+*id))->setCompleted(completed);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateDueById(int *id, string *due){
    try{
        if(db->begin()+*id >= db->end()) throw logic_error("Task with Id: \'" + to_string(*id) + "\' Not Found");
        (*(db->begin()+*id))->setDue(due);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateNameByName(string *name, string *name_){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \'" + *name + "\' Not Found");
        (*itr)->setName(name_);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCategoryByName(string *name, string *category){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \'" + *name + "\' Not Found");
        (*itr)->setCategory(category);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateCompletedByName(string *name, bool *completed){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \'" + *name + "\' Not Found");
        (*itr)->setCompleted(completed);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::updateDueByName(string *name, string *due){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \'" + *name + "\' Not Found");
        (*itr)->setDue(due);
        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}