/*
**
** QWASAR.IO -- my_is_sort
**
** @param {integer_array*} param_1
**
** @return {bool}
**
*/

#include <stdio.h>
#include <stdbool.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array {
    int size;
    int* array;
} integer_array;
#endif

bool my_is_sort(integer_array* param_1) {
    if (param_1->size <= 1) return true; // An empty or single-element array is always sorted

    int asc = 1, desc = 1; // Flags for ascending and descending order

    for (int i = 0; i < param_1->size - 1; i++) {
        if (param_1->array[i] > param_1->array[i + 1]) {
            asc = 0; // Not ascending
        }
        if (param_1->array[i] < param_1->array[i + 1]) {
            desc = 0; // Not descending
        }
    }
    return asc || desc; // If either asc or desc is 1, the array is sorted
}

