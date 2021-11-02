/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:18:53 by acolin            #+#    #+#             */
/*   Updated: 2021/10/07 12:18:53 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * vérifie si l'on a un caractère alphabétique.
 *
 * \param	c	caractère a tester
 * \return		Les valeurs renvoyées sont non nulles 
 *				si le caractère c entre dans la catégorie testée, et zéro sinon
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
