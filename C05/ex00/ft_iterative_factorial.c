/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:52:25 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/07 01:10:45 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	sum;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	i = 1;
	sum = 1;
	while (i <= nb)
	{
		sum *= i;
		i++;
	}
	return (sum);
}
