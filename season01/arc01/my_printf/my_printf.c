#include <stdarg.h> // va_list, va_start, va_arg, va_end
#include <unistd.h> // write

// Prints a single character; returns number of bytes written
int my_putchar(char c) {
    return write(1, &c, 1);
}

// Prints a null-terminated string; returns total characters printed
int my_putstr(const char *str) {
    int count = 0;
    if (!str) {
        // If pointer is NULL, print "(null)"
        str = "(null)";
    }
    while (*str) {
        my_putchar(*str);
        str++;
        count++;
    }
    return count;
}

// Prints an unsigned long integer in a given base; returns total characters printed
int my_putnbr_base(unsigned long num, const char *base) {
    int count = 0;
    unsigned long base_len = 0;

    while (base[base_len] != '\0') {
        base_len++;
    }
    if (num >= base_len) {
        count += my_putnbr_base(num / base_len, base);
    }
    count += my_putchar(base[num % base_len]);
    return count;
}

// Prints a signed long integer in decimal; handles negatives
int my_putnbr_signed(long num) {
    int count = 0;
    if (num < 0) {
        count += my_putchar('-');
        num = -num;
    }
    count += my_putnbr_base((unsigned long)num, "0123456789");
    return count;
}

// Parses format specifiers and prints arguments accordingly
int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int total_chars_printed = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int val = va_arg(args, int);
                total_chars_printed += my_putnbr_signed(val);
            } else if (*format == 'u') {
                unsigned int val = va_arg(args, unsigned int);
                total_chars_printed += my_putnbr_base(val, "0123456789");
            } else if (*format == 'o') {
                unsigned int val = va_arg(args, unsigned int);
                total_chars_printed += my_putnbr_base(val, "01234567");
            } else if (*format == 'x') {
                unsigned int val = va_arg(args, unsigned int);
                total_chars_printed += my_putnbr_base(val, "0123456789ABCDEF");
            } else if (*format == 'c') {
                int val = va_arg(args, int);
                total_chars_printed += my_putchar((char)val);
            } else if (*format == 's') {
                char *val = va_arg(args, char *);
                total_chars_printed += my_putstr(val);
            } else if (*format == 'p') {
                void *ptr = va_arg(args, void *);
                unsigned long addr = (unsigned long)ptr;
                total_chars_printed += my_putstr("0x");
                total_chars_printed += my_putnbr_base(addr, "0123456789abcdef");
            } else {
                total_chars_printed += my_putchar('%');
                total_chars_printed += my_putchar(*format);
            }
        } else {
            total_chars_printed += my_putchar(*format);
        }
        format++;
    }
    va_end(args);
    return total_chars_printed;
}

