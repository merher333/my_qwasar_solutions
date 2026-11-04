
/*
**
** QWASAR.IO -- my_strlen
**
** @param {char*} param_1
**
** @return {int}
**
*/

int my_strlen(char* param_1) {
    int count = 0;
    while (param_1[count] != '\0') { // Loop until it finds the null terminator
        count ++;
}
return count;
}

