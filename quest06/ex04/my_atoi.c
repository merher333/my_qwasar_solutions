/*
**
** QWASAR.IO -- my_atoi
**
** @param {char*} param_1
**
** @return {int}
**
*/

int my_atoi(char* param_1)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    // Check for negative sign
    if (param_1[i] == '-')
    {
        sign = -1;
        i++;
    }

    // Convert each character to integer
    while (param_1[i] >= '0' && param_1[i] <= '9')
    {
        result = result * 10 + (param_1[i] - '0');
        i++;
    }

    return result * sign;
}
