/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:32:24 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/11 19:35:47 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strcpy_pos(char *dest, char *src, int pos)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[pos] = src[i];
		pos++;
		i++;
	}
	return (pos);
}

char	*ft_check(int size)
{
	char	*result;

	if (size == 0)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_calculate_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;
	int	sep_len;

	len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += sep_len;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;
	int		pos;

	if (size == 0)
		return (ft_check(size));
	len = ft_calculate_len(size, strs, sep);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	pos = 0;
	i = -1;
	while (++i < size)
	{
		pos = ft_strcpy_pos(result, strs[i], pos);
		if (i < size - 1)
			pos = ft_strcpy_pos(result, sep, pos);
	}
	result[pos] = '\0';
	return (result);
}

int	main(void)
{
	char	*words[] = {"Hello", "World", "42"};
	char	*sep;
	char	*result;

	sep = ", ";
	result = ft_strjoin(3, words, sep);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
}
