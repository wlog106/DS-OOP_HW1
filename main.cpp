#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include "task.h"
#include "./databaseOp/database.h"
#include "./routers/router.h"
#include "./validators/validator.h"

using namespace std;


deque<string>& decodeBuffer(string buffer);

int main(){
    
    string buffer;
    while (getline(cin, buffer)){

        Database TodoList;
        deque<string>& command = decodeBuffer(buffer);

        if(!validator(command)){
            cout << "invalid command\n";
            continue;
        }

        if(command.front() == "help"){

        }
        else if(command.front() == "exit"){
            return 0;
        }

        router(TodoList, command);

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

