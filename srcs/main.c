/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:22:16 by acolin            #+#    #+#             */
/*   Updated: 2021/11/07 19:03:04 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_win(t_map *map)
{
	int	n;

	if ((map->height / map->nbcol) < (map->width / map->nbline))
		map->zoom = (map->height / map->nbcol) / 2;
	else
		map->zoom = (map->width / map->nbline) / 2;
	map->mwin.mlx = mlx_init();
	map->mwin.win = mlx_new_window(map->mwin.mlx, map->width, map->height,
			"fdf");
	map->mwin.img = mlx_new_image(map->mwin.mlx, map->width, map->height);
	map->mwin.buffer = (int *) mlx_get_data_addr(map->mwin.img, &n, &n, &n);
}

void	ft_init_map(t_map *map)
{
	map->height = 1080;
	map->width = 1920;
	map->move = 5;
	map->nbcol = 0;
	map->nbline = 0;
	map->centre.x = (map->width / 2);
	map->centre.y = (-map->height / 4);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		ft_init_map(&map);
		if (!ft_check_file(argv[1], &map))
			return (0);
		if (!ft_parse_file(argv[1], &map))
			return (0);
		if (!ft_gen_point(&map))
			return (ft_error_malloc());
		init_win(&map);
		ft_draw_map(&map);
		mlx_mouse_hook(map.mwin.win, ft_mouse_event, &map);
		mlx_key_hook(map.mwin.win, ft_key_event, &map);
		//mlx_hook(map.mwin.win, 2, 0, ft_key_event, &map);
		//mlx_hook(map.mwin.win, 3, 0, ft_key_event, &map);
		mlx_loop(map.mwin.mlx);
	}
	else
		ft_putendl_fd("usage : ./fdf <path map>", 1);
}
