#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void print_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        write(2, "my_cat: Cannot open file ", 25);
        write(2, filename, strlen(filename));
        write(2, "\n", 1);
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        write(2, "Usage: ./my_cat <file1> <file2> ...\n", 36);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        print_file(argv[i]);
    }

    return 0;
}

