/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:49:50 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/15 20:04:05 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
}			t_map;

int		process_map(int fd, t_map *map);
char	*get_next_line(int fd);
int		read_and_validate_grid(int fd, t_map *map);
void	find_biggest_square(t_map *map);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	print_map(t_map *map);
void	free_map(t_map *map);

#endif
