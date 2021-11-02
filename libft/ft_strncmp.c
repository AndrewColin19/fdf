/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:25:54 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 12:39:55 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * compare les deux chaînes s1 et s2. Elle renvoie un entier négatif, 
 * nul, ou positif, si s1 est respectivement inférieure, 
 * égale ou supérieure à s2.
 *
 * \param	*s1		chaine 1
 * \param	*s2		chaine 2
 * \param	n		nombres de caractère
 * \return			renvoient un entier inférieur, égal ou supérieur à zéro 
 * 					si s1 (ou ses n premiers octets) 
 * 					est respectivement inférieure, égale ou supérieure à s2. 
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sa;
	unsigned char	*sb;
	size_t			i;

	if (n == 0)
		return (0);
	sa = (unsigned char *) s1;
	sb = (unsigned char *) s2;
	i = 0;
	while (sa[i] == sb[i] && sa[i] != '\0' && sb[i] != '\0' && i < n - 1)
		i++;
	return (sa[i] - sb[i]);
}
