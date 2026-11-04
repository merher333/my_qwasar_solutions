#include <stddef.h>

/*
**
** QWASAR.IO -- remove_nth_node_from_end_of_list
**
** @param {listnode*} param_1
** @param {int} param_2
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

listnode* remove_nth_node_from_end_of_list(listnode* param_1, int param_2)
{
    listnode dummy;
    dummy.next = param_1;

    listnode *first = &dummy;
    listnode *second = &dummy;

    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= param_2; i++)
        first = first->next;

    // Move both until first hits end
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // Remove the target node
    listnode *temp = second->next;
    second->next = second->next->next;

    return dummy.next;
}
