#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include "task.h"
#include "./database/database.h"
#include "./routers/router.h"
#include "./validators/validator.h"

using namespace std;


void decodeBuffer(string *buffer, deque<string> *commmand, stringstream *ss);


int main(){
    
    stringstream *ss = new stringstream;
    deque<string> *command = new deque<string>;
    string *buffer = new string;
    Database *TodoList = new Database;

    while (getline(cin, *buffer)){

        decodeBuffer(buffer, command, ss);

        if(!validator(command)) continue;

        if((*command).front() == "help"){

        }
        else if((*command).front() == "exit"){
            delete ss;
            delete command;
            delete buffer;
            delete TodoList;
            ss = nullptr;
            command = nullptr;
            buffer = nullptr;
            TodoList = nullptr;
            return 0;
        }

        router(TodoList, command);

        *buffer = "";
        (*ss).str("");
        command->clear();
    }

}

void decodeBuffer(string *buffer, deque<string> *command, stringstream *ss){

    string *str = new string;
    *ss << *buffer;
    
    while(*ss >> *str){
        command->push_back(*str);
    }

    delete str;
    str = nullptr;

}

