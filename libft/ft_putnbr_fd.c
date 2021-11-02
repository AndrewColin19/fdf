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
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n && n >= -2147483647 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
}
