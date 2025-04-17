Commands
---

### Create
#### `add <flag1> <value1> <flag2> <value2>...`<br>
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-n, --name`|set the task name|0 < length <= 15|
|`-c, --category`|set the task category|0 < length <= 15|
|`-C, --completed`|set task as completed status**(optional)**|`true/false` (default=`false`)|
|`-d, --due`|set a due for the task **(optional)**|`YYYY-MM-DD@hr:min:sec`|
     
### Read
#### `ls <flag> <value>`<br>
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-a, --all`|show all tasks by selected criteria|`name/category/completed/expire`|
|`-i, --id`|show task by seleted id|an integer|
|`-n, --name`|show task matching the given name|0 < length <= 15|
|`-c, --category`|show all tasks matching the given category|0 < length <= 15|
|`-C, --completed`|show all tasks with the given completed status|`true/fasle`|
|`-e, --expire`|show all tasks with the given expire status|`true/false`|

### Update
#### `upt <search-flag> <search-value> <update-flag> <new-value>`<br>
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-i, --id`|**search** by id|an inetger|
|`-n, --name`|**search/update** the task name|0 < length <= 15|
|`-c, --category`|**update** the task category|0 < length <= 15|
|`-C, --completed`|**update** the task completed status|`true/false`|
|`-d, --due`|**update** the due of the task|`YYYY-MM-DD@hr:min:sec`|

### Delete
#### `rm <flag> <value>`<br>
|🚩**Flags**|↪️**Description**|⚠️**Input Constraints**|
|:----------|:---------------|:---------------------|
|`-i, --id`|delete the task by selected id|an integer|
|`-n, --name`|delete the task matching the given name|0 < length <= 15|
|`-c, --category`|delete all the tasks matching the given category|0 < length <= 15|
|`-C, --completed`|delete all the tasks matching the given completed status|`true/false`|
|`-e, --expire`|delete all the tasks matching the given expire status|`true/false`|
