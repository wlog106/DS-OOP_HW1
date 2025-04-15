#include "database.h"
#include "../task.h"
#include <string>
#include <algorithm>

using namespace std;

// read
void Database::readAll(int *sortCriteria){
    if(*sortCriteria == sortCriteria_Name) sort(db->begin(), db->end(), cmpByName);
    else if(*sortCriteria == sortCriteria_Category) sort(db->begin(), db->end(), cmpByCategory);
    else if(*sortCriteria == sortCriteria_Completed) sort(db->begin(), db->end(), cmpByCompleted);
    else if(*sortCriteria == sortCriteria_Expire){
        for(auto itr = db->begin(); itr != db->end(); itr++){
            (*itr)->updateExpireState();
        }
        sort(db->begin(), db->end(), cmpByExpire);
    }
    printDB(db->begin(), db->begin(), db->end());
}
void Database::readById(int *id){
    try{
        if((db->begin()+*id) >= db->end()) throw logic_error("Id: \"" + to_string(*id) + "\" not found");
        printDB(db->begin(), db->begin()+*id);
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::readByName(string *name){
    auto itr = searchByName(name);
    try{
        if(itr == db->end()) throw logic_error("Name: \"" + *name + "\" not found");
        printDB(db->begin(), itr);
    }
    catch(exception &error){
        cout << "error: " << error.what() << "\n";
    }
}
void Database::readByCategory(string *category){

    pair<vector<Task*>::iterator, vector<Task*>::iterator> *itrPair 
        = new pair<vector<Task*>::iterator, vector<Task*>::iterator>(searchByCategory(category));

    try{
        if(itrPair->first == db->end()) throw logic_error("Category: \"" + *category + "\" not found");
        printDB(db->begin(), itrPair->first, itrPair->second);
        delete itrPair;
        itrPair = nullptr;
    }
    catch(exception &error){
        delete itrPair;
        itrPair = nullptr;
        cout << "error: " << error.what() << "\n";
    }
}
void Database::readByCompleted(bool *completed){

    string *state = new string("Not Completed");
    if(*completed){
        *state = "Completed";
    }

    pair<vector<Task*>::iterator, vector<Task*>::iterator> *itrPair 
        = new pair<vector<Task*>::iterator, vector<Task*>::iterator>(searchByCompleted(completed));
    try{
        if(itrPair->first == db->end()) throw logic_error("Completed State: \"" + *state + "\" not found");
        printDB(db->begin(), itrPair->first, itrPair->second);
        delete itrPair;
        itrPair = nullptr;
    }
    catch(exception &error){
        delete itrPair;
        itrPair = nullptr;
        cout << "error: " << error.what() << "\n";
    }

    delete state;
    state = nullptr;
}
void Database::readByExpire(int *expire){

    string *state = new string("Not Expired");
    if(*expire == expireState_True){
        *state = "Expired";
    }
    else if(*expire == expireState_None){
        *state = "Due isn't set";
    }

    pair<vector<Task*>::iterator, vector<Task*>::iterator> *itrPair 
        = new pair<vector<Task*>::iterator, vector<Task*>::iterator>(searchByExpire(expire));
    try{
        if(itrPair->first == db->end()) throw logic_error("Expire State: \"" + *state + "\" not found");
        printDB(db->begin(), itrPair->first, itrPair->second);
        delete itrPair;
        itrPair = nullptr;
    }
    catch(exception &error){
        delete itrPair;
        itrPair = nullptr;
        cout << "error: " << error.what() << "\n";
    }
}