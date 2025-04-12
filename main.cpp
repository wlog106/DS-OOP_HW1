#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include "task.h"
#include "./database/database.h"
#include "./router/router.h"
#include "./validator/validator.h"

using namespace std;


void decodeBuffer(string *buffer, deque<string> *commmand, stringstream *ss, string* str);


int main(){
    
    string *str = new string;
    stringstream *ss = new stringstream;
    deque<string> *command = new deque<string>;
    string *buffer = new string;
    Database *TodoList = new Database;

    while (getline(cin, *buffer)){

        decodeBuffer(buffer, command, ss, str);

        if(!validator(command)){
            command->clear();
            continue;
        }

        if((*command).front() == "help"){

        }
        else if((*command).front() == "exit"){
            delete ss;
            delete str;
            delete command;
            delete buffer;
            delete TodoList;
            ss = nullptr;
            str = nullptr;
            command = nullptr;
            buffer = nullptr;
            TodoList = nullptr;
            return 0;
        }

        router(TodoList, command);

        *buffer = "";
        *str = "";
        (*ss).clear();
        command->clear();
    }

}

void decodeBuffer(string *buffer, deque<string> *command, stringstream *ss, string *str){

    *ss << *buffer;
    
    while(*ss >> *str){
        command->push_back(*str);
    }

}

