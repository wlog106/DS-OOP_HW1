#include "database.h"
#include "../task.h"
#include <string>
#include <algorithm>

using namespace std;

// read
void Database::readAll(int sortCriteria){
    if(sortCriteria = sortCriteria::name) sort((*db).begin(), (*db).end(), cmpByName);
    else if(sortCriteria = sortCriteria::category) sort((*db).begin(), (*db).end(), cmpByCategory);
    else if(sortCriteria = sortCriteria::completed) sort((*db).begin(), (*db).end(), cmpByCompleted);
    else if(sortCriteria = sortCriteria::expire){
        for(auto itr = (*db).begin(); itr != (*db).end(); itr++){
            (*itr)->updateExpireState();
        }
        sort((*db).begin(), (*db).end(), cmpByExpire);
    }

    for(auto itr = (*db).begin(); itr != (*db).end(); itr++){
        cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
    }
}
void Database::readById(int id){
    cout << "Id: " << id << " " << *(*((*db).begin()+id));
}
void Database::readByName(string name){
    auto itr = searchByName(name);
    cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
}
void Database::readByCategory(string category){
    auto itrPair = searchByCategory(category);
    for(auto itr = itrPair.first; itr != itrPair.second; itr++){
        cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
    }
}
void Database::readByCompleted(bool completed){
    auto itrPair = searchByCompleted(completed);
    for(auto itr = itrPair.first; itr != itrPair.second; itr++){
        cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
    }
}
void Database::readByExpire(int expire){
    auto itrPair = searchByExpire(expire);
    for(auto itr = itrPair.first; itr != itrPair.second; itr++){
        cout << "Id: " << itr-(*db).begin() << " " << *(*itr);
    }
}