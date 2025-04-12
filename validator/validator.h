#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>

using namespace std;

bool validator(const deque<string> *command);

bool flagCheck(const string *flag, const set<string> *flagSet);
bool flagCheck(const deque<string> *command, const set<set<string>> *flagSet);

bool valueCheck(const string *flag, const string *value);

bool CreateValidator(const deque<string> *command);

bool ReadValidator(const string *flag, const string *value);

bool UpdateValidator(const deque<string> *command);

bool DeleteValidator(const string *flag, const string *value);


extern set<string> *ReadFlagSet, *DeleteFlagSet;

extern set<set<string>> *CreateFlagSet, *UpdateFlagSet;