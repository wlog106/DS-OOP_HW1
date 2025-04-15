#include "router.h"
#include "../database/database.h"
#include <deque>
#include <string>

using namespace std;

void Update(Database *db, deque<string> *command){

    // search by id
    if(command->front() == "-i" || command->front() == "--id"){
        command->pop_front();
        int *id = new int(stoi(command->front()));
        command->pop_front();
        while(command->size() != 0){

            // update name
            if(command->front() == "-n" || command->front() == "--name"){
                command->pop_front();
                string *name = new string(command->front());
                command->pop_front();
                db->updateNameById(id, name);
            }

            // update category
            else if(command->front() == "-c" || command->front() == "--category"){
                command->pop_front();
                string *category = new string(command->front());
                command->pop_front();
                db->updateCategoryById(id, category);
            }

            //update completed
            else if(command->front() == "-C" || command->front() == "--completed"){
                command->pop_front();
                bool *completed = new bool;
                strTo_Completed(completed, &command->front());
                command->pop_front();
                db->updateCompletedById(id, completed);
            }

            // update due
            else if(command->front() == "-d" || command->front() == "--due"){
                command->pop_front();
                string *due = new string(command->front());
                command->pop_front();
                db->updateDueById(id, due);
            }
        }
        delete id;
        id = nullptr;
    }

    // search by name
    else if(command->front() == "-n" || command->front() == "--name"){
        command->pop_front();
        string *name = new string(command->front());
        command->pop_front();
        while(command->size() != 0){

            // update name
            if(command->front() == "-n" || command->front() == "--name"){
                command->pop_front();
                string *name_ = new string(command->front());
                command->pop_front();
                db->updateNameByName(name, name_);
            }

            // update category
            else if(command->front() == "-c" || command->front() == "--category"){
                command->pop_front();
                string *category = new string(command->front());
                command->pop_front();
                db->updateCategoryByName(name, category);
            }

            //update completed
            else if(command->front() == "-C" || command->front() == "--completed"){
                command->pop_front();
                bool *completed = new bool;
                strTo_Completed(completed, &command->front());
                command->pop_front();
                db->updateCompletedByName(name, completed);
            }

            // update due
            else if(command->front() == "-d" || command->front() == "--due"){
                command->pop_front();
                string *due = new string(command->front());
                command->pop_front();
                db->updateDueByName(name, due);
            }
        }
        delete name;
        name = nullptr;
    }
}