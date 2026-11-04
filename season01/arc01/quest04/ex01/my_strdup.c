#include <stdlib.h>

char* my_strdup(char* param_1) {
    int len = 0;
    while (param_1[len]) len++;

    char* copy = (char*)malloc((len + 1) * sizeof(char));
    if (!copy) return NULL;

    for (int i = 0; i <= len; i++) {
        copy[i] = param_1[i];
    }

    return copy;
}
