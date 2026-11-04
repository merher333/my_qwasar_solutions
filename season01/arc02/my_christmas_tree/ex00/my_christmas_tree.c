#include <stdio.h>
#include <stdlib.h>

void print_spaces(int n) {
    while (n-- > 0) putchar(' ');
}

void print_stars(int n) {
    for (int i = 0; i < n; i++)
        putchar('*');
    putchar('\n');
}

int get_total_width(int size) {
    int stars = 1, width = 0;
    for (int block = 0; block < size; block++) {
        int lines = block + 4;
        for (int i = 0; i < lines; i++) {
            if (stars > width) width = stars;
            stars += 2;
        }
        int sub = 4 + 2 * (block / 2);
        stars -= sub;
    }
    return width;
}

void print_tree(int size) {
    int stars = 1;
    int max_width = get_total_width(size);

    for (int block = 0; block < size; block++) {
        int lines = block + 4;
        for (int i = 0; i < lines; i++) {
            int spaces = (max_width - stars) / 2;
            print_spaces(spaces);
            print_stars(stars);
            stars += 2;
        }
        int sub = 4 + 2 * (block / 2);
        stars -= sub;
    }

    int trunk_w = size;
    int trunk_sp = (max_width - trunk_w + 1) / 2;
    for (int i = 0; i < size; i++) {
        print_spaces(trunk_sp);
        for (int j = 0; j < trunk_w; j++)
            putchar('|');
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int size = atoi(argv[1]);
    if (size <= 0) return 0;
    print_tree(size);
    return 0;
}
