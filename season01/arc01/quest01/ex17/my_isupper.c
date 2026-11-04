/*
** QWASAR.IO -- my_isupper
**
** @param {char} param_1
**
** @return {int}
**
*/

// Function prototype
int my_isupper(char param_1);

// Function definition
int my_isupper(char param_1) {
    if (param_1 >= 'A' && param_1 <= 'Z') {
        return 1; // Return 1 for uppercase letters
    }
    return 0; // Return 0 otherwise
}

