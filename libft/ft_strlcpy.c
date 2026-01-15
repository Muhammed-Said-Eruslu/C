/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:57:02 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/05 17:04:19 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size < src_size + 1)
	{
		size--;
		while (size--)
			*dst++ = *src++;
		*dst = '\0';
		return (src_size);
	}
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_size);
}
