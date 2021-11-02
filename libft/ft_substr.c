/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:21:23 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 16:56:53 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Alloue (avec malloc(3)) et retourne une chaine de
 * caractères issue de la chaine ’s’.
 * Cette nouvelle chaine commence à l’index ’start’ et
 * a pour taille maximale ’len’
 *
 * \param	*s		La chaine de laquelle extraire la nouvelle
 * 					chaine
 * \param	start	L’index de début de la nouvelle chaine dans la
 * 					chaine ’s’.
 * \param	len		La taille maximale de la nouvelle chaine.
 * \return			The nouvelle chaine de caractere. NULL si
 * 					l’allocation échoue.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = start;
	while (i < (start + len))
	{
		str[i - start] = s[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
