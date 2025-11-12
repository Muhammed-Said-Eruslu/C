/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:57:44 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/15 17:43:40 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_and_print(int fd)
{
	t_map	map;

	map.grid = NULL;
	if (process_map(fd, &map))
	{
		find_biggest_square(&map);
		print_map(&map);
		free_map(&map);
	}
	else
	{
		ft_putstr("map error\n");
	}
}

static void	process_arguments(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("map error\n");
		}
		else
		{
			solve_and_print(fd);
			close(fd);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		solve_and_print(0);
	}
	else
	{
		process_arguments(argc, argv);
	}
	return (0);
}
