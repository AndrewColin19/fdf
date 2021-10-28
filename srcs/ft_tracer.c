/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:09 by acolin            #+#    #+#             */
/*   Updated: 2021/10/28 16:16:18 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_tracer(t_coor coor, t_mwin mwin, int color)
{
	int dx;
	int dy;
	int e;

	e = coor.x2 - coor.x1;
	dx = e * 2;
	dy = (coor.y2 - coor.y1 * 2);
	while (coor.x1 <= coor.x2)
	{
		mlx_pixel_put(mwin.mlx, mwin.win, coor.x1, coor.y1, color);
		coor.x1 += 1;
		coor.y1 -= 1;
	}
}