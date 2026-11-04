#include <stdlib.h>
#include <stdio.h>

char* my_spaceship(char* param_1) {
    int x = 0, y = 0;
    char* directions[] = {"up", "right", "down", "left"};
    int dir = 0; // Start facing up

    for (int i = 0; param_1[i]; i++) {
        if (param_1[i] == 'R') {
            dir = (dir + 1) % 4;
        } else if (param_1[i] == 'L') {
            dir = (dir + 3) % 4; // Equivalent to -1 mod 4
        } else if (param_1[i] == 'A') {
            if (dir == 0) y--;    // Move up
            else if (dir == 1) x++; // Move right
            else if (dir == 2) y++; // Move down
            else if (dir == 3) x--; // Move left
        }
    }

    char* result = (char*)malloc(50);
    snprintf(result, 50, "{x: %d, y: %d, direction: '%s'}", x, y, directions[dir]);

    return result;
}
