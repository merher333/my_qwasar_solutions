#include <stdio.h>

// Function declaration
void detonation_in(int seconds_left) {
    printf("detonation in... %d seconds.\n", seconds_left);
}

int main() {
    int timer = 10;

    while (timer > 0) { // Loop until timer reaches 0
        detonation_in(timer);
        timer--; // Decrement the timer
    }

    return 0;
}
