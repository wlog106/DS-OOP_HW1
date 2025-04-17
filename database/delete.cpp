#include "database.h"
#include "../task/task.h"
#include <string>

using namespace std;

// delete
void Database::deleteById(int *id){

    auto itr = db->begin()+*id;
    try{
        if(itr == db->end()) throw logic_error("Task with Id: " + to_string(*id) + " Not Found");

        existedName->erase((*itr)->getName());
        delete *itr;
        *itr = nullptr;
        db->erase(itr);

        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::deleteByName(string *name){

    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Task with Name: \"" + *name + "\" Not Found");

        existedName->erase((*itr)->getName());
        delete *itr;
        *itr = nullptr;
        db->erase(itr);

        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::deleteByCategory(string *category){

    auto itrPair = searchByCategory(category);
    try{
        if(itrPair.first == db->end()) throw logic_error("Task with Category: \"" + *category + "\" not found");

        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            existedName->erase((*itr)->getName());
            delete *itr;
            *itr = nullptr;
        }
        db->erase(itrPair.first, itrPair.second);

        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }
}
void Database::deleteByCompleted(bool *completed){

    string *status = new string("Not Completed");
    if(*completed){
        *status = "Completed";
    }

    auto itrPair = searchByCompleted(completed);
    try{
        if(itrPair.first == db->end()) throw logic_error("Task with Completed Status: \"" + *status + "\" not found");

        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            existedName->erase((*itr)->getName());
            delete *itr;
            *itr = nullptr;
        }
        db->erase(itrPair.first, itrPair.second);

        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n"; 
    }

    delete status;
    status = nullptr;
}
void Database::deleteByExpire(int *expire){

    string *status = new string("Not Expired");
    if(*expire == expireStatus_True){
        *status = "Expired";
    }
    else if(*expire == expireStatus_None){
        *status = "Due isn't set";
    }

    auto itrPair = searchByExpire(expire);
    try{
        if(itrPair.first == db->end()) throw logic_error("Task with Expire Status: \"" + *status + "\" not found");

        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            delete *itr;
            *itr = nullptr;
        }
        db->erase(itrPair.first, itrPair.second);

        int *tmp = new int(sortCriteria_Name);
        readAll(tmp);
        delete tmp;
        tmp = nullptr;
    }
    catch(exception &error){
        cout << error.what() << "\n";
    }

    delete status;
    status = nullptr;
}