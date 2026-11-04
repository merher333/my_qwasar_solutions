#include <stdio.h>
#include "my_ngram.h"

void my_ngram(int argc, char **argv)
{
    int counts[256] = {0};
    for (int i = 1; i < argc; i++) {
        char *str = argv[i];
        while (*str) {
            if (*str != '"') {
                counts[(unsigned char)*str]++;
            }
            str++;
        }
    }
    for (int c = 0; c < 256; c++) {
        if (counts[c] > 0) {
            printf("%c:%d\n", c, counts[c]);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc > 1) {
        my_ngram(argc, argv);
    }
    return 0;
}

