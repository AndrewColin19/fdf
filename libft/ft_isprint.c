/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:29:13 by acolin            #+#    #+#             */
/*   Updated: 2021/10/07 12:29:13 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * vérifie s'il s'agit d'un caractère imprimable, y compris l'espace.
 *
 * \param	c	caractère a tester
 * \return		Les valeurs renvoyées sont non nulles 
 *				si le caractère c entre dans la catégorie testée, et zéro sinon
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
