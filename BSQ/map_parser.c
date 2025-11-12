/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:31:12 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/15 20:02:09 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	*resize_buffer(char *line, int old_size, int new_size)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * new_size);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < old_size)
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	return (new_line);
}

static char	*read_line_loop(int fd, char *line, int *i_cap)
{
	char	buffer;
	int		bytes_read;

	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		if (buffer == '\n')
			break ;
		if (i_cap[0] >= i_cap[1] - 1)
		{
			i_cap[1] *= 2;
			line = resize_buffer(line, i_cap[0], i_cap[1]);
			if (!line)
				return (NULL);
		}
		line[i_cap[0]++] = buffer;
		bytes_read = read(fd, &buffer, 1);
	}
	line[i_cap[0]] = '\0';
	if (bytes_read <= 0 && i_cap[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		i_cap[2];

	i_cap[1] = 128;
	line = malloc(sizeof(char) * i_cap[1]);
	if (!line)
		return (NULL);
	i_cap[0] = 0;
	return (read_line_loop(fd, line, i_cap));
}

static int	is_line_valid(char *line, t_map *map)
{
	int	j;

	j = 0;
	if (ft_strlen(line) != map->width)
		return (0);
	while (j < map->width)
	{
		if (line[j] != map->empty && line[j] != map->obstacle)
			return (0);
		j++;
	}
	return (1);
}

int	read_and_validate_grid(int fd, t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * map->height);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = get_next_line(fd);
		if (!map->grid[i])
			return (0);
		if (i == 0)
		{
			map->width = ft_strlen(map->grid[0]);
			if (map->width == 0)
				return (0);
		}
		if (!is_line_valid(map->grid[i], map))
			return (0);
		i++;
	}
	return (1);
}
