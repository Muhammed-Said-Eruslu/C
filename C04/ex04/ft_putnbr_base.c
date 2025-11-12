/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:38:24 by mueruslu          #+#    #+#             */
/*   Updated: 2025/10/04 21:06:42 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strlen(base);
	if (len < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	box[32];
	long	n;
	int		size;
	int		i;

	if (!ft_check_base(base))
		return ;
	size = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	while (n > 0)
	{
		box[i] = base[n % size];
		n = n / size;
		i++;
	}
	while (--i >= 0)
		ft_putchar(box[i]);
}

int main()
{
	int n = 18903253;
	char *hex = "0123456789abcdef";
	char *oct = "012345678";
	char *dec = "0123456789";
	char *bin = "10";
	write(1, "Hex: ",6);
	ft_putnbr_base(n,hex);
	ft_putchar('\n');
	write(1, "oct: ",6);
	ft_putnbr_base(n,oct);
	ft_putchar('\n');
	write(1, "dec: ", 6);
	ft_putnbr_base(n,dec);
	ft_putchar('\n');
	write(1, "bin: ",6);
	ft_putnbr_base(n,bin);
}