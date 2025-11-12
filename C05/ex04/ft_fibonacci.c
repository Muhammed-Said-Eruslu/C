/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:59:19 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/07 01:13:05 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	fib0;
	int	fib1;
	int	next;
	int	i;

	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index < 0)
		return (-1);
	fib0 = 0;
	fib1 = 1;
	i = 2;
	while (i <= index)
	{
		next = fib0 + fib1;
		fib0 = fib1;
		fib1 = next;
		i++;
	}
	return (fib1);
}
