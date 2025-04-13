#include <iostream>
#include <vector>
#include <deque>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
#endif

using namespace std;

void PrevCommand(vector<char> *Buffer, deque<string>::iterator HistoryItr);
void NextCommand(vector<char> *Buffer, deque<string>::iterator HistoryItr);
void render(const vector<char> *Buffer, int *lastRenderSize);
bool getInput(string *buffer, deque<string> *History);
