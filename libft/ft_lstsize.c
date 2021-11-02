/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:54:31 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 11:26:20 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compte le nombre d’éléments de la liste.
 * 
 * \param	*lst	Le début de la liste.
 * \return			Taille de la liste.
 */
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*sv;

	i = 0;
	sv = lst;
	while (sv)
	{
		sv = sv->next;
		i++;
	}
	return (i);
}
