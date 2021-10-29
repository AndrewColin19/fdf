/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:09 by acolin            #+#    #+#             */
/*   Updated: 2021/10/29 16:08:25 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_utils(t_coor *coor)
{
	coor->dx = abs(coor->x2 - coor->x1);
	coor->dy = -abs(coor->y2 - coor->y1);
	if (coor->x1 < coor->x2)
		coor->sx = 1;
	else
		coor->sx = -1;
	if (coor->y1 < coor->y2)
		coor->sy = 1;
	else
		coor->sy = -1;
	coor->e = coor->dx + coor->dy;
}

void	ft_draw_line(t_coor coor, t_mwin *mwin, int color)
{
	ft_init_utils(&coor);
	while (1)
	{
		mlx_pixel_put(mwin->mlx, mwin->win, coor.x1, coor.y1, color);
		if (coor.x1 == coor.x2 && coor.y1 == coor.y2)
			break ;
		coor.e2 = 2 * coor.e;
		if (coor.e2 >= coor.dy)
		{
			coor.e += coor.dy;
			coor.x1 += coor.sx;
		}
		if (coor.e2 <= coor.dx)
		{
			coor.e += coor.dx;
			coor.y1 += coor.sy;
		}	
	}
}
