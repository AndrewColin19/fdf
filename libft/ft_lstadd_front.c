/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:38:20 by acolin            #+#    #+#             */
/*   Updated: 2021/10/14 23:38:20 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ajoute l’élément ’new’ au début de la liste.
 * 
 * \param	**alst		L’adresse du pointeur vers le premier élément 
 * 						de la liste.
 * \param	*new		L’adresse du pointeur vers l’élément à rajouter
 * 						à la liste.
 * \return				None
 */
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
