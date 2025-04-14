#include <vector>
#include <deque>
#include "input.h"


using namespace std;

bool getInput(string *buffer, deque<string> *History){

#ifdef _WIN32
    
    windowsCommandLine(buffer, History);

#else // UNIX

    unixCommandLine(buffer, History);

#endif

    return true;
}
