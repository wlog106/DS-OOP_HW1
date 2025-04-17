#pragma once

#include <string>
#include <deque>
#include "../database/database.h"

using namespace std;

void router(Database *db, deque<string> *command);

void strTo_Completed(bool *completed, string *str);
void strTo_SortCriteria(int *sortCriteria, string *str);
void strTo_ExpireStatus(int *expire, string *str);

void Create(Database *db, deque<string> *command);
void Read(Database *db, deque<string> *command);
void Update(Database *db, deque<string> *command);
void Delete(Database *db, deque<string> *command);