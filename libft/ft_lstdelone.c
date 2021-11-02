/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:43:44 by acolin            #+#    #+#             */
/*   Updated: 2021/10/18 15:20:42 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Libère la mémoire de l’élément passé en argument
 * en utilisant la fonction del puis avec free(3). La
 * mémoire de next ne doit pas être free.
 * 
 * \param	*lst	L’élement à free
 * \param	*del	L’adresse de la fonction permettant de 
 * 					supprimer le contenu de l’élement.
 * \return			none
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
