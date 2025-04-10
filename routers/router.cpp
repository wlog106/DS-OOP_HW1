#include "router.h"
#include "../databaseOp/database.h"
#include <deque>
#include <string>

using namespace std;

void router(Database &db, deque<string>& command){
    if(command.front() == "add"){
        command.pop_front();
        Create(db, command);    
    }
    else if(command.front() == "ls"){
        command.pop_front();
        Read(db, command);
    }
    else if(command.front() == "upt"){
        command.pop_front();
        Update(db, command);
    }
    else if(command.front() == "rm"){
        command.pop_front();
        Delete(db, command);
    }
}