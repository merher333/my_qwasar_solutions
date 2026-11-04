#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

integer_array* my_count_on_it(string_array* param_1) {
    integer_array* result = (integer_array*)malloc(sizeof(integer_array));
    if (!result) return NULL;

    result->size = param_1->size;
    result->array = (int*)malloc(result->size * sizeof(int));
    if (!result->array) return NULL;

    for (int i = 0; i < result->size; i++) {
        int len = 0;
        while (param_1->array[i][len]) len++;
        result->array[i] = len;
    }

    return result;
}
