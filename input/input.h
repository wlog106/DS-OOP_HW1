#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void unixCommandLine(string *buffer, deque<string> *History);
void windowsCommandLine(string *buffer, deque<string> *History);
void setCommand(vector<char> *Buffer, deque<string>::iterator HistoryItr);
void render(const vector<char> *Buffer, const vector<char>::iterator BufferItr);
bool getInput(string *buffer, deque<string> *History);
