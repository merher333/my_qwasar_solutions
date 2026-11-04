
/*
**
** QWASAR.IO -- my_upcase
**
** @param {char*} param_1
**
** @return {char*}
**
*/

char* my_upcase(char* param_1) {
    int i = 0;
    while (param_1[i] != '\0') {
        if (param_1[i] >= 'a' && param_1[i] <= 'z') {
            param_1[i] -= 32; // Convert lowercase to uppercase
        }
        i++;
    }
    return param_1;
}

