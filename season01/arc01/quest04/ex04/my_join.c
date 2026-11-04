#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

char* my_join(string_array* param_1, char* param_2) {
    if (param_1->size == 0) return NULL;

    int total_len = 0, sep_len = 0;
    while (param_2[sep_len]) sep_len++;

    for (int i = 0; i < param_1->size; i++) {
        int len = 0;
        while (param_1->array[i][len]) len++;
        total_len += len;
    }
    
    total_len += (param_1->size - 1) * sep_len + 1;
    
    char* result = (char*)malloc(total_len);
    if (!result) return NULL;

    char* ptr = result;
    for (int i = 0; i < param_1->size; i++) {
        int j = 0;
        while (param_1->array[i][j]) *ptr++ = param_1->array[i][j++];
        
        if (i < param_1->size - 1) {
            for (int k = 0; k < sep_len; k++) *ptr++ = param_2[k];
        }
    }

    *ptr = '\0';
    return result;
}
