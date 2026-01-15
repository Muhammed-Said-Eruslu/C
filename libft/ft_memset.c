/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mueruslu <mueruslu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:22:55 by mueruslu          #+#    #+#             */
/*   Updated: 2026/01/07 15:01:46 by mueruslu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void b olmasının sebebi her şeyi kopyalıyabilir
//
// len kaç byte boyunca bu işlemi yapacağız
void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr; // unsigned char'a cast etmemizin sebebi void * üzerinden işlem yapılmaz bilgisayar her kutu kaç byte bilmiyorum der bellekteki en küçük birim 1 byte'dır
	// c dilinde 1 byte'a karşılık gelen tür unsigned char'dır
	// unsigned olmasının sebebi normal char -128 ile 127 arası alır ama memsette saf veri ile ugrasırız unsigned kullanarak 0 255 arasındakı tum bıt kombınasyonlarını hatasız sekılde garantı altına alırız
	size_t i;
	if (!b)
		return (NULL);
	ptr = (unsigned char *)b; // b sadece bir adrest tutar ıcındekı verıyı bılmez ondan dolayı cast ediyoruz
	i = 0;
	while (i < len) // i gelen len kadar ilerliyor
	{
		ptr[i] = (unsigned char)c; // hafızadakı her hücre 8 bit (1 byte) genişliğindedir. Ama parametreden gelen c değişkeni 32 bit (4 byte) genişliğindedir. Eğer (unsigned char) yazmazsak 4 kat büyük veriyi 1 katlık yere zorla sıgdırmaya calısıyormus gibi oluruz
		i++;
	}
	return (b); // b yi dönmemizin sebebi memset standartlarına göre başlangıç adresini dönmemiz gerekir
}

// void * int char bellekteki görünümü
// void: Hiç bir şey görmez, sadece başlangıç noktasını bilir.
// int: Her bakışta 4 byte görür
// unsigned char: Her bakışta 1 byte görür.
// ft_memset her kutuyu boya dediği için bize en küçük birim olan 1 byte'lık gözluk (yani unsigned char) lazım.

// size_t  nedir ve neden kullandık
// Negatif boyut olamaz: bir alanın uzunluğu (len) asla -5 byte olamaz int tipi negatif değerler alabilir (signed), ancak size_t sadece pozitif (unsigned) temsil eder.

// Kapasite farkı:
// Günümüz 64-bit bilgisayarlarında int genellikle hala 32-bit (yaklaşık 2 milyar sınırında) kalır.
// ancak size_t 64-bit bir tam sayıdır.
// Eğer 4GB'lık devasa bir bellık bloğunu memset ile doldurmak istersek 32-bit int bu boyutu taşıyamaz size_t ise o sistemin adresleyebileceği tüm belleği kapsayacak kadar büyük tasarlanmıştır.

// Portatiflik (Taşınabilirlik):
// Kodunu yarın bir gün 32-bit bir işlemciden 64-bit bir işlemciye taşırsak size_t kendini otomatik olarak o sisteme göre ayarlar

// size_t formatını printf ile yazdırmak istersek %d ile %zu format belirleyicisini kullanmak gerekir.