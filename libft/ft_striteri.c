/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:46:56 by acolin            #+#    #+#             */
/*   Updated: 2021/10/14 15:46:56 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applique la fonction f à chaque caractère de la
 * chaîne de caractères transmise comme argument, et
 * en passant son index comme premier argument. Chaque
 * caractère est transmis par adresse à f pour être
 * modifié si nécessaire.
 *
 * \param	*s	La chaine de caractères sur laquelle itérer.
 * \param	*f	La fonction à appliquer à chaque caractère.
 * \return		None
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
