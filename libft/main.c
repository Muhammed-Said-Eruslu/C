#include "libft.h"
#include <stdio.h>

int main()
{
   char *s = ft_itoa(-12345);
   printf("%s\n", s);
   free(s);
   return 0;
}
