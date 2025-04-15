#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include "task.h"
#include "./database/database.h"
#include "./router/router.h"
#include "./validator/validator.h"
#include "./input/input.h"

#ifdef _WIN32
    #define symbol ">>> |"
#else
    #define symbol "──> |"
#endif


using namespace std;


void decodeBuffer(string *buffer, deque<string> *commmand, stringstream *ss, string* str);


int main(){
    
    string *str = new string;
    stringstream *ss = new stringstream;
    deque<string> *command = new deque<string>;
    string *buffer = new string;
    deque<string> *History = new deque<string>;
    Database *TodoList = new Database;

    string *file = new string("disk.txt");
    TodoList->loadFromFile(file);

    cout << symbol;

    while (getInput(buffer, History)){

        cout << "\r";

        decodeBuffer(buffer, command, ss, str);

        if(command->size() == 0){
            *buffer = "";
            *str = "";
            ss->clear();
            command->clear();
            cout << symbol;
            continue;
        }
        else {
            History->push_back(*buffer);
        }
        

        if(!validator(command)){
            *buffer = "";
            *str = "";
            ss->clear();
            command->clear();
            cout << symbol;
            continue;
        }

        if(command->front() == "help"){
            
        }
        else if(command->front() == "exit"){

            TodoList->saveToFile(file);
            
            delete History;
            delete file;
            delete ss;
            delete str;
            delete command;
            delete buffer;
            delete TodoList;
            History = nullptr;
            file = nullptr;
            ss = nullptr;
            str = nullptr;
            command = nullptr;
            buffer = nullptr;
            TodoList = nullptr;
            
            return 0;
        }
        else {
            router(TodoList, command);
        }

    
        *buffer = "";
        *str = "";
        ss->clear();
        command->clear();

        cout << symbol;
    }
}

void decodeBuffer(string *buffer, deque<string> *command, stringstream *ss, string *str){

    *ss << *buffer;
    
    while(*ss >> *str){
        command->push_back(*str);
    }

}

