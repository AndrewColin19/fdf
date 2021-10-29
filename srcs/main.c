/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:22:16 by acolin            #+#    #+#             */
/*   Updated: 2021/10/29 16:54:58 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		int fd;
		char *line;
		t_mwin	mwin;

		mwin.mlx = mlx_init();
		mwin.win = mlx_new_window(mwin.mlx, 500, 500, "fdf");
		fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
		mlx_loop(mwin.mlx);
	}
}
