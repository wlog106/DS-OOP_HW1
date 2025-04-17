#ifdef __unix__

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <cstdlib>

#include <iostream>
#include <vector>
#include <deque>
#include "input.h"

using namespace std;


void unixCommandLine(string *buffer, deque<string> *History){

    int *ch = new int;
    vector<char> *Buffer = new vector<char>;
    auto BufferItr = Buffer->end();
    auto HistoryItr = History->end();
    system("/bin/stty raw");
    while(*ch = getchar()){
        if(*ch == 27){
            *ch = getchar();
            *ch = getchar();
            // arrow key
            if(*ch == 65){
                // Key Up
                if(HistoryItr != History->begin()){
                    setCommand(Buffer, --HistoryItr);
                    BufferItr = Buffer->end();
                }
            }
            else if(*ch == 66){
                // Key Down
                if(HistoryItr != History->end()){
                    setCommand(Buffer, ++HistoryItr);
                    BufferItr = Buffer->end();
                }
            }
            // Key Right
            else if(*ch == 67){
                if(BufferItr != Buffer->end()){
                    BufferItr++;
                }
            }
            // Key Left
            else if(*ch == 68){
                if(BufferItr != Buffer->begin()){
                    BufferItr--;
                }
            }
        }
        // backspace
        else if(*ch == 127){
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
        // printable chars
        else if(*ch >= 32 && *ch <= 126) {
            BufferItr = Buffer->insert(BufferItr, static_cast<char>(*ch));
            BufferItr++;
        }
        render(Buffer, BufferItr);
    }
    for(auto itr = Buffer->begin(); itr != Buffer->end(); itr++){
        *buffer += *itr;
    }
    system("/bin/stty cooked");

    delete Buffer;
    delete ch;
    Buffer = nullptr;
    ch = nullptr;

}

#endif
