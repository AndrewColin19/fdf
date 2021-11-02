/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:30:22 by acolin            #+#    #+#             */
/*   Updated: 2021/10/07 16:30:22 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * met à 0 (octets contenant « \0 ») les n premiers octets du bloc 
 * pointé par s.
 *
 * \param	*s	pointeur sur une zone mémoire
 * \param	n	nombres d'octets
 * \return		None
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
