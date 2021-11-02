/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:43:39 by acolin            #+#    #+#             */
/*   Updated: 2021/10/07 12:43:39 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * convertit la lettre c en majuscule si c'est possible.
 *
 * \param	c	caractère à convertir
 * \return		La valeur renvoyée est celle de la lettre convertie, 
 * 				ou bien c si la conversion n'était pas possible. 
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
