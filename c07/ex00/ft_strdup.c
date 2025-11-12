/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:48:20 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/11 16:16:35 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
	
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(str);
	dest = (char *)malloc(len);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

int main()
{
	char str[] = "said";
	char *dest;
	dest = ft_strdup(str);
	printf("%s",dest);
}