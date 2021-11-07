/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:46:51 by andrew            #+#    #+#             */
/*   Updated: 2021/11/07 18:30:37 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	iso(t_point *p)
{
	t_point	save;

	save.x = p->x;
	save.y = p->y;
	p->x = (save.x - save.y) * cos(M_PI / 4);
	p->y = (save.x + save.y) * sin(M_PI / 4) - p->z;
}

void	set_point_xy(t_point *point, t_map *map, int i, int j)
{
	point->x = map->start.x + (map->zoom * j);
	point->y = map->start.y + (map->zoom * i);
	iso(point);
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
				ft_draw_line(map, map->tpoint[i][j], map->tpoint[i][j + 1]);
			if (i + 1 < map->nbline)
				ft_draw_line(map, map->tpoint[i][j], map->tpoint[i + 1][j]);
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
	int	i;

	map->start.x = map->centre.x;
	map->start.y = map->centre.y;
	i = -1;
	while (++i < (map->nbcol / 2))
		map->start.x -= map->zoom;
	i = -1;
	while (++i < (map->nbline / 2))
		map->start.y -= map->zoom;
	calc(map);
	draw(map);
	mlx_put_image_to_window(map->mwin.mlx, map->mwin.win, map->mwin.img, 0, 0);
	return (1);
}
