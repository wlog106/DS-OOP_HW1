Tree  
---
main.cpp  
|---database  
|[Tab]|---create.cpp\
|[Tab]|---read.cpp\
|[Tab]|---update.cpp\  
|[Tab]|---delete.cpp\ 
|[Tab]|---others.cpp\  
|[Tab]+---database.h\  
|---router\  
|[Tab]|---router.cpp\  
|[Tab]|---create.cpp\  
|[Tab]|---read.cpp\  
|[Tab]|---update.cpp\  
|[Tab]|---delete.cpp\  
|[Tab]|---others.cpp\  
|[Tab]+---router.h\  
|---validator\  
|[Tab]|---validator.cpp\  
|[Tab]|---create.cpp\  
|[Tab]|---read.cpp\  
|[Tab]|---update.cpp\  
|[Tab]|---delete.cpp\  
|[Tab]|---others.cpp\  
|[Tab]+---validator.h\  
|---input\  
|[Tab]|---input.cpp\  
|[Tab]|---unix.cpp\  
|[Tab]|---windows.cpp\  
|[Tab]|---others.cpp\  
|[Tab]+---input.h\  
+---task\  
 [Tab]|---task.cpp\  
 [Tab]+---task.h\  

Commands
---

Create option: add <flag1> <input1> <flag2> <input2>...\
    ==flags==                                   ==input constraints==            ==\
    -n, --name                                  0 < length <= 15                 set a task name\  
    -c, --category                              0 < length <= 15                 set a task category\ 
    -C, --completed (default=false)             true/false                       set a completed state of task (optional)\  
    -d, --due                                   YYYY-MM-DD@hr:min:sec            set a due for task (optional)\  
     
Read option: ls <flag> <input>\
    ==flags==                                   ==input constraints==\
    -a, --all                                   name/category/completed/expire            list all task by specific\ 
    -i, --id                                    an integer\
    -n, --name                                  0 < length <= 15\
    -c, --category                              0 < length <= 15\
    -C, --completed                             true/false\
    -e, --expire                                true/false\

Update option: upt <flag1> <input1> <flag2> <input2> // update flag2 by searching flag1\
    ==flags==                                   ==input constraints==\
    -i, --id                                    an inetger\
    -n, --name                                  0 < length <= 15\
    -c, --category                              0 < length <= 15\
    -C, --completed                             true/false\
    -d, --due                                   YYYY-MM-DD@hr:min:sec\

Delete option: rm <flag> <input>
    ==flags==                                   ==input constraints==\
    -i, --id                                    an integer
    -n, --name                                  0 < length <= 15\
    -c, --category                              0 < length <= 15\
    -C, --completed                             true/false\
    -e, --expire                                true/false\