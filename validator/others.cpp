#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include "validator.h"

using namespace std;

bool isValidDay(const int *year, const int *mon, const int *day){
    // big month
    if(*mon == 1 || *mon == 3 || *mon == 5 || *mon == 7 || *mon == 8 || *mon == 10 || *mon == 12){
        if(*day < 1 || *day > 31){
            return false;
        }
        return true;
    }
    // small month
    else if(*mon == 4 || *mon == 6 || *mon == 9 || *mon == 11){
        if(*day < 1 || *day > 30){
            return false;
        }
        return true;
    }
    // check leap year
    else if(*mon == 2){
        if(isLeapYear(year) && (*day < 1 || *day > 29)){
            return false;
        }
        else if(!isLeapYear(year) && (*day < 1 || *day > 28)){
            return false;
        }
        return true; 
    }
    // invalid month
    else{
        return false;
    }
}

bool isLeapYear(const int *year){
    if(*year%4 != 0){
        return false;
    }
    if(*year%100 != 0){
        return true;
    }
    if(*year%400 != 0){
        return false;
    }
    return true;
}