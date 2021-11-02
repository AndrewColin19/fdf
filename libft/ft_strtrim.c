/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:33:43 by acolin            #+#    #+#             */
/*   Updated: 2021/10/12 18:33:43 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Alloue (avec malloc(3)) et retourne une copie de
 * la chaine ’s1’, sans les caractères spécifiés
 * dans ’set’ au début et à la fin de la chaine de
 * caractères.
 *
 * \param	*s1		La chaine de caractères à trimmer.
 * \param	*set	Le set de reference de caractères à trimmer.
 * \return			La chaine de caractères trimmée. NULL si
 * 					l’allocation échoue.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen(s1);
	while (size_s && ft_strchr(set, s1[size_s - 1]))
		size_s--;
	newstring = ft_substr((char *)s1, 0, size_s);
	return (newstring);
}
