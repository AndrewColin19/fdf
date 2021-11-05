/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:01:03 by acolin            #+#    #+#             */
/*   Updated: 2021/11/05 15:40:41 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    refrech(t_map *map)
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

void    move_lr(t_map *map, int key)
{
    if (key == 123)
    {
        map->centre.x += map->move;
        map->centre.y -= map->move;
    }
    if (key == 124)
    {
        map->centre.x -= map->move;
        map->centre.y += map->move;
    }
}

void    move_ud(t_map *map, int key)
{
    if (key == 126)
    {
        map->centre.y += map->move;
        map->centre.x += map->move;
    }
    if (key == 125)
    {
        map->centre.y -= map->move;
        map->centre.x -= map->move;
    }
}

int ft_key_event(int key_code, void *param)
{
    t_map *map;

    map = (t_map *) param;
    if (key_code == 123 || key_code == 124)
    {
        move_lr(map, key_code);
        refrech(map);
    }
    if (key_code == 126 || key_code == 125)
    {
        move_ud(map, key_code);
        refrech(map);
    }
    return (1);
}
