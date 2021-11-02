/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:19:12 by acolin            #+#    #+#             */
/*   Updated: 2021/10/12 16:19:12 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * compare les n premiers octets des zones mémoire s1 et s2. 
 * Elle renvoie un entier inférieur, égal, ou supérieur à zéro, 
 * si s1 est respectivement inférieure, égale ou supérieur à s2.
 *
 * \param	*s1		zone mémoire 1
 * \param	*s2		zone mémoire 2
 * \param	n		nombres d'octets
 * \return			renvoie un entier négatif, nul ou positif si les n 
 * 					premiers octets de s1 sont respectivement inférieurs, 
 * 					égaux ou supérieurs aux n premiers octets de s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
