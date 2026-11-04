#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void generate_code(char *code) {
    int used[9] = {0}; 
    int i = 0;

    srand(time(NULL)); 

    while (i < 4) {
        int digit = rand() % 9 + '0'; 
        if (!used[digit - '0']) { 
            code[i] = digit;
            used[digit - '0'] = 1;
            i++;
        }
    }
    code[4] = '\0'; 
}

int is_valid_guess(char *guess) {
    if (strlen(guess) != 4) return 0;

    int used_digits[9] = {0}; 
    for (int i = 0; i < 4; i++) {
        if (guess[i] < '0' || guess[i] > '9') return 0;
        if (used_digits[guess[i] - '0']) return 0;
        used_digits[guess[i] - '0'] = 1;
    }
    return 1;
}

void compare_guess(const char *secret, const char *guess, int *well_placed, int *misplaced) {
    *well_placed = 0;
    *misplaced = 0;

    int used[4] = {0};

    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            (*well_placed)++;
            used[i] = 1;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (guess[i] != secret[i]) {
            for (int j = 0; j < 4; j++) {
                if (!used[j] && guess[i] == secret[j]) { 
                    (*misplaced)++;
                    used[j] = 1;
                    break;
                }
            }
        }
    }
}

int read_user_input(char *buffer, int size) {
    int i = 0;
    char c;
    while (i < size - 1) {
        int bytes_read = read(0, &c, 1);
        if (bytes_read <= 0 || c == '\n') {
            break;
        }
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    return i;
}

int main(int argc, char *argv[]) {
    char secret_code[5] = "";
    int attempts = 10;
    char guess[10];

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            strncpy(secret_code, argv[i + 1], 4);
            secret_code[4] = '\0';
        }
        if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
            attempts = atoi(argv[i + 1]);
        }
    }

    if (secret_code[0] == '\0') {
        generate_code(secret_code);
    }

    printf("Will you find the secret code?\n");
    printf("You have %d attempts.\n", attempts);

    for (int round = 0; round < attempts; round++) {
        printf("Please enter a valid guess\n");
        printf("Round %d\n> ", round + 1);

        int input_length = read_user_input(guess, sizeof(guess));

        if (input_length == 0) {
            printf("\nGame exited.\n");
            return 0;
        }

        if (!is_valid_guess(guess)) {
            printf("Wrong input!\n");
            continue;
        }

        int well_placed = 0, misplaced = 0;
        compare_guess(secret_code, guess, &well_placed, &misplaced);

        printf("Well placed pieces: %d\n", well_placed);
        printf("Misplaced pieces: %d\n", misplaced);

        if (well_placed == 4) {
            printf("Congratz! You did it!\n");
            return 0;
        }
    }

    printf("Game over! The secret code was: %s\n", secret_code);
    return 0;
}
