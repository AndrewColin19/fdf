/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:09 by acolin            #+#    #+#             */
/*   Updated: 2021/11/02 12:57:38 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_set_color(t_coor coor)
{
	int	color;

	if (coor.z1 == coor.z2 && coor.z1 > 0)
		color = 0x00FF00FF;
	else if (coor.z1 == coor.z2)
		color = 0x0021A82D;
	else
		color = 0x006B656B;
	return (color);
}

t_coor	ft_set_coor(t_point old_point, t_point point)
{
	t_coor	coor;

	coor.x1 = old_point.x;
	coor.y1 = old_point.y;
	coor.z1 = old_point.z;
	coor.x2 = point.x;
	coor.y2 = point.y;
	coor.z2 = point.z;
	return (coor);
}

static t_calc	ft_init_calc(t_coor coor)
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

void	ft_draw_line(t_coor coor, t_mwin mwin)
{
	t_calc	calc;

	calc = ft_init_calc(coor);
	while (1)
	{
		mlx_pixel_put(mwin.mlx, mwin.win, coor.x1, coor.y1, ft_set_color(coor));
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
