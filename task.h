#pragma once

#include <iostream>
#include <string>

#define expireState_None 4
#define expireState_True 5
#define expireState_False 6

using namespace std;

class Basic_task{
public:
    Basic_task();
    Basic_task(string *name, string *category, bool *completed);
    virtual ~Basic_task();

    void setName(string *name);
    void setCategory(string *category);
    void setCompleted(bool *completed);

    string getName() const;
    string getCategory() const;
    bool getCompleted() const;
    string showCompletedState() const;
protected:
    string *name;
    string *category;
    bool *completed;
};

class Task: public Basic_task{
public:
    Task();
    Task(string *name, string *category, bool *completed);
    Task(string *name, string *category, string *due, bool *completed);
    ~Task();

    void setDue(string *due);
    void updateExpireState();
    int getExpire() const;
    void showRemainingTime();
private:
    int *expire;
    time_t *expireTime;
};

ostream& operator << (ostream& out, Task &task);