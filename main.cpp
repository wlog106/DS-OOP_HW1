#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include "./task/task.h"
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
void showHelpMenu();

int main(){
    
    string *str = new string;
    stringstream *ss = new stringstream;
    deque<string> *command = new deque<string>;
    string *buffer = new string;
    deque<string> *History = new deque<string>;
    Database *TodoList = new Database;

    string *file = new string("YOUR_FILE_NAME.txt");
    TodoList->loadFromFile(file);

    cout << "Type 'help' to show HELP MENU\n";

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
            showHelpMenu();
        }
        else if(command->front() == "exit" || command->front() == "quit"){

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

void showHelpMenu(){
    cout << "+--------------------------------------<-HELP-MENU->----------------------------------------+\n";
    cout << "| add <flag1> <value1> <flag2> <value2>...                                                  |\n"
         << "|    -n, --name              set the task name                                              |\n"
         << "|    -c, --category          set the task category                                          |\n"
         << "|    -C, --completed         set task as completed status (optional) (default=false)        |\n"
         << "|    -d, --due               set a due for the task (optional) (YYYY-MM-DD@hr:min:sec)      |\n"
         << "|                                                                                           |\n"
         << "| ls <flag> <value>                                                                         |\n"
         << "|    -a, --all               show tasks by selected criteria                                |\n"
         << "|                              (name/category/completed/expire)                             |\n"
         << "|    -i, --id                show task by id                                                |\n"
         << "|    -n, --name              show task by name                                              |\n"
         << "|    -c, --category          show tasks by category                                         |\n"
         << "|    -C, --completed         filter by completed status (true/false)                        |\n"
         << "|    -e, --expire            filter by expire status (true/false)                           |\n"
         << "|                                                                                           |\n"
         << "| upt <search-flag> <search-value> <update-flag> <new-value>                                |\n"
         << "|    -i, --id                search by id                                                   |\n"
         << "|    -n, --name              serach/update by name                                          |\n"
         << "|    -c, --category          update by category                                             |\n"
         << "|    -C, --completed         update the task completed status (true/false)                  |\n"
         << "|    -d, --due               update the due of the task                                     |\n"
         << "|                                                                                           |\n"
         << "| rm <flag> <value>                                                                         |\n"
         << "|    -i, --id                delete the task by selected id                                 |\n"
         << "|    -n, --name              delete the task matching the given name                        |\n"
         << "|    -c, --category          delete tasks matching the given category                       |\n"
         << "|    -C, --completed         delete tasks matching the given completed status (true/false)  |\n"
         << "|    -e, --expire            delete tasks matching the given expire status (true/false)     |\n"
         << "|                                                                                           |\n"
         << "| help                       show this menu                                                 |\n"
         << "|                                                                                           |\n"
         << "| exit/quit                  terminate the TodoList                                         |\n";
    cout << "+-------------------------------------------------------------------------------------------+\n";
}
