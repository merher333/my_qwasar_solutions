/*
**
** QWASAR.IO -- my_first_struct
**
** @param {integer_array*} param_1
**
** @return {void}
**
*/

#include <stdio.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array {
    int size;
    int* array;
} integer_array;
#endif

void my_first_struct(integer_array* param_1) {
    printf("%d\n", param_1->size); // Print size of array

    for (int i = 0; i < param_1->size; i++) {
        printf("%d\n", param_1->array[i]); // Print each element
    }
}


