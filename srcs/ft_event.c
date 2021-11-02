/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:01:03 by acolin            #+#    #+#             */
/*   Updated: 2021/11/02 15:51:35 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_mouse_event(int button, int x, int y, void *param)
{
	t_map	*map;

	(void) x;
	(void) y;
	map = (t_map *) param;
	if (button == 4)
	{
		map->scale -= 5;
		mlx_clear_window(map->mwin.mlx, map->mwin.win);
		ft_draw_map(*map);
	}
	if (button == 5)
	{
		map->scale += 5;
		mlx_clear_window(map->mwin.mlx, map->mwin.win);
		ft_draw_map(*map);
	}
	return (1);
}

int	ft_key_event(int key_code, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (key_code == 123)
	{
		map->width -= 20;
		map->height -= 20;
	}
	if (key_code == 124)
	{
		map->width += 20;
		map->height += 20;
	}
	if (key_code == 125)
	{
		map->width += 20;
		map->height -= 20;
	}
	if (key_code == 126)
	{
		map->width -= 20;
		map->height += 20;
	}
	mlx_clear_window(map->mwin.mlx, map->mwin.win);
	ft_draw_map(*map);
	return (1);
}