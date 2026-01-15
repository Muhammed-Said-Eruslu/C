/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:16:53 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/07 20:12:57 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_words(char const *s, char c)
{
    int count;
    int in_word;

    count = 0;
    in_word = 0;
    while (*s)
    {
        if (*s != c && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static char **free_all(char **res, int j)
{
    while (j > 0)
        free(res[--j]);
    free(res);
    return (NULL);
}

static char **fill_words(char const *s, char c, char **res)
{
    int i;
    int j;
    int start;

    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
        {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            res[j++] = ft_substr(s, start, i - start);
            if (!res[j - 1])
                return (free_all(res, j - 1));
        }
    }
    res[j] = NULL;
    return (res);
}

char **ft_split(char const *s, char c)
{
    char **res;

    if (!s)
        return (NULL);
    res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!res)
        return (NULL);
    return (fill_words(s, c, res));
}