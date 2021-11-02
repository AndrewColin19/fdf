/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:08:03 by acolin            #+#    #+#             */
/*   Updated: 2021/10/07 15:08:03 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ajoute la chaîne terminée par NUL src à la fin de dst. 
 * Il ajoutera au plus size - strlen (dst) - 1 octets, 
 * terminant le résultat par NUL.
 *
 * \param	*dst	La chaîne à ajouter à src
 * \param	*src	La chaîne à y ajouter
 * \param	size	La taille du tampon de destination.
 * \return			renvoient la longueur totale de la chaîne 
 * 					qu'elles ont essayé de créer.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	size_t	size_dst;
	size_t	i;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	i = 0;
	if (size <= size_dst)
		return (size + size_src);
	while (src[i] != '\0' && (i + size_dst) < (size - 1))
	{
		dst[i + size_dst] = src[i];
		i++;
	}
	dst[i + size_dst] = '\0';
	return (size_dst + size_src);
}
