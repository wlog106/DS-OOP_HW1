#include <iostream>
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
    expire = new int(expireState::None);
    expireTime = new time_t;
}

Task::Task(string *name, string *category, bool *completed): 
    Basic_task(name, category, completed){
    expire = new int(expireState::None);
    expireTime = new time_t;
}

Task::Task(string *name, string *category, string *due, bool *completed): 
    Basic_task(name, category, completed){
    expire = new int(expireState::None);
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
    (*dueTime).tm_year = stoi((*due).substr(0, 4))-1900;
    (*dueTime).tm_mon  = stoi((*due).substr(5, 2))-1;
    (*dueTime).tm_mday = stoi((*due).substr(8, 2));
    (*dueTime).tm_hour = stoi((*due).substr(11, 2));
    (*dueTime).tm_min  = stoi((*due).substr(14, 2));
    (*dueTime).tm_sec  = 0;
    *(this->expireTime) = mktime(dueTime);
    *expire = difftime(*expireTime, time(NULL)) < 0 ? expireState::True : expireState::False;
    delete due;
    due = nullptr;
}

void Task::updateExpireState(){
    if(*expire == expireState::None) return;
    *expire = difftime(*expireTime, time(NULL)) < 0 ? expireState::True : expireState::False;
}

int Task::getExpire() const{
    return *expire;
}

string Task::showRemainingTime(){

    time_t *diff = new time_t;
    *diff = difftime(*expireTime, time(NULL));

    if(*diff < 0){
        return "Already Expired!";
    }

    int day, hr, min;
    day = *diff/(60*60*24);
    *diff %= (60*60*24);
    hr = *diff/(60*60);
    *diff %= (60*60);
    min = *diff/60;
    *diff %= 60;

    delete diff;
    diff = nullptr;

    return to_string(day) + " days " + to_string(hr) + " hours " + to_string(min) + " minutes";
}

ostream& operator << (ostream& out, Task &task){

    out << " Name: " << task.getName() << " " 
        << "Category: " << task.getCategory() << " " 
        << "CompletedState: " << task.showCompletedState() << " "
        << "Time Remainig: ";
    
    if(task.getExpire() != expireState::None){
        out << task.showRemainingTime();
    }
    else out << "Due isn't set";

    out << "\n";

    return out;
}
