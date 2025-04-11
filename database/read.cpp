#include "database.h"
#include "../task.h"
#include <string>
#include <algorithm>

using namespace std;

// read
void Database::readAll(int *sortCriteria){
    if(*sortCriteria = sortCriteria::name) sort((*db).begin(), (*db).end(), cmpByName);
    else if(*sortCriteria = sortCriteria::category) sort((*db).begin(), (*db).end(), cmpByCategory);
    else if(*sortCriteria = sortCriteria::completed) sort((*db).begin(), (*db).end(), cmpByCompleted);
    else if(*sortCriteria = sortCriteria::expire){
        for(auto itr = (*db).begin(); itr != (*db).end(); itr++){
            (*itr)->updateExpireState();
        }
        sort((*db).begin(), (*db).end(), cmpByExpire);
    }

    for(auto itr = (*db).begin(); itr != (*db).end(); itr++){
        cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
    }
}
void Database::readById(int *id){
    try{
        if(((*db).begin()+*id) >= (*db).end()) throw logic_error("Id: \"" + to_string(*id) + "\" not found\n");
        cout << "Id: " << *id << " " << *(*((*db).begin()+*id));
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::readByName(string *name){
    auto itr = searchByName(name);
    try{
        if(itr == (*db).end()) throw logic_error("Name: \"" + *name + "\" not found\n");
        cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::readByCategory(string *category){
    auto itrPair = searchByCategory(category);
    try{
        if(itrPair.first == (*db).end()) throw logic_error("Category: \"" + *category + "\" not found\n");
        for(auto itr = itrPair.first; itr != itrPair.second; itr++){
            cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
        }
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::readByCompleted(bool *completed){

    string *state = new string("Not Completed");
    if(*completed){
        *state = "Completed";
    }

    auto itrPair = searchByCompleted(completed);
    try{
        if(itrPair.first == (*db).end()) throw logic_error("Completed State: \"" + *state + "\" not found\n");
        for(auto itr = itrPair.first; itr != itrPair.second; itr++){
            cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
        }
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }

    delete state;
    state = nullptr;
}
void Database::readByExpire(int *expire){

    string *state = new string("Not Expired");
    if(*expire == expireState::True){
        *state = "Expired";
    }
    else if(*expire == expireState::None){
        *state = "Due isn't set";
    }

    auto itrPair = searchByExpire(expire);
    try{
        if(itrPair.first == (*db).end()) throw logic_error("Expire State: \"" + *state + "\" not found\n");
        for(auto itr = itrPair.first; itr != itrPair.second; itr++){
            cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
        }
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}