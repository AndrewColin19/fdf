/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:28 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 16:42:17 by acolin           ###   ########.fr       */
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
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (*s == '\0' && (unsigned char) c == '\0')
		return ((char *) s);
	return (0);
}
