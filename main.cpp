#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include "task.h"
#include "./databaseOp/database.h"
#include "./routers/router.h"

using namespace std;

deque<string>& decodeBuffer(string buffer);
bool commandValidator(deque<string>& command);

int main(){
    
    string buffer;
    while (getline(cin, buffer)){

        Database TodoList;
        deque<string>& command = decodeBuffer(buffer);

        if(!commandValidator(command)){
            cout << "invalid command\n";
            continue;
        }

        if(command.front() == "add"){
            command.pop_front();
            Create(TodoList, command);    
        }
        else if(command.front() == "ls"){
            command.pop_front();
            Read(TodoList, command);
        }
        else if(command.front() == "upt"){
            command.pop_front();
            Update(TodoList, command);
        }
        else if(command.front() == "rm"){
            command.pop_front();
            Delete(TodoList, command);
        }
        else if(command.front() == "help"){

        }
        else if(command.front() == "exit"){
            return 0;
        }

        buffer = "";
    }

}

deque<string>& decodeBuffer(string buffer){
    string str;
    deque<string> tmp;
    stringstream ss;
    ss << buffer;
    
    while(ss >> str){
        tmp.push_back(str);
    }

    return tmp;
}

bool commandValidator(deque<string>& command){

}