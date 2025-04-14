#include <iostream>
#include <vector>
#include <deque>

#ifdef _WIN32
    #include <conio.h>
#else // UNIX
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
    if(BufferItr == Buffer->begin()) cout << "|";
    for(auto itr = Buffer->begin(); itr != Buffer->end(); itr++){
        cout << *itr;
        if(itr+1 == BufferItr) cout << "|";
    }
    //*lastRenderSize = Buffer->size();
}

bool getInput(string *buffer, deque<string> *History){
#ifdef _WIN32
    int *ch = new int;
    vector<char> *Buffer = new vector<char>;
    auto BufferItr = Buffer->end();
    auto HistoryItr = History->end();
    while(true){
        if(_kbhit()){
            *ch = _getch();
            //cout << "you press: " << *ch << "\n";
            // arrow key
            if(*ch == 224){
                *ch = _getch();
                // Key Up
                if(*ch == 72){
                    if(HistoryItr != History->begin()){
                        PrevCommand(Buffer, --HistoryItr);
                        BufferItr = Buffer->end();
                    }
                }
                // Key Down
                else if(*ch == 80){
                    if(HistoryItr != History->end()){
                        NextCommand(Buffer, ++HistoryItr);
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
                    if(BufferItr != next(Buffer->begin())){
                        BufferItr--;
                    }
                }
            }
            // backspace
            else if(*ch == 8){
                if(Buffer->size() != 0){
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

    return true;

#else // UNIX

    int *ch = new int;
    int *lastRenderSize = new int(50);
    vector<char> *Buffer = new vector<char>;
    auto BufferItr = Buffer->begin();
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
                    PrevCommand(Buffer, --HistoryItr);
                    BufferItr = Buffer->end();
                }
            }
            else if(*ch == 66){
                // Key Down
                if(HistoryItr != History->end()){
                    NextCommand(Buffer, ++HistoryItr);
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
            //printf("%p\n%p\n", BufferItr, Buffer->begin());
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

        // block invalid input (something like ctl+c won't render but it was inserted)
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
    delete lastRenderSize;
    Buffer = nullptr;
    ch = nullptr;
    lastRenderSize = nullptr;

    return true;

#endif
}
