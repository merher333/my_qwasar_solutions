#include <stddef.h>

/*
**
** QWASAR.IO -- merge_k_sorted_lists
**
** @param {listnode_array*} param_1
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

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
    int size;
    listnode **array;
} listnode_array;
#endif

listnode* merge_k_sorted_lists(listnode_array* param_1)
{
    listnode* head = NULL;
    listnode* tail = NULL;

    while (1)
    {
        int minIndex = -1;

        // Find the index with the smallest current node
        for (int i = 0; i < param_1->size; i++)
        {
            if (param_1->array[i] != NULL)
            {
                if (minIndex == -1 || param_1->array[i]->val < param_1->array[minIndex]->val)
                {
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1)
            break; // all lists are exhausted

        // Get the smallest node and advance in that list
        listnode* minNode = param_1->array[minIndex];
        param_1->array[minIndex] = param_1->array[minIndex]->next;

        // Add to result list
        if (head == NULL)
        {
            head = minNode;
            tail = minNode;
        }
        else
        {
            tail->next = minNode;
            tail = tail->next;
        }
    }

    return head;
}
