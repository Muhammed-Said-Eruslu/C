/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:10:46 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/07 01:13:58 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 0)
		return (2);
	else if (nb == 1)
		return (2);
	i = 2;
	while (i < nb)
	{
		if (nb % i != 0)
			i++;
		else
			return (ft_find_next_prime(nb + 1));
	}
	return (nb);
}
