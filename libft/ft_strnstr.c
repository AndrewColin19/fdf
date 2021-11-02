/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:39:09 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 12:23:07 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * localise la première occurrence de la chaîne s2 
 * dans la chaîne s1 .
 *
 * \param	*s1		la chaine où rechercher
 * \param	*s2		la chaine à trouver
 * \param	len		le nombre maximum de caractères à rechercher
 * \return			Si s2 est une chaîne vide, s1 est renvoyé, 
 * 					si s2 n'apparaît nulle part dans s1 ,
 * 					NULL est renvoyé ; sinon un pointeur vers le premier 
 * 					caractère du premier
 * 					l'occurrence de s2 est renvoyée.
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	pos;
	size_t	i;

	if (!*s2)
		return ((char *)s1);
	pos = 0;
	while (s1[pos] != '\0' && pos < len)
	{
		if (s1[pos] == s2[0])
		{
			i = 1;
			while (s2[i] != '\0' && (pos + i) < len
				&& s1[pos + i] == s2[i])
				i++;
			if (s2[i] == '\0')
				return ((char *)s1 + pos);
		}
		pos++;
	}
	return (0);
}
