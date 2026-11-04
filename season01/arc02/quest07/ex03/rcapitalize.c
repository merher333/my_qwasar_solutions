
#include <stdlib.h>

char* rcapitalize(char* param_1)
{
    int i;
    int len;

    // If string is empty or NULL, return as is
    if (!param_1 || param_1[0] == '\0')
        return param_1;

    // Get string length
    len = 0;
    while (param_1[len])
        len++;

    i = 0;
    while (i < len)
    {
        // Convert all characters to lowercase initially
        if (param_1[i] >= 'A' && param_1[i] <= 'Z')
            param_1[i] += 32;
        i++;
    }

    i = 0;
    while (i < len)
    {
        // Skip spaces/tabs
        while (i < len && (param_1[i] == ' ' || param_1[i] == '\t'))
            i++;

        if (i >= len)
            break;

        // Find the end of the current word
        int start = i;
        while (i < len && param_1[i] != ' ' && param_1[i] != '\t')
            i++;

        // Capitalize the last letter of the word
        if (i - 1 >= start && param_1[i - 1] >= 'a' && param_1[i - 1] <= 'z')
            param_1[i - 1] -= 32;
    }

    return param_1;
}
