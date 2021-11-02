/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:53:19 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 11:50:42 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * copie n octets depuis la zone mémoire src vers la zone mémoire dst. 
 * Les deux zones peuvent se chevaucher : la copie se passe comme si les 
 * octets de src étaient d'abord copiés dans une zone temporaire qui ne 
 * chevauche ni src ni dst, et les octets sont ensuite copiés de la zone 
 * temporaire vers dst.
 *
 * \param	*dst	pointeur sur la zone mémoire de déstination
 * \param	*src	pointeur sur la zone mémoire source
 * \param	n		nombres d'octets à copier
 * \return			renvoie un pointeur sur dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
