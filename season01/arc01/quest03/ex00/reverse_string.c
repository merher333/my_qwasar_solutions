
/*
**
** QWASAR.IO -- reverse_string
**
** @param {char*} param_1
**
** @return {char*}
**
*/

char* reverse_string(char* param_1) {
    int left = 0;
    int right = strlen(param_1) -1;
    char temp;

    while (left < right) {
       temp = param_1[left];
       param_1[left] = param_1[right];
        param_1[right] = temp;
        left++;
        right--;
    }

    return param_1;
}

