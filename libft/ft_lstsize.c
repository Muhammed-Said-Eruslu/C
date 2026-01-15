

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    size_t count;

    while (lst)
    {
        lst = lst->next;
        count++;
    }
    return (count);
}