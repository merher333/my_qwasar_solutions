/*
**
** QWASAR.IO -- my_strncpy
**
** @param {char*} param_1
** @param {char*} param_2
** @param {int} param_3
**
** @return {char*}
**
*/


#include <stdio.h>

char* my_strncpy(char* param_1, char* param_2, int param_3) {
    int i = 0;

    while (i < param_3 && param_2[i] != '\0') { // Copy each character up to param_3
        param_1[i] = param_2[i];
        i++;
    }

    while (i < param_3) { // Fill remaining space with '\0'
        param_1[i] = '\0';
        i++;
    }
    return param_1;
}



