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

void setCommand(vector<char> *Buffer, deque<string>::iterator HistoryItr);
void render(const vector<char> *Buffer, const vector<char>::iterator BufferItr);
bool getInput(string *buffer, deque<string> *History);
