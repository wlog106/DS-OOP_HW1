#ifdef _WIN32

#include <conio.h>

#include <iostream>
#include <vector>
#include <deque>
#include "input.h"

using namespace std;


void windowsCommandLine(string *buffer, deque<string> *History){

    int *ch = new int;
    vector<char> *Buffer = new vector<char>;
    auto BufferItr = Buffer->end();
    auto HistoryItr = History->end();
    while(true){
        if(_kbhit()){
            *ch = _getch();
            
            // arrow key
            if(*ch == 224){
                *ch = _getch();
                // Key Up
                if(*ch == 72){
                    if(HistoryItr != History->begin()){
                        setCommand(Buffer, --HistoryItr);
                        BufferItr = Buffer->end();
                    }
                }
                // Key Down
                else if(*ch == 80){
                    if(HistoryItr != History->end()){
                        setCommand(Buffer, ++HistoryItr);
                        BufferItr = Buffer->end();
                    }
                }
                // Key Right
                else if(*ch == 77){
                    if(BufferItr != Buffer->end()){
                        BufferItr++;
                    }
                }
                // Key Left
                else if(*ch == 75){
                    if(BufferItr != Buffer->begin()){
                        BufferItr--;
                    }
                }
            }
            // backspace
            else if(*ch == 8){
                if(BufferItr != Buffer->begin()){
                    BufferItr--;
                    Buffer->erase(BufferItr);
                }
            }
            // enter
            else if(*ch == 13){
                render(Buffer, Buffer->end());
                cout << "\b \b\n";
                break;
            }
            // block some wired input
            else if(*ch >= 32 && *ch <= 126){
                BufferItr = Buffer->insert(BufferItr, static_cast<char>(*ch));
                BufferItr++;
            }
            render(Buffer, BufferItr);

        }
    }
    for(auto itr = Buffer->begin(); itr != Buffer->end(); itr++){
        *buffer += *itr;
    }
    delete Buffer;
    delete ch;
    Buffer = nullptr;
    ch = nullptr;
}

#endif