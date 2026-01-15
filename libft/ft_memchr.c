/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:57:27 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/07 14:10:39 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	size_t i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i)); // ptr'ın başlangıç adresine i eklediğimiz zaman aradığımız konumu buluruz
										// diyelim ptr başlangıcı 100 i 2 oldu 102 de bulmuş olduk
		i++;
	}
	return (0);
}