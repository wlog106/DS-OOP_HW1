#include <iostream>
#include <vector>
#include <deque>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #include <cstdlib>
#endif

using namespace std;

void PrevCommand(vector<char> *Buffer, deque<string>::iterator HistoryItr){
    Buffer->clear();
    int *i = new int;
    for(*i = 0; *i < HistoryItr->length(); (*i)++){
        Buffer->push_back(HistoryItr->at(*i));
    }
    delete i;
    i = nullptr;
}

void NextCommand(vector<char> *Buffer, deque<string>::iterator HistoryItr){
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
    for(auto itr = Buffer->begin(); itr != Buffer->end(); itr++){
        cout << *itr;
        if(itr+1 == BufferItr) cout << "|";
    }
    //*lastRenderSize = Buffer->size();
}

bool getInput(string *buffer, deque<string> *History){
#ifdef _WIN32

#else
    int *ch = new int;
    int *lastRenderSize = new int(50);
    vector<char> *Buffer = new vector<char>;
    auto BufferItr = Buffer->end();
    auto HistoryItr = History->end();
    system("/bin/stty raw");
    while(*ch = getchar()){
         if(*ch == 27){
            *ch = getchar();
            *ch = getchar();
            if(*ch == 65){
                if(HistoryItr != History->begin()){
                    PrevCommand(Buffer, --HistoryItr);
                    BufferItr = Buffer->end();
                }
            }
            else if(*ch == 66){
                if(HistoryItr != History->end()){
                    NextCommand(Buffer, ++HistoryItr);
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
                BufferItr--;
                Buffer->erase(BufferItr);
            }
        }
        else if(*ch == 13){
            cout << "\b\b  \b\b\n";
            break;
        }
        else {
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
    delete lastRenderSize;
    Buffer = nullptr;
    ch = nullptr;
    lastRenderSize = nullptr;

    return true;

#endif
}
