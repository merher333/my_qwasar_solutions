#include <stdio.h>
#include <stdlib.h>

void my_square(int x, int y) {
    // If x or y <= 0, do nothing
    if (x <= 0 || y <= 0)
        return;

    // Print top line
    if (y >= 1) {
        printf("o");
        for (int i = 0; i < x - 2; i++)
            printf("-");
        if (x > 1)
            printf("o");
        printf("\n");
    }

    // Print middle lines (if y > 2, we have lines in between top and bottom)
    for (int j = 0; j < y - 2; j++) {
        printf("|");
        for (int i = 0; i < x - 2; i++)
            printf(" ");
        if (x > 1)
            printf("|");
        printf("\n");
    }

    // Print bottom line (only if y > 1)
    if (y > 1) {
        printf("o");
        for (int i = 0; i < x - 2; i++)
            printf("-");
        if (x > 1)
            printf("o");
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        // Not enough arguments
        return 0;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    my_square(x, y);
    return 0;
}
