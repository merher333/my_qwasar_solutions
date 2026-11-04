#include <stdio.h>

int main() {
    int my_index = 0;

    my_index++; // Increment by 1
    printf("%d\n", my_index);

    my_index--; // Decrement by 1
    my_index--; // Decrement by 1 again
    printf("%d\n", my_index);

    my_index++; // Increment by 1
    my_index++; // Increment by 1 again
    my_index++; // Increment by 1 again
    printf("%d\n", my_index);

    return 0;
}
