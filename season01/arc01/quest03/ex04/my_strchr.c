/*
**
** QWASAR.IO -- my_strchr
**
** @param {char*} param_1
** @param {char} param_2
**
** @return {char*}
**
*/

#include <stdio.h>

char* my_strchr(char* param_1, char param_2) {
    int i = 0;


    while (param_1[i] != '\0') { // Loop through the string
        if (param_1[i] == param_2) {
            return &param_1[i]; // Return pointer to the first match
        }
        i++;
    }


    return NULL; // If not found, return NULL
}

