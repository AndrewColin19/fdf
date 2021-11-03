/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:54:10 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 16:10:47 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrit l’integer ’n’ sur le file descriptor donné.
 *
 * \param	n	La chaine de caractères à écrire.
 * \param	fd	Le file descriptor sur lequel écrire.
 * \return		None
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	if (nbr)
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr = -nbr;
		}
		if (nbr >= 10)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(((nbr % 10) + '0'), fd);
	}
}
