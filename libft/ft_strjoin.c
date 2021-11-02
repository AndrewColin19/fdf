/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:44:58 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 17:59:56 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Alloue (avec malloc(3)) et retourne une nouvelle
 * chaine, résultat de la concaténation de s1 et s2.
 *
 * \param	*s1		La chaine de caractères préfixe.
 * \param	*s2		La chaine de caractères suffixe.
 * \return			La nouvelle chaine de caractères. NULL si
 * 					l’allocation échoue.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s1_size;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	str = malloc(sizeof(char) * (s1_size + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[s1_size + i] = s2[i];
		i++;
	}
	str[s1_size + i] = '\0';
	return (str);
}
