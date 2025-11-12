/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:25:33 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/15 19:46:31 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->grid)
		return ;
	while (i < map->height)
	{
		write(1, map->grid[i], map->width);
		write(1, "\n", 1);
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->grid)
		return ;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}
