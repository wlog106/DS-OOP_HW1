#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <string>

using namespace std;

bool validator(deque<string>& command);

bool flagCheck(string flag, set<string> flagSet);
bool flagCheck(deque<string> &command, set<set<string>> flagSet);

bool valueCheck(string flag, string value);

bool CreateValidator(deque<string> &command);

bool ReadValidator(string flag, string value);

bool UpdateValidator(deque<string> &command);

bool DeleteValidator(string flag, string value);


extern set<string> ReadFlagSet, DeleteFlagSet;


extern set<set<string>> CreateFlagSet, UpdateFlagSet;