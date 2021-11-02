/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:49:34 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 11:38:31 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrit La chaine de caractères ’s’ sur le file
 * descriptor donné, suivie d’un retour à la ligne.
 *
 * \param	*s	La chaine de caractères à écrire.
 * \param	fd	Le file descriptor sur lequel écrire.
 * \return		None
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
