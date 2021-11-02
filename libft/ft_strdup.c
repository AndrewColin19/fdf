/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:01:14 by acolin            #+#    #+#             */
/*   Updated: 2021/10/12 17:01:14 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * renvoie un pointeur sur une nouvelle chaîne de caractères 
 * qui est dupliquée depuis s. 
 * La mémoire occupée par cette nouvelle chaîne 
 * est obtenue en appelant malloc(3), 
 * et peut (doit) donc être libérée avec free(3).
 *
 * \param	*s	La chaine à dupliquer
 * \return		renvoie un pointeur sur la chaîne dupliquée, 
 * 				ou NULL s'il n'y avait pas assez de mémoire.
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
