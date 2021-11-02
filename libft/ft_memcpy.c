/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:03:31 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 11:50:04 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * copie n octets depuis la zone mémoire src vers la zone mémoire dest. 
 * Les deux zones ne doivent pas se chevaucher. Si c'est le cas, 
 * utilisez plutôt ft_memmove(3).
 *
 * \param	*dst	pointeur sur la zone mémoire de déstination
 * \param	*src	pointeur sur la zone mémoire source
 * \param	n		nombres d'octets à copier
 * \return			renvoie un pointeur sur dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;

	s = (char *)dst;
	if (!dst && !src)
		return (dst);
	while (n)
	{
		*(char *)s = *(char *)src;
		s++;
		src++;
		n--;
	}
	return (dst);
}
