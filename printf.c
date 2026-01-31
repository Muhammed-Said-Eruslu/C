#include "print.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(const char *str)
{
    int i;

    i = 0;
    if (!str)
        return (ft_putstr("(null)"));
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int n)
{
    int len;

    len = 0;
    if (n == -2147483648)
        return (ft_putstr("-2147483648"));
    if (n < 0)
    {
        len += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        len += ft_putnbr(n / 10);
    len += ft_putchar((n % 10) + '0');
    return (len);
}

static int ft_puthex_long(unsigned long long nb)
{
    char *base;
    int len;

    base = "0123456789abcdef";
    len = 0;
    if (nb >= 16)
        len += ft_puthex_long(nb / 16);
    len += write(1, &base[nb % 16], 1);
    return (len);
}

int ft_puthex(unsigned int n, char format)
{
    int len;
    char *base;

    len = 0;
    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if (n >= 16)
        len += ft_puthex(n / 16, format);
    len += ft_putchar(base[n % 16]);
    return (len);
}

int ft_putptr(unsigned long long ptr)
{
    int len = 0;
    if (ptr == 0)
        return (ft_putstr("(nil)"));
    len += ft_putstr("0x");
    len += ft_puthex_long(ptr);
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int total_len;
    int i;

    va_start(args, format);

    total_len = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                total_len += ft_putchar(va_arg(args, int));
            else if (format[i] == 's')
                total_len += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd' || format[i] == 'i')
                total_len += ft_putnbr(va_arg(args, int));
            else if (format[i] == '%')
                total_len += ft_putchar('%');
            else if (format[i] == 'x' || format[i] == 'X')
                total_len += ft_puthex(va_arg(args, unsigned int), format[i]);
            else if (format[i] == 'p')
                total_len += ft_putptr(va_arg(args, unsigned long));
            else
                total_len += ft_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
}

int main()
{
    int d = 10;
    int *p = &d;
    ft_printf(" %p: %p ", p);
    // ft_printf("%p:  %p", d);
}