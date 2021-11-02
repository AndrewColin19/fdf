/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:01:03 by acolin            #+#    #+#             */
/*   Updated: 2021/11/02 13:38:39 by acolin           ###   ########.fr       */
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
		map->scale -= 1;
		mlx_clear_window(map->mwin.mlx, map->mwin.win);
		ft_draw_map(*map);
	}
	if (button == 5)
	{
		map->scale += 1;
		mlx_clear_window(map->mwin.mlx, map->mwin.win);
		ft_draw_map(*map);
	}
	return (1);
}
