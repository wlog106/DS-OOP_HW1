#include "database.h"
#include "../task.h"
#include <string>

using namespace std;

// delete
void Database::deleteById(int id){
    auto itr = (*db).begin()+id;
    if(itr != (*db).end()){
        delete *itr;
        *itr = nullptr;
        (*db).erase(itr);
        return;
    }
    cout << "No such task\n";
}
void Database::deleteByName(string name){
    auto itr = searchByName(name);
    if(itr != (*db).end()){
        delete *itr;
        *itr = nullptr;
        (*db).erase(itr);
        return;
    }
    cout << "No such task\n";
}
void Database::deleteByCategory(string category){
    auto itrPair = searchByCategory(category);
    if(itrPair.first != (*db).end()){
        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            delete *itr;
            *itr = nullptr;
        }
        (*db).erase(itrPair.first, itrPair.second);
        cout << "Successfully delete all the members in " << category << "\n";
        return;
    }
    cout << "Category: " << category << " not found\n";
}
void Database::deleteByCompleted(bool completed){
    auto itrPair = searchByCompleted(completed);
    if(itrPair.first != (*db).end()){
        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            delete *itr;
            *itr = nullptr;
        }
        (*db).erase(itrPair.first, itrPair.second);
        cout << "Successfully delete all the members in " << category << "\n";
        return;
    }
    cout << "Category: " << category << " not found\n";
}
void Database::deleteByExpire(int expire){
    auto itrPair = searchByExpire(expire);
    if(itrPair.first != (*db).end()){
        for(auto itr = itrPair.first; itr!=itrPair.second; itr++){
            delete *itr;
            *itr = nullptr;
        }
        (*db).erase(itrPair.first, itrPair.second);
        cout << "Successfully delete all the members in " << category << "\n";
        return;
    }
    cout << "Category: " << category << " not found\n";
}