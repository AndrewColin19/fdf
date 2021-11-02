/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:39:15 by acolin            #+#    #+#             */
/*   Updated: 2021/10/14 15:39:15 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applique la fonction ’f’ à chaque caractère de la
 * chaine de caractères passée en argument pour créer
 * une nouvelle chaine de caractères (avec malloc(3))
 * résultant des applications successives de ’f’.
 *
 * \param	*s	La chaine de caractères sur laquelle itérer
 * \param	*f	La fonction à appliquer à chaque caractère.
 * \return		La chaine de caractères résultant des applications
 * 				successives de f. Retourne NULL si l’allocation
 * 				échoue.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
