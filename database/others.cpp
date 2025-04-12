#include "../database/database.h"
#include "../task.h"
#include <string>
#include <algorithm>

using namespace std;

//construcotr
Database::Database(){
    db = new vector<Task*>(0);
    existedName = new set<string>;
}

//destructor
Database::~Database(){
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

void Database::writeToFile(){}