#include <stddef.h>

/*
**
** QWASAR.IO -- remove_duplicates_from_sorted_list
**
** @param {listnode*} param_1
**
** @return {listnode*}
**
*/
#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

listnode* remove_duplicates_from_sorted_list(listnode* param_1)
{
    listnode* current = param_1;

    while (current != NULL && current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            listnode* temp = current->next;
            current->next = current->next->next;
            // free(temp); // skip this if not required, Qwasar likely handles memory
        }
        else
        {
            current = current->next;
        }
    }

    return param_1;
}
