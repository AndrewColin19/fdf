/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:01:03 by acolin            #+#    #+#             */
/*   Updated: 2021/11/03 18:46:34 by andrew           ###   ########.fr       */
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
		if (map->scale - map->zoom > 0)
			map->scale -= map->zoom;
		mlx_clear_window(map->mwin.mlx, map->mwin.win);
		ft_draw_map(map);
	}
	if (button == 5)
	{
		map->scale += map->zoom;
		mlx_clear_window(map->mwin.mlx, map->mwin.win);
		ft_draw_map(map);
	}
	return (1);
}
