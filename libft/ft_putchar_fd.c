/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:48:06 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 13:25:23 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrit le caractère ’c’ sur le file descriptor
 * donné.
 *
 * \param	c	Le caractère à écrire.
 * \param	fd	Le file descriptor sur lequel écrire.
 * \return		None
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
