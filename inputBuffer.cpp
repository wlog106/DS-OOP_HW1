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

void PrevCommand(vector<char> *Buffer, deque<vector<char>>::iterator HistoryItr){
    Buffer->clear();
    for(auto itr = HistoryItr->begin(); itr != HistoryItr->end(); itr++){
        Buffer->push_back(*itr);
    }
}

void NextCommand(vector<char> *Buffer, deque<vector<char>>::iterator HistoryItr){
    Buffer->clear();
    for(auto itr = HistoryItr->begin(); itr != HistoryItr->end(); itr++){
        Buffer->push_back(*itr);
    }
}

void render(const vector<char> *Buffer, int *lastRenderSize){
    int *i = new int;
    for(*i = 0; *i < *lastRenderSize; (*i)++){
        cout << "\b";
    }
    for(*i = 0; *i < *lastRenderSize; (*i)++){
        cout << " ";
    }
    for(*i = 0; *i < *lastRenderSize; (*i)++){
        cout << "\b";
    }
    delete i;
    i = nullptr;
    for(auto itr = Buffer->begin(); itr != Buffer->end(); itr++){
        cout << *itr;
    }
    *lastRenderSize = Buffer->size();
}


bool getInput(string *buffer){
#ifdef _WIN32

#else
    int *ch = new int;
    int *lastRenderSize = new int(0);
    vector<char> *Buffer = new vector<char>;
    auto BufferItr = Buffer->end();
    auto HistoryItr = History->end();
    while((*ch = getchar()) != '\n'){
        if(*ch == 27){
            *ch = getchar();
            *ch = getchar();
            if(*ch == 65){
                if(HistoryItr != History->begin()){
                    PrevCommand(Buffer, HistoryItr--);
                    BufferItr = Buffer->end();
                }
            }
            else if(*ch == 66){
                if(HistoryItr != History->end()){
                    NextCommand(Buffer, HistoryItr--);
                    BufferItr = Buffer->end();
                }
            }
            else if(*ch == 67){
                if(BufferItr != Buffer->end()){
                    BufferItr++;
                }
            }
            else if(*ch == 68){
                if(BufferItr != Buffer->begin()){
                    BufferItr--;
                }
            }
        }
        else if(*ch == 127){
            if(Buffer->size() != 0){
                Buffer->erase(BufferItr);
            }
        }
        else {
            Buffer->insert(BufferItr, static_cast<char>(*ch));
        }
        render(Buffer, lastRenderSize);
    }
    for(auto itr = Buffer->begin(); itr != Buffer->end(); itr++){
        buffer->at(itr-Buffer->begin()) = *itr;
    }
    delete Buffer;
    delete ch;
    delete lastRenderSize;
    Buffer = nullptr;
    ch = nullptr;
    lastRenderSize = nullptr;

    return true;
    
#endif
}

deque<vector<char>> *History = new deque<vector<char>>;