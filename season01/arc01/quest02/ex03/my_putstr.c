
/*
**
** QWASAR.IO -- my_putstr
**
** @param {char*} param_1
**
** @return {void}
**
*/

void my_putstr(char* param_1) {
    int i = 0;
    while (param_1[i] != '\0') { // Loop through each character
        putchar(param_1[i]);     // Print each character
        i++;
    }
}
