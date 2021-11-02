/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:49:52 by acolin            #+#    #+#             */
/*   Updated: 2021/10/15 00:49:52 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Supprime et libère la mémoire de l’élément passé en
 * paramètre, et de tous les élements qui suivent, à
 * l’aide de del et de free(3)
 * Enfin, le pointeur initial doit être mis à NULL
 * 
 * \param	**lst	L’adresse du pointeur vers un élément
 * \param	*del	L’adresse de la fonction permettant de 
 * 					supprimer le contenu d’un élément.
 * \return			None
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = next;
		}
		*lst = NULL;
	}
}
