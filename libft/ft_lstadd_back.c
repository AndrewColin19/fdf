/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:24:27 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 15:32:31 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ajoute l’élément new à la fin de la liste.
 * 
 * \param	**alst	L’adresse du pointeur vers le premier élément
 * 					de la liste.
 * \param	*new	L’adresse du pointeur vers l’élément à rajouter 
 * 					à la liste.
 * \return			none
 */
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	lst = ft_lstlast(*(alst));
	lst->next = new;
}
