/*
**
** QWASAR.IO -- my_recursive_factorial
**
** @param {int} param_1
**
** @return {int}
**
*/

int my_recursive_factorial(int param_1)
{
    if (param_1 < 0)
        return 0;
    if (param_1 == 0)
        return 1;
    return param_1 * my_recursive_factorial(param_1 - 1);
}

