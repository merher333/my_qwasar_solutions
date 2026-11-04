/*
**
** QWASAR.IO -- hidenp
**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {int}
**
*/

int hidenp(char* param_1, char* param_2)
{
    int i = 0;
    int j = 0;

    if (!param_1[0])
        return 1;

    while (param_2[j]) {
        if (param_1[i] == param_2[j])
            i++;
        if (!param_1[i])
            return 1;
        j++;
    }
    return 0;
}
