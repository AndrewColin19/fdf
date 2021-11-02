/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:59:02 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 16:42:39 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * renvoie un pointeur sur la première occurrence du caractère c 
 * dans la chaîne s.
 *
 * \param	*s	chaine de caractère
 * \param	c	caractère à trouver
 * \return		renvoient un pointeur sur le caractère correspondant, 
 * 				ou NULL si le caractère n'a pas été trouvé.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	r = 0;
	while (*s)
	{
		if (*s == (unsigned char) c)
			r = ((char *) s);
		s++;
	}
	if (*s == '\0' && (unsigned char) c == '\0')
		return ((char *) s);
	return (r);
}
