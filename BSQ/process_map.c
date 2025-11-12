/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:43:36 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/15 20:02:27 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_and_validate_first_line(char *first_line, t_map *map)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (first_line[i] >= '0' && first_line[i] <= '9')
	{
		height = height * 10 + (first_line[i] - '0');
		i++;
	}
	map->height = height;
	map->empty = first_line[i];
	map->obstacle = first_line[i + 1];
	map->full = first_line[i + 2];
	if (map->height <= 0 || ft_strlen(first_line) != i + 3
		|| map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
	{
		return (0);
	}
	return (1);
}

int	process_map(int fd, t_map *map)
{
	char	*first_line;

	first_line = get_next_line(fd);
	if (!first_line || !parse_and_validate_first_line(first_line, map))
	{
		free(first_line);
		return (0);
	}
	free(first_line);
	if (!read_and_validate_grid(fd, map))
	{
		free_map(map);
		return (0);
	}
	return (1);
}
