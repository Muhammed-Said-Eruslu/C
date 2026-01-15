#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *ptr;
    unsigned int i;

    if (!s || !f)
        return (NULL);
    // ft_strlen size_t döner, cast etmek gerekebilir
    ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    while (s[i])
    {
        ptr[i] = f(i, s[i]);
        i++;
    }
    ptr[i] = '\0'; // Manuel olarak sonlandırmak her zaman daha güvenlidir
    return (ptr);
}