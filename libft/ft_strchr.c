/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:06:06 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/05 20:12:04 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return (char *)s;
		s++;
	}
	if (ch == '\0')
		return (char *)s;
	return NULL;
}
