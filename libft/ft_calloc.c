/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:56:09 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/07 15:09:11 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// nmeb kaç tane yer ayırıyım
// size ayırcagım yerlerın her biri kaç byte
void *ft_calloc(size_t nmeb, size_t size)
{
	void *ptr;
	size_t total_size;

	// Taşma kontrolü (SIZE_MAX yerine (size_t)-1)
	if (nmeb != 0 && size > (size_t)-1 / nmeb) // çarpma işlemini yapmadan once sonucun max'i geçip geçmediğin kontrol et eğer geçerse null döndür neden carpma ıle kontrol etmedık eğer carpımda sayıyı asarsa bılgısayar rast gele kucuk sayı verır bu da hatalıdır
											   // nmeb != 0 --> matemtikte bir sayıyı 0'a bölemezsin eğer bu kontolu yapmazsak max / 0 bılgısayarı cokertır
		return (NULL);
	total_size = nmeb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}