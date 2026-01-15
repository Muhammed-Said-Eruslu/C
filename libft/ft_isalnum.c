/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:04:54 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/05 11:09:30 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
// kendisine gönderilen bir karakterin alfabetik harf ve rakam olup olmadıgını kontrol eder