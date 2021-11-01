/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:09 by acolin            #+#    #+#             */
/*   Updated: 2021/10/30 22:17:15 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_coor	ft_set_coor(int x1, int y1, int x2, int y2)
{
	t_coor	coor;

	coor.x1 = x1;
	coor.y1 = y1;
	coor.x2 = x2;
	coor.y2 = y2;
	return (coor);
}

static t_calc	ft_init_clac(t_coor coor)
{
	t_calc	calc;

	calc.dx = abs(coor.x2 - coor.x1);
	calc.dy = -abs(coor.y2 - coor.y1);
	if (coor.x1 < coor.x2)
		calc.sx = 1;
	else
		calc.sx = -1;
	if (coor.y1 < coor.y2)
		calc.sy = 1;
	else
		calc.sy = -1;
	calc.e = calc.dx + calc.dy;
	return (calc);
}

void	ft_draw_line(t_coor coor, t_mwin mwin, int color)
{
	t_calc	calc;

	calc = ft_init_clac(coor);
	while (1)
	{
		mlx_pixel_put(mwin.mlx, mwin.win, coor.x1, coor.y1, color);
		if (coor.x1 == coor.x2 && coor.y1 == coor.y2)
			break ;
		calc.e2 = 2 * calc.e;
		if (calc.e2 >= calc.dy)
		{
			calc.e += calc.dy;
			coor.x1 += calc.sx;
		}
		if (calc.e2 <= calc.dx)
		{
			calc.e += calc.dx;
			coor.y1 += calc.sy;
		}	
	}
}
