/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:34:18 by acolin            #+#    #+#             */
/*   Updated: 2021/10/14 14:34:18 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_int(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_fill(int *i, char *s, long n)
{
	if (n >= 10)
	{
		ft_fill(i, s, n / 10);
		ft_fill(i, s, n % 10);
	}
	else
		s[(*i)++] = n + '0';
}

/**
 * Alloue (avec malloc(3)) et retourne une chaine de
 * caractères représentant l’integer reçu en argument.
 * Les nombres négatifs doivent être gérés.
 *
 * \param	n	l’integer à convertir.
 * \return		La chaine de caractères représentant l’integer.
 * 				NULL si l’allocation échoue.
 */
char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*s;

	nb = n;
	s = malloc(sizeof(char) * (ft_size_int(nb) + 1));
	if (!s)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		s[i++] = '-';
		nb *= -1;
	}
	ft_fill(&i, s, nb);
	s[i] = '\0';
	return (s);
}
