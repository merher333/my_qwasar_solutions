
/*
**
** QWASAR.IO -- my_strcmp
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {int}
**
*/


int my_strcmp(char* param_1, char* param_2) {
    int i = 0;

    while (param_1[i] != '\0' && param_2[i] != '\0') {
        if (param_1[i] != param_2[i]) {
            return param_1[i] - param_2[i]; // Return ASCII difference
        }
        i++;
    }

    return param_1[i] - param_2[i]; // If one string is shorter
}

