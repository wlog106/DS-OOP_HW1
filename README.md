Tree  
---
main.cpp  
|---database  
|   |---create.cpp  
|   |---read.cpp  
|   |---update.cpp  
|   |---delete.cpp  
|   |---others.cpp  
|   +---database.h  
|---router  
|   |---router.cpp  
|   |---create.cpp  
|   |---read.cpp  
|   |---update.cpp  
|   |---delete.cpp  
|   |---others.cpp  
|   +---router.h  
|---validator  
|   |---validator.cpp  
|   |---create.cpp  
|   |---read.cpp  
|   |---update.cpp  
|   |---delete.cpp  
|   |---others.cpp  
|   +---validator.h  
|---input  
|   |---input.cpp  
|   |---unix.cpp  
|   |---windows.cpp  
|   |---others.cpp  
|   +---input.h  
+---task  
    |---task.cpp  
    +---task.h  

Commands
---
Create option: add
    -n, --name <string>                                 set a task name  
    -c, --category <string>                             set a task category 
    -C, --completed <?bool>(defult=false)               set a completed state of task  
    -d, --due <?date>(format: YYYY-MM-DD@hr:min:sec)    set a due for task  
     
Read option: ls
    -a, --all <string>   list all task by specific order
    -i, --id  <>
    -n, --name
    -c, --category
    -C, --completed
    -e, --expire