/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:36:05 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 15:25:00 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * copie jusqu'à la taille - 1 caractères de la chaîne terminée par NUL 
 * src vers dst, terminant le résultat par NUL.
 *
 * \param	*dst	La chaîne à ajouter à src
 * \param	*src	La chaîne à y ajouter
 * \param	size	La taille du tampon de destination.
 * \return			renvoient la longueur totale de la chaîne 
 * 					qu'elles ont essayé de créer.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
