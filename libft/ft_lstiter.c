/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:58:43 by acolin            #+#    #+#             */
/*   Updated: 2021/10/15 00:58:43 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Itère sur la list lst et applique la fonction f au
 * contenu chaque élément.
 * 
 * \param	*lst	L’adresse du pointeur vers un élément.
 * \param	*f		L’adresse de la fonction à appliquer.
 * \return			None
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
