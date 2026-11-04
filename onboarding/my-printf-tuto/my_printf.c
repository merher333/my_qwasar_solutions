#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putstr(char *s)
{
    int i = 0;

    if (!s)
        s = "(null)";
    while (s[i])
        i += write(1, &s[i], 1);
    return i;
}

int my_putnbr(int n)
{
    int count = 0;

    if (n == -2147483648)
        return write(1, "-2147483648", 11);
    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        count += my_putnbr(n / 10);
    count += my_putchar((n % 10) + '0');
    return count;
}

int my_puthex(unsigned long n)
{
    char *hex = "0123456789abcdef";
    int count = 0;

    if (n >= 16)
        count += my_puthex(n / 16);
    count += my_putchar(hex[n % 16]);
    return count;
}

int my_putptr(void *ptr)
{
    int count = 0;

    count += write(1, "0x", 2);
    count += my_puthex((unsigned long)ptr);
    return count;
}

int handle_format(char c, va_list args)
{
    if (c == 'd')
        return my_putnbr(va_arg(args, int));
    else if (c == 'c')
        return my_putchar((char)va_arg(args, int));
    else if (c == 's')
        return my_putstr(va_arg(args, char *));
    else if (c == 'p')
        return my_putptr(va_arg(args, void *));
    else if (c == '%')
        return my_putchar('%');
    return 0;
}

int my_printf(char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += handle_format(format[i], args);
        }
        else
        {
            count += my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return count;
}