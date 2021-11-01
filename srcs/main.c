/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:22:16 by acolin            #+#    #+#             */
/*   Updated: 2021/11/01 22:43:31 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_mwin	mwin;

	if (argc == 2)
	{
		if (!ft_check_file(argv[1], &map))
			return (0);
		if (!ft_parse_file(argv[1], &map))
			return (ft_error_data());
		mwin = ft_init_window(1000, 1000);
		ft_draw_map(mwin, map, 0x00FF00);
		mlx_loop(mwin.mlx);
	}
}
