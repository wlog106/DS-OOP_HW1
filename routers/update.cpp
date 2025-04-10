#include "router.h"
#include "../database/database.h"
#include <deque>
#include <string>

using namespace std;

void Update(Database &db, deque<string> &command){
    int id;
    string name, category, due;
    bool completed;

    // search by id
    if(command.front() == "-i"){
        command.pop_front();
        id = stoi(command.front());
        command.pop_front();
        while(command.size() != 0){

            // update name
            if(command.front() == "-n"){
                command.pop_front();
                name = command.front();
                command.pop_front();
                db.updateNameById(id, name);
            }

            // update category
            else if(command.front() == "-c"){
                command.pop_front();
                category = command.front();
                command.pop_front();
                db.updateCategoryById(id, category);
            }

            //update completed
            else if(command.front() == "-C"){
                command.pop_front();
                completed = strTo_Completed(command.front());
                command.pop_front();
                db.updateCompletedById(id, completed);
            }

            // update due
            else if(command.front() == "-d"){
                command.pop_front();
                due = command.front();
                command.pop_front();
                db.updateDueById(id, due);
            }
        }
    }

    // search by name
    else if(command.front() == "-n"){
        command.pop_front();
        name = command.front();
        command.pop_front();
        while(command.size() != 0){

            // update category
            if(command.front() == "-c"){
                command.pop_front();
                category = command.front();
                command.pop_front();
                db.updateCategoryById(id, category);
            }

            //update completed
            else if(command.front() == "-C"){
                command.pop_front();
                completed = strTo_Completed(command.front());
                command.pop_front();
                db.updateCompletedById(id, completed);
            }

            // update due
            else if(command.front() == "-d"){
                command.pop_front();
                due = command.front();
                command.pop_front();
                db.updateDueById(id, due);
            }
        }
    }
}