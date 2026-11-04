#include <stdio.h>
#include "my_printf.h"

int main(void) {
    my_printf("Hello World!\n");
    my_printf("Testing decimal %%d: %d\n", 42);
    my_printf("Testing unsigned decimal %%u: %u\n", 42);
    my_printf("Testing octal %%o: %o\n", 42);
    my_printf("Testing hex %%x: %x\n", 255);
    my_printf("Testing char %%c: %c\n", 'A');
    my_printf("Testing string %%s: %s\n", "Hello Qwasar!");
    my_printf("Testing pointer %%p: %p\n", main);

    return 0;
}
