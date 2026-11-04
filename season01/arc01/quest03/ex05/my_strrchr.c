/*
**
** QWASAR.IO -- my_strrchr
**
** @param {char*} param_1
** @param {char} param_2
**
** @return {char*}
**
*/

#include <stdio.h>

char* my_strrchr(char* param_1, char param_2) {
    char *last_occurance = NULL;
    int i = 0;


    while (param_1[i] != '\0') { // Loop through the string
        if (param_1[i] == param_2) {
            last_occurance = &param_1[i]; // Update the last occurance
        }
        i++;
    }


    return last_occurance; // Return the last occurance (or NULL if not found)
}

