/*
**
** QWASAR.IO -- my_iterative_factorial
**
** @param {int} param_1
**
** @return {int}
**
*/

int my_iterative_factorial(int param_1)
{
    int result = 1;
    int i;

    if (param_1 < 0)
        return 0;

    for (i = 1; i <= param_1; i++)
        result *= i;

    return result;
}
