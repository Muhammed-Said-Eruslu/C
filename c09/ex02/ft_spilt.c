/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spilt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:23:02 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/13 16:40:13 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		int	j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		
		if (charset[j])
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

char **ft_split(char *str, char *charset)
{

}