/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:46:51 by andrew            #+#    #+#             */
/*   Updated: 2021/11/03 18:43:43 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	iso(t_point *p)
{
	t_point	save;

	save.x = p->x;
	save.y = p->y;
	p->x = (save.x - save.y) * cos(0.5);
	p->y = (save.x + save.y) * sin(0.5) - p->z;
}

t_point	*set_point_xy(t_point *point, t_map *map, int i, int j)
{
	point->x = map->start.x + (map->scale * j);
	point->y = map->start.y + (map->scale * i);
	iso(point);
	return (point);
}

void	draw(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->nbline)
	{
		j = -1;
		while (++j < map->nbcol)
		{
			if (j + 1 < map->nbcol)
				ft_draw_line(map->tpoint[i][j], map->tpoint[i][j + 1],
					map->mwin);
			if (i + 1 < map->nbline)
				ft_draw_line(map->tpoint[i][j], map->tpoint[i + 1][j],
					map->mwin);
		}
	}
}

void	calc(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->nbline)
	{
		j = -1;
		while (++j < map->nbcol)
			set_point_xy(&map->tpoint[i][j], map, i, j);
	}
}

int	ft_draw_map(t_map *map)
{
	map->start.x = (map->width / 2) / 2;
	map->start.y = (-map->height / 2) / 2;
	calc(map);
	draw(map);
	return (1);
}
