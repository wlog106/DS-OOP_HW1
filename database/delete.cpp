#include "database.h"
#include "../task.h"
#include <string>

using namespace std;

// delete
void Database::deleteById(int *id){

    auto itr = db->begin()+*id;
    try{
        if(itr == db->end()) throw logic_error("Id: " + to_string(*id) + " Not Found");

        existedName->erase((*itr)->getName());
        delete *itr;
        *itr = nullptr;
        db->erase(itr);

        cout << "Successfully deleted the task with Id: \"" << *id << "\"\n";
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::deleteByName(string *name){

    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Name: \"" + *name + "\" Not Found");

        existedName->erase((*itr)->getName());
        delete *itr;
        *itr = nullptr;
        db->erase(itr);

        cout << "Successfully deleted the task with Name: \"" << *name << "\"\n";
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::deleteByCategory(string *category){

    auto itrPair = searchByCategory(category);
    try{
        if(itrPair.first == db->end()) throw logic_error("Category: \"" + *category + "\" not found");

        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            existedName->erase((*itr)->getName());
            delete *itr;
            *itr = nullptr;
        }
        db->erase(itrPair.first, itrPair.second);

        cout << "Successfully deleted all the tasks in \"" + *category + "\"\n";
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::deleteByCompleted(bool *completed){

    string *state = new string("Not Completed");
    if(*completed){
        *state = "Completed";
    }

    auto itrPair = searchByCompleted(completed);
    try{
        if(itrPair.first == db->end()) throw logic_error("Completed State: \"" + *state + "\" not found");

        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            existedName->erase((*itr)->getName());
            delete *itr;
            *itr = nullptr;
        }
        db->erase(itrPair.first, itrPair.second);

        cout << "Successfully deleted all the tasks with state \"" + *state + "\"\n";
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n"; 
    }

    delete state;
    state = nullptr;
}
void Database::deleteByExpire(int *expire){

    string *state = new string("Not Expired");
    if(*expire == expireState_True){
        *state = "Expired";
    }
    else if(*expire == expireState_None){
        *state = "Due isn't set";
    }

    auto itrPair = searchByExpire(expire);
    try{
        if(itrPair.first == db->end()) throw logic_error("Expire State: \"" + *state + "\" not found");

        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            delete *itr;
            *itr = nullptr;
        }
        db->erase(itrPair.first, itrPair.second);

        cout << "Successfully deleted all the tasks with state \"" + *state + "\"\n";
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }

    delete state;
    state = nullptr;
}