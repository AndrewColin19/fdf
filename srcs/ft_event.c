/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:01:03 by acolin            #+#    #+#             */
/*   Updated: 2021/11/07 18:44:39 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	refrech(t_map *map)
{
	clear_img(map);
	ft_draw_map(map);
}

int	ft_mouse_event(int button, int x, int y, void *param)
{
	t_map	*map;

	(void) x;
	(void) y;
	map = (t_map *) param;
	if (button == 4)
	{
		if (map->zoom > 0)
		{
			map->zoom -= 1;
		}
		refrech(map);
	}
	if (button == 5)
	{
		map->zoom += 1;
		refrech(map);
	}
	return (1);
}

void	move_lr(t_map *map, int key)
{
	if (key == 123 || key == 65361)
	{
		map->centre.x += map->move;
		map->centre.y -= map->move;
	}
	if (key == 124 || key == 65363)
	{
		map->centre.x -= map->move;
		map->centre.y += map->move;
	}
}

void	move_ud(t_map *map, int key)
{
	if (key == 126 || key == 65362)
	{
		map->centre.y += map->move;
		map->centre.x += map->move;
	}
	if (key == 125 || key == 65364)
	{
		map->centre.y -= map->move;
		map->centre.x -= map->move;
	}
}

int	ft_key_event(int key_code, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (key_code == 123 || key_code == 124 || key_code == 65361
		|| key_code == 65363)
	{
		move_lr(map, key_code);
		refrech(map);
	}
	if (key_code == 126 || key_code == 125 || key_code == 65362
		|| key_code == 65364)
	{
		move_ud(map, key_code);
		refrech(map);
	}
	if (key_code == 53 || key_code == 65307)
	{
		free_tpoint(map, map->nbline);
		exit(1);
	}
	return (1);
}
