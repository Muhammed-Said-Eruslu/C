/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:47:39 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/11 12:52:40 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_print_param(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	ft_sort_param(int argc, char **argv, int j)
{
	int	flag;

	flag = 1; // flag bir olamsının sebebi swap yapılmıs sıralama devam edıyor 
	// 0 olursa sıralama tamam demek
	if (argc > 1)
	{
		while (flag)
		{
			j = 1;
			flag = 0;
			while (argv[j + 1]) // j + 1 var olup olmadıgı kontrolu
			{
				if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				{
					ft_swap(&argv[j], &argv[j + 1]);
					flag = 1;
				}
				j++;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	int	j;

	j = 0;
	ft_sort_param(argc, argv, j);
	ft_print_param(argv);
}
