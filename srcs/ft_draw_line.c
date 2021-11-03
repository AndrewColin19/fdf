/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:09 by acolin            #+#    #+#             */
/*   Updated: 2021/11/03 18:43:21 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_set_color(t_point point1, t_point point2)
{
	int	color;

	if (point1.z == point2.z && point1.z > 0)
		color = 0x00FF00FF;
	else if (point1.z == point2.z)
		color = 0x0021A82D;
	else
		color = 0x006B656B;
	return (color);
}

static t_calc	ft_init_calc(t_point point1, t_point point2)
{
	t_calc	calc;

	calc.dx = abs(point2.x - point1.x);
	calc.dy = -abs(point2.y - point1.y);
	if (point1.x < point2.x)
		calc.sx = 1;
	else
		calc.sx = -1;
	if (point1.y < point2.y)
		calc.sy = 1;
	else
		calc.sy = -1;
	calc.e = calc.dx + calc.dy;
	return (calc);
}

void	ft_draw_line(t_point point1, t_point point2, t_mwin mwin)
{
	t_calc	calc;

	calc = ft_init_calc(point1, point2);
	while (1)
	{
		mlx_pixel_put(mwin.mlx, mwin.win, point1.x, point1.y,
			ft_set_color(point1, point2));
		if (point1.x == point2.x && point1.y == point2.y)
			break ;
		calc.e2 = 2 * calc.e;
		if (calc.e2 >= calc.dy)
		{
			calc.e += calc.dy;
			point1.x += calc.sx;
		}
		if (calc.e2 <= calc.dx)
		{
			calc.e += calc.dx;
			point1.y += calc.sy;
		}	
	}
}
