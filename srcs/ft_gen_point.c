/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:43:22 by acolin            #+#    #+#             */
/*   Updated: 2021/11/02 17:00:44 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	free_tpoint(t_map *map, int ind)
{
	while (ind--)
		free(map->tpoint[ind]);
	free(map->tpoint);
	return (0);
}

int m_point(t_map *map)
{
	int i;

	map->tpoint = malloc(sizeof(t_point *) * map->nbline);
	if (!map->tpoint)
		return (0); 
	i = -1;
	while (++i < map->nbline)
	{
		map->tpoint[i] = malloc(sizeof(t_point) * map->nbcol);
		if (!map->tpoint[i])
			return (free_tpoint(map));
	}
	return (1);
}

int	ft_gen_point(t_map *map)
{
	int	j;
	int	i;

	if (!m_point(map))
		return (0);
	i = -1;
	while (++i < map->nbline)
	{
		j = -1;
		while (++j < map->nbcol)
			map->tpoint[i][j] = iso_proj(set_point(i, j, map[i][j]), *map);
	}
	return (1);
}