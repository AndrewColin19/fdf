/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:43:22 by acolin            #+#    #+#             */
/*   Updated: 2021/11/04 17:51:21 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point	set_point(int x, int y, int z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

int	free_tpoint(t_map *map, int ind)
{
	while (ind--)
		free(map->tpoint[ind]);
	free(map->tpoint);
	return (0);
}

int	ft_gen_point(t_map *map)
{
	int	j;
	int	i;

	map->tpoint = malloc(sizeof(t_point *) * map->nbline);
	if (!map->tpoint)
		return (0);
	i = -1;
	while (++i < map->nbline)
	{
		map->tpoint[i] = malloc(sizeof(t_point) * map->nbcol);
		j = -1;
		while (++j < map->nbcol)
			map->tpoint[i][j] = set_point(i, j, map->map[i][j] * map->zoom);
			if (!map->tpoint[i])
				return (free_tpoint(map, i));
	}
	free(map->map);
	return (1);
}
