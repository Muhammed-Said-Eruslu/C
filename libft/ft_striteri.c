#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    if (!s || !f)
        return;
    i = 0;
    while (s[i] != '\0')
    {
        // f fonksiyonuna o anki indeksi (i)
        // ve karakterin adresini (&s[i]) gönderiyoruz.
        f(i, &s[i]);
        i++;
    }
}