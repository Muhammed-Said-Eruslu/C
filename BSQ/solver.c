/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:24:35 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/15 20:03:36 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	check_new_border(t_map *map, int i, int j, int k)
{
	int	l;

	l = 0;
	while (l <= k)
	{
		if (map->grid[i + l][j + k] == map->obstacle
			|| map->grid[i + k][j + l] == map->obstacle)
		{
			return (1);
		}
		l++;
	}
	return (0);
}

static void	expand_from_point(t_map *map, int *coords, int *sol)
{
	int		k;
	int		obstacle_found;

	k = 1;
	while (coords[0] + k < map->height && coords[1] + k < map->width)
	{
		obstacle_found = check_new_border(map, coords[0], coords[1], k);
		if (obstacle_found)
			break ;
		if (k + 1 > sol[0])
		{
			sol[0] = k + 1;
			sol[1] = coords[0];
			sol[2] = coords[1];
		}
		k++;
	}
}

static void	find_1x1_fallback(t_map *map, int *sol)
{
	int	i;
	int	j;

	if (sol[0] == 0 && map->height > 0 && map->width > 0)
	{
		i = 0;
		while (i < map->height)
		{
			j = 0;
			while (j < map->width)
			{
				if (map->grid[i][j] == map->empty)
				{
					sol[0] = 1;
					sol[1] = i;
					sol[2] = j;
					return ;
				}
				j++;
			}
			i++;
		}
	}
}

static void	draw_solution(t_map *map, int *sol)
{
	int	i;
	int	j;

	if (sol[1] != -1)
	{
		i = 0;
		while (i < sol[0])
		{
			j = 0;
			while (j < sol[0])
			{
				map->grid[sol[1] + i][sol[2] + j] = map->full;
				j++;
			}
			i++;
		}
	}
}

void	find_biggest_square(t_map *map)
{
	int	sol[3];
	int	coords[2];

	sol[0] = 0;
	sol[1] = -1;
	sol[2] = -1;
	coords[0] = 0;
	while (coords[0] <= map->height - 1 - sol[0])
	{
		coords[1] = 0;
		while (coords[1] <= map->width - 1 - sol[0])
		{
			if (map->grid[coords[0]][coords[1]] != map->obstacle)
				expand_from_point(map, coords, sol);
			coords[1]++;
		}
		coords[0]++;
	}
	find_1x1_fallback(map, sol);
	draw_solution(map, sol);
}
