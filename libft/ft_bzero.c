/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:44:07 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/05 12:44:56 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	if (!s)
		return;
	ft_memset(s, 0, n);
}
// b (block) zero (sıfır) kelimelerinden gelir.
// Görevi kendisine verilen bellek bloğunu n karakter uzunlukta sıfırla doldurur