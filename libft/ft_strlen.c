/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:48:14 by acolin            #+#    #+#             */
/*   Updated: 2021/11/04 11:18:08 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * calcule la longueur de la chaîne de caractères s, 
 * sans compter l'octet nul « \0 » final.
 *
 * \param	*s		pointeur sur la chaine à compter 
 * \return			renvoie le nombre de caractères dans la chaîne s. 
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
