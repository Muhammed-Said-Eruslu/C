/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:12:03 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/07 14:40:20 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	if (*little == '\0')	  // aranan kelime boşşsa
		return ((char *)big); // yazının basını dondur
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		// little[j] != '\0' aramanın sonundamı kontrolü
		// big ile little bastan sona tarar
		// verilen sınırı aşmamak için
		while (little[j] != '\0' && big[i + j] == little[j] && (i + j) < len)
		{
			j++;
		}
		// bigde aranan kelimenin nerde bulunduğunu döner
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
// ABCDE
// BCD
//  i = 1
//  j = 3
//