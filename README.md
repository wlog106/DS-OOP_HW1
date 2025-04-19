Commands
---
### Create
#### `add <flag1> <value1> <flag2> <value2>...`
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-n, --name`|set the task name|*Length: 1-15*|
|`-c, --category`|set the task category|*Length: 1-15*|
|`-C, --completed`|set task as completed status **(optional)**|*Options:* `true / false` (default=`false`)|
|`-d, --due`|set a due for the task **(optional)**|*Format:* `YYYY-MM-DD@hr:min:sec`|
     
### Read
#### `ls <flag> <value>`
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-a, --all`|show tasks by selected criteria|*Options:* `name / category / completed / expire`|
|`-i, --id`|show task by id|*Type: Integer*|
|`-n, --name`|show task by name|*Length: 1-15*|
|`-c, --category`|show tasks by category|*Length: 1-15*|
|`-C, --completed`|filter by completed status|*Options:* `true / fasle`|
|`-e, --expire`|filter by expire status|*Options:* `true / false`|

### Update
#### `upt <search-flag> <search-value> <update-flag> <new-value>`
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-i, --id`|**search** by id|*Type: Integer*|
|`-n, --name`|**search/update** the task name|*Length: 1-15*|
|`-c, --category`|**update** the task category|*Length: 1-15*|
|`-C, --completed`|**update** the task completed status|*Options:* `true / false`|
|`-d, --due`|**update** the due of the task|*Format:* `YYYY-MM-DD@hr:min:sec`|

### Delete
#### `rm <flag> <value>`
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-i, --id`|delete the task by selected id|*Type: Integer*|
|`-n, --name`|delete the task matching the given name|*Length: 1-15*|
|`-c, --category`|delete tasks matching the given category|*Length: 1-15*|
|`-C, --completed`|delete tasks matching the given completed status|*Options:* `true / false`|
|`-e, --expire`|delete tasks matching the given expire status|*Options:* `true / false`|

### Others
#### `help` , `exit/quit`
- Use `help` to show HELP MENU
- Use `exit/quit` to terminate the TodoList

Main Logic
---
```mermaid
graph LR
A(main) --valid command--> B(router)
B --choose different entries--> C(database)
D(validator) --validity--> A
E(input) --user input--> A
A --input command--> D
```

Some Features 
---
*Note: All features should work well on both UNIX and windows system*  
*Tested on Fedora 41 (kernel 6.13.11), windows 11*
- Navigate command history using the `Up` and `Down` arrow keys  
- Move the cursor using the `Left` and `Right` arrow keys
- Data can be `Save` and `Load` from .txt file
- Solid user input `validator`

Known issue
---
- **The issue isn’t been solved so please make sure the width of your terminal is bigger than 110 spaces.**<br><br>
Since every time you input a char, `render()` is called.<br>
It would using 110 spaces to overwrite what ever is rendered last time *--110 is close to maximum possible input length.* However, if your terminal’s width is less than 110 spaces, every time when `render()` is called, the result would look like a `\n` is output.<br>

Thanks
---
- *My friends' and ChatGPT's inspiring ideas*
- *My friends' windows laptop*
- *TAs' Q&A forum*




