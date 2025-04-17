#pragma once

#include <iostream>
#include <string>

#define expireStatus_None 4
#define expireStatus_True 5
#define expireStatus_False 6

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
    string showCompletedStatus() const;
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
    void setDue(time_t *t);
    void updateExpireStatus();
    int getExpire() const;
    time_t getExpireTime() const;
    void showRemainingTime();
    void showTask();
private:
    int *expire;
    time_t *expireTime;
};
