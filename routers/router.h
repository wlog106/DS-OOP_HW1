#pragma once

#include <string>
#include <deque>
#include "database.h"

using namespace std;

void router(Database &db, deque<string>& command);

bool strTo_Completed(string str);
int strTo_SortCriteria(string str);
int strTo_ExpireState(string str);

void Create(Database &db, deque<string> &command);
void Read(Database &db, deque<string> &command);
void Update(Database &db, deque<string> &command);
void Delete(Database &db, deque<string> &command);