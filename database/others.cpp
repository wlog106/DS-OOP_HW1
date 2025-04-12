#include "../database/database.h"
#include "../task.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

//construcotr
Database::Database(){
    db = new vector<Task*>(0);
    existedName = new set<string>;
}

//destructor
Database::~Database(){
    for(auto itr = db->begin(); itr != db->end(); itr++){
        delete *itr;
        *itr = nullptr;
    }
    delete db; 
    delete existedName;
    db = nullptr;
    existedName = nullptr;
}


// cmp for sort
bool cmpByName(const Task *a, const Task *b){
    return a->getName() < b->getName();
}
bool cmpByCategory(const Task *a, const Task *b){
    return a->getCategory() < b->getCategory();
}
bool cmpByCompleted(const Task *a, const Task *b){
    return a->getCompleted() < b->getCompleted();
}
bool cmpByExpire(const Task *a, const Task *b){
    return a->getExpire() < b->getExpire();
}



// search
auto Database::searchByName(string *name)->vector<Task*>::iterator{
    auto itr = (*db).begin();
    for(; itr != (*db).end(); itr++){
        if((*itr)->getName() == *name) break;
    }
    return itr;
}
auto Database::searchByCategory(string *category)->pair<vector<Task*>::iterator, vector<Task*>::iterator>{
    sort((*db).begin(), (*db).end(), cmpByCategory);
    auto first = (*db).begin();
    while(first != (*db).end()){
        if((*first)->getCategory() == *category) break;
        first++;
    }
    auto second = first;
    while(second != (*db).end()){
        if((*second)->getCategory() != *category) break;
        second++;
    }
    return {first, second};
}
auto Database::searchByCompleted(bool *completed)->pair<vector<Task*>::iterator, vector<Task*>::iterator>{
    sort((*db).begin(), (*db).end(), cmpByCompleted);
    auto first = (*db).begin();
    while(first != (*db).end()){
        if((*first)->getCompleted() == *completed) break;
        first++;
    }
    auto second = first;
    while(second != (*db).end()){
        if((*second)->getCompleted() != *completed) break;
        second++;
    }
    return {first, second};
}
auto Database::searchByExpire(int *expire)->pair<vector<Task*>::iterator, vector<Task*>::iterator>{
    for(auto itr = (*db).begin(); itr != (*db).end(); itr++){
        (*itr)->updateExpireState();
    }
    sort((*db).begin(), (*db).end(), cmpByExpire);
    auto first = (*db).begin();
    while(first != (*db).end()){
        if((*first)->getExpire() == *expire) break;
        first++;
    }
    auto second = first;
    while(second != (*db).end()){
        if((*second)->getExpire() != *expire) break;
        second++;
    }
    return {first, second};
}

void Database::saveToFile(string *file){

    ofstream *out = new ofstream(*file);
    for(auto itr = db->begin(); itr != db->end(); itr++){
        *out << (*itr)->getName() << " " 
             << (*itr)->getCategory() << " "
             << (*itr)->getCompleted() << " ";
             if((*itr)->getExpire() == expireState_None){
                *out << 0 << "\n";
             }
             else{
                *out << (*itr)->getExpireTime() << "\n";
             }
    }
    out->close();
    delete out;
    out = nullptr;
}

void Database::loadFromFile(string *file){

    string *buffer = new string;
    stringstream *ss = new stringstream;
    ifstream *in = new ifstream(*file);

    while(getline(*in, *buffer)){
        *ss << *buffer;

        string *name = new string;
        string *category = new string;
        bool *completed = new bool;
        time_t *t = new time_t;

        *ss >> *name >> *category >> *completed >> *t;
        Task *task = new Task(name, category, completed);
        if(*t == 0){
            delete t;
            t = nullptr;
        }
        else {
            task->setDue(t);
        }
        db->push_back(task);
        existedName->insert(*name);
        ss->clear();
        *buffer = "";
    }
    
    delete buffer;
    delete ss;
    delete in;
    buffer = nullptr;
    ss = nullptr;
    in = nullptr;   
}