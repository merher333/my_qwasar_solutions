
/*
**
** QWASAR.IO -- my_swap
**
** @param {int*} param_1
** @param {int*} param_2
**
** @return {void}
**
*/

void my_swap(int* param_1, int* param_2) {
    int temp = *param_1;  // Store the value of param_1
    *param_1 = *param_2;  // Assign param_2 value to param_1
    *param_2 = temp;      // Assign the stored value to param_2
}

