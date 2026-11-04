/*
**
** QWASAR.IO -- my_split
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {string_array*}
**
*/

#include <stdlib.h>
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY

typedef struct s_string_array {
    int size;
    char** array;
} string_array;

#endif
int my_strlen(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int count_substrings(char* str, char* sep) {
    if (!str[0] || !sep[0]) return 0;

    int count = 0;
    int i = 0;
    int start = 0;
    int len = my_strlen(str);

    while (i <= len) {
        if (str[i] == sep[0] || str[i] == '\0') {
            if (i > start) {
                count++;
            }
            start = i + 1;
        }
        i++;
    }
    return count;
}

string_array* my_split(char* param_1, char* param_2) {
    string_array* result = malloc(sizeof(*result));
    if (!param_1[0] || !param_2[0]) {
        result->size = 0;
        result->array = NULL;
        return result;
    }

    int num_substrings = count_substrings(param_1, param_2);
    result->size = num_substrings;
    result->array = malloc(sizeof(char*) * num_substrings);

    int i = 0, j = 0, start = 0, substring_index = 0;
    int len = my_strlen(param_1);

    while (i <= len) {
        if (param_1[i] == param_2[0] || param_1[i] == '\0') {
            if (i > start) {
                int substring_len = i - start;
                result->array[substring_index] = malloc(substring_len + 1);
                for (j = 0; j < substring_len; j++) {
                    result->array[substring_index][j] = param_1[start + j];
                }
                result->array[substring_index][j] = '\0';
                substring_index++;
            }
            start = i + 1;
        }
        i++;
    }

    return result;
}
