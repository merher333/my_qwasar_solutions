/*
**
** QWASAR.IO -- my_strstr
**
** @param {char*} param_1 (haystack)
** @param {char*} param_2 (needle)
**
** @return {char*}
**
*/

#include <stdio.h>

char* my_strstr(char* param_1, char* param_2) {
    if (*param_2 == '\0') {
         return param_1; // If needle is empty, return haystack
    }



    int i = 0;
    while (param_1[i] != '\0') { // Loop through haystack
        int j = 0;
        while (param_2[j] !='\0' && param_1[i + j] == param_2[j]) {
            j++;
        }
        if (param_2[j] == '\0') {
            return &param_1[i]; // Return pointer to the first match
        }
        i++;
    }


    return NULL; // If no match is found
}
