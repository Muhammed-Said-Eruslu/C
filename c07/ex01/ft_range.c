/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:51:52 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/11 16:16:49 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*p;

	i = 0;
	p = (int *)malloc((max - min) * 4);
	if (!p)
		return (NULL);
	while (min < max)
	{
		p[i] = min;
		min++;
		i++;
	}
	return (p);
}

int main()
{
	int *arr;
	arr = ft_range(1,5);
	for (int i = 0; i < 4; i++)
	{
		printf("%d",arr[i]);
	}
	
}