#pragma once

#include <vector>
#include <string>
#include <set>
#include "../task.h"

#define sortCriteria_Name 0
#define sortCriteria_Category 1
#define sortCriteria_Completed 2
#define sortCriteria_Expire 3

using namespace std;

// cmp for sort
bool cmpByName(const Task *a, const Task *b);
bool cmpByCategory(const Task *a, const Task *b);
bool cmpByCompleted(const Task *a, const Task *b);
bool cmpByExpire(const Task *a, const Task *b);

class Database {
public:
    //constructor
    Database();
    
    ~Database();

    // create
    void createWithoutDue(string *name, string *category, bool *completed);
    void createWithDue(string *name, string *category, string *due, bool *complete);

    // read
    void readAll(int *sortCriteria);
    void readById(int *id);
    void readByName(string *name);
    void readByCategory(string *category);
    void readByCompleted(bool *completed);
    void readByExpire(int *expire);

    // update
    void updateNameById(int *id, string *name);
    void updateCategoryById(int *id, string *category);
    void updateCompletedById(int *id, bool *completed);
    void updateDueById(int *id, string *due);
    void updateNameByName(string *name, string *name_);
    void updateCategoryByName(string *name, string *category);
    void updateCompletedByName(string *name, bool *completed);
    void updateDueByName(string *name, string *due);


    // delete
    void deleteById(int *id);
    void deleteByName(string *name);
    void deleteByCategory(string *category);
    void deleteByCompleted(bool *completed);
    void deleteByExpire(int *expire);


    // search
    auto searchByName(string *name)->vector<Task*>::iterator;
    auto searchByCategory(string *category)->pair<vector<Task*>::iterator, vector<Task*>::iterator>;
    auto searchByCompleted(bool *completed)->pair<vector<Task*>::iterator, vector<Task*>::iterator>;
    auto searchByExpire(int *expire)->pair<vector<Task*>::iterator, vector<Task*>::iterator>;
    
    void saveToFile(string *file);
    void loadFromFile(string *file);

private:
    vector<Task*> *db;
    set<string> *existedName;
};