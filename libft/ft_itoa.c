
#include "libft.h"

static int get_len(int n)
{
    int len;
    long nb;

    len = 0;
    nb = n;
    if (nb <= 0)
    {
        len++;
        if (nb < 0)
            nb = -nb;
    }
    while (nb > 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int n)
{
    int len;
    char *str;
    long nb;

    len = get_len(n);
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len--] = '\0';
    nb = n;
    if (nb < 0)
    {
        str[0] = '-';
        nb = -nb;
    }
    if (nb == 0)
        str[0] = '0';
    while (nb > 0)
    {
        str[len] = (nb % 10) + '0';
        nb /= 10;
        len--;
    }
    return (str);
}