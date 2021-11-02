/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:11:25 by acolin            #+#    #+#             */
/*   Updated: 2021/10/07 16:11:25 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * remplit les n premiers octets de la zone mémoire pointée par s avec 
 * l'octet c.
 *
 * \param	*s	pointeur sur la zone mémoire
 * \param	c	octet de remplissage
 * \param	n	nombres d'octets
 * \return		renvoie un pointeur sur la zone mémoire s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *) s;
	while (n)
	{
		*a = (unsigned char) c;
		a++;
		n--;
	}
	return (s);
}
