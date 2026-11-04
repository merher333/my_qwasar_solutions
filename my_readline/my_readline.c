#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int  READLINE_READ_SIZE = 512;
char *storage = NULL;

void init_my_readline(void)
{
    if (storage)
    {
        free(storage);
        storage = NULL;
    }
}

char *my_readline(int fd)
{
    char buffer[READLINE_READ_SIZE + 1];
    char *newline;
    char *tmp;
    ssize_t bytes;

    // read until we find a newline in storage
    while ((newline = storage ? strchr(storage, '\n') : NULL) == NULL)
    {
        bytes = read(fd, buffer, READLINE_READ_SIZE);
        if (bytes <= 0)
            break;
        buffer[bytes] = '\0';

        if (!storage)
        {
            storage = malloc(bytes + 1);
            strcpy(storage, buffer);
        }
        else
        {
            tmp = malloc(strlen(storage) + bytes + 1);
            strcpy(tmp, storage);
            strcat(tmp, buffer);
            free(storage);
            storage = tmp;
        }
    }

    if (storage && *storage)
    {
        if (newline)
        {
            size_t len = newline - storage;
            char *line = malloc(len + 1);
            memcpy(line, storage, len);
            line[len] = '\0';

            tmp = strdup(newline + 1);
            free(storage);
            storage = tmp;

            return line;
        }
        else
        {
            char *line = strdup(storage);
            free(storage);
            storage = NULL;
            return line;
        }
    }

    return NULL;
}
