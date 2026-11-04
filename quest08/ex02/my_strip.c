#include <stdlib.h>

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

char* my_strip(char* param_1)
{
    int i = 0, j = 0, len = 0, in_word = 0;
    
    // Count length
    while (param_1[len]) len++;

    char* result = malloc(len + 1); // max possible size
    if (!result) return NULL;

    // Skip leading spaces
    while (is_space(param_1[i])) i++;

    while (param_1[i]) {
        if (is_space(param_1[i])) {
            if (in_word) {
                result[j++] = ' ';
                in_word = 0;
            }
        } else {
            result[j++] = param_1[i];
            in_word = 1;
        }
        i++;
    }

    // Remove trailing space
    if (j > 0 && result[j - 1] == ' ')
        j--;

    result[j] = '\0';
    return result;
}
