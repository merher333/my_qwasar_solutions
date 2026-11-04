
/*
**
** QWASAR.IO -- my_string_index
**
** @param {char*} param_1
** @param {char} param_2
**
** @return {int}
**
*/

int my_string_index(char* param_1, char param_2) {
    int i = 0;
    while (param_1[i] != '\0') { // Loop through each character
        if (param_1[i] == param_2) {
            return i; // Return index when found
        }
        i++;
    }
    return -1; // Return -1 if not found
}

