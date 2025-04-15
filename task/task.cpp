#include <iostream>
#include <iomanip>
#include <string>
#include "task.h"

using namespace std;

// Basic_task
Basic_task::Basic_task(){
    this->name = new string;
    this->category = new string;
    this->completed = new bool;
}
Basic_task::Basic_task(string *name, string *category, bool *completed){
    this->name = name;
    this->category = category;
    this->completed = completed;
}
Basic_task::~Basic_task(){
    delete name;
    delete category;
    delete completed;
    name = nullptr;
    category = nullptr;
    completed = nullptr;
}
void Basic_task::setName(string *name){
    delete this->name;
    this->name = name;
}
void Basic_task::setCategory(string *category){
    delete this->category;
    this->category = category;
}
void Basic_task::setCompleted(bool *completed){
    delete this->completed;
    this->completed = completed;
}

string Basic_task::getName() const{
    return *(this->name);
}
string Basic_task::getCategory() const{
    return *(this->category);
}
bool Basic_task::getCompleted() const{
    return *(this->completed);
}
string Basic_task::showCompletedState() const{
    if(*completed) return "Yes";
    return "No";
}

//Task
Task::Task(){
    expire = new int(expireState_None);
    expireTime = new time_t;
}

Task::Task(string *name, string *category, bool *completed): 
    Basic_task(name, category, completed){
    expire = new int(expireState_None);
    expireTime = new time_t;
}

Task::Task(string *name, string *category, string *due, bool *completed): 
    Basic_task(name, category, completed){
    expire = new int(expireState_None);
    expireTime = new time_t;
    setDue(due);
}

Task::~Task(){
    delete expire;
    delete expireTime;
    expire = nullptr;
    expireTime = nullptr;
}

void Task::setDue(string *due){
    tm *dueTime = new tm{0};
    dueTime->tm_year = stoi(due->substr(0, 4))-1900;
    dueTime->tm_mon  = stoi(due->substr(5, 2))-1;
    dueTime->tm_mday = stoi(due->substr(8, 2));
    dueTime->tm_hour = stoi(due->substr(11, 2));
    dueTime->tm_min  = stoi(due->substr(14, 2));
    dueTime->tm_sec  = stoi(due->substr(17, 2));
    *(this->expireTime) = mktime(dueTime);
    *expire = difftime(*expireTime, time(NULL)) < 0 ? expireState_True : expireState_False;
    delete due;
    due = nullptr;
}

void Task::setDue(time_t *t){
    expireTime = t;
    *expire = difftime(*expireTime, time(NULL)) < 0 ? expireState_True : expireState_False;
}

void Task::updateExpireState(){
    if(*expire == expireState_None) return;
    *expire = difftime(*expireTime, time(NULL)) < 0 ? expireState_True : expireState_False;
}

time_t Task::getExpireTime() const{
    return *expireTime;
}

int Task::getExpire() const{
    return *expire;
}

void Task::showRemainingTime(){

    time_t *diff = new time_t;
    *diff = difftime(*expireTime, time(NULL));

    if(*diff < 0){
        cout << setw(35) <<  "Already Expired ";
        return;
    }


    int *day = new int(*diff/(60*60*24));
    *diff %= (60*60*24);
    int *hr = new int(*diff/(60*60));
    *diff %= (60*60);
    int *min = new int(*diff/60);
    *diff %= 60;

    cout << setw(35) << to_string(*day) + " days " 
                      + to_string(*hr) + " hrs " 
                      + to_string(*min) + " mins " 
                      + to_string(*diff) + " secs ";

    delete diff;
    delete day;
    delete hr;
    delete min;
    diff = nullptr;
    day = nullptr;
    hr = nullptr;
    min = nullptr;
}

void Task::showTask(){

    string *str = new string;
    if(this->getCompleted()){
        *str = "yes";
    }
    else {
        *str = "no";
    }
    cout << setw(18) << this->getName()
         << setw(18) << this->getCategory()
         << setw(15) << *str;
    
    if(this->getExpire() != expireState_None){
        this->showRemainingTime();
    }
    else cout << setw(35) << "Due isn't set ";

    delete str;
    str = nullptr;
}
