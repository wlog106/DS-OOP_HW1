#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void setCommand(vector<char> *Buffer, deque<string>::iterator HistoryItr){
    Buffer->clear();
    int *i = new int;
    for(*i = 0; *i < HistoryItr->length(); (*i)++){
        Buffer->push_back(HistoryItr->at(*i));
    }
    delete i;
    i = nullptr;
}

void render(const vector<char> *Buffer, const vector<char>::iterator BufferItr){
    int *i = new int;
    cout << "\r";
    for(*i = 0; *i < 50; (*i)++){
        cout << " ";
    }
    for(*i = 0; *i < 50; (*i)++){
        cout << "\b";
    }
    cout << "──> ";
    delete i;
    i = nullptr;
    if(BufferItr == Buffer->begin()) cout << "|";
    for(auto itr = Buffer->begin(); itr != Buffer->end(); itr++){
        cout << *itr;
        if(itr+1 == BufferItr) cout << "|";
    }
}