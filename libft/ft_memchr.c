/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:03:19 by acolin            #+#    #+#             */
/*   Updated: 2021/10/12 16:03:19 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * examine les n premiers octets de la zone mémoire pointée par s 
 * à la recherche du caractère c. Le premier octet correspondant à c 
 * (interprété comme un unsigned char) arrête l'opération.
 *
 * \param	*s		zone mémoire
 * \param	c		caractère à rechercher
 * \param	n		nombres d'octets
 * \return			renvoient un pointeur sur l'octet correspondant, 
 * 					ou NULL si le caractère n'est pas présent dans la 
 * 					zone de mémoire concernée.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (n--)
	{
		if (*src == (unsigned char)c)
			return (src);
		src++;
	}
	return (NULL);
}
