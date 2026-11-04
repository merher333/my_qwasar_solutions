# Welcome to Quest09
***

## Task
Implement multiple functions to solve real-world problems using singly linked lists in C.  
These include reversing a list, removing specific nodes, and merging sorted data structures.  
The challenge lies in managing pointers correctly, handling edge cases (like nulls or duplicates), and thinking in terms of memory instead of arrays.

## Description
Each task was approached step-by-step:
- **Reverse Linked List:** Rewired node pointers using a `prev`, `curr`, and `next` technique.
- **Remove N-th Node from End:** Used the two-pointer method to target the right node from the back of the list.
- **Remove Duplicates:** Checked neighbor values in a sorted list and skipped over duplicates.
- **Merge K Sorted Lists:** Compared all current list heads, selected the smallest, and advanced through each list until all were merged.
All functions were written in C with full pointer handling and submitted successfully through Gandalf.

## Installation
No installation required. Each file can be compiled using `gcc`:
gcc -o test test.c your_function_file.c

## Usage
Each function operates on a `listnode*` linked list:
```c
listnode* result = reverse_linked_list(my_list);
listnode* result = remove_nth_node_from_end_of_list(my_list, 2);
listnode* result = remove_duplicates_from_sorted_list(my_list);
listnode* result = merge_k_sorted_lists(&my_list_array);

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
