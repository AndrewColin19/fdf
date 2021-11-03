/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:22:16 by acolin            #+#    #+#             */
/*   Updated: 2021/11/03 19:02:22 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mwin	ft_init_window(int height, int width)
{
	t_mwin	mwin;

	mwin.mlx = mlx_init();
	mwin.win = mlx_new_window(mwin.mlx, width, height, "fdf");
	return (mwin);
}

void	ft_init_map(t_map *map)
{
	map->height = 1080;
	map->width = 1920;
	map->scale = 50;
	map->zoom = 5;
	map->mult = 2;
	map->mwin = ft_init_window(map->height, map->width);
	ft_gen_point(map);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		if (!ft_parse_file(argv[1], &map))
			return (ft_error_data());
		ft_init_map(&map);
		ft_draw_map(&map);
		mlx_mouse_hook(map.mwin.win, ft_mouse_event, &map);
		mlx_loop(map.mwin.mlx);
	}
	else
		ft_putendl_fd("usage : ./fdf <path map>", 1);
}
