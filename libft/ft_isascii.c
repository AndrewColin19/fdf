/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:27:43 by acolin            #+#    #+#             */
/*   Updated: 2021/10/07 12:27:43 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * vérifie si c est un unsigned char sur 7 bits, 
 * entrant dans le jeu de caractères ASCII.
 *
 * \param	c	caractère a tester
 * \return		Les valeurs renvoyées sont non nulles 
 *				si le caractère c entre dans la catégorie testée, et zéro sinon
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
