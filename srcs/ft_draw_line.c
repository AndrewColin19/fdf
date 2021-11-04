/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:09 by acolin            #+#    #+#             */
/*   Updated: 2021/11/04 17:42:06 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_img(t_map *map)
{
	int	x;

	x = map->height * map->width - 1;
	while (x >= 0)
	{
		map->mwin.buffer[x] = 0x00000000;
		x--;
	}
}

void	draw_pixel(t_map *map, int x, int y, int color)
{
	if (x < 0 || x >= map->width)
		return ;
	if (y < 0 || y >= map->height)
		return ;
	map->mwin.buffer[x + y * map->width] = color;
}

int	ft_set_color(t_point a, t_point b)
{
	int	color;

	if (a.z == b.z && a.z > 0)
		color = 0x00FF00FF;
	else if (a.z == b.z)
		color = 0x0021A82D;
	else
		color = 0x006B656B;
	return (color);
}

t_calc	ft_init_calc(t_point a, t_point b)
{
	t_calc	calc;

	calc.dx = b.x - a.x;
	calc.dy = b.y - a.y;
	if (abs(calc.dx) > abs(calc.dy))
		calc.steps = abs(calc.dx);
	else
		calc.steps = abs(calc.dy);
	calc.xinc = calc.dx / (float) calc.steps;
	calc.yinc = calc.dy / (float) calc.steps;
	calc.x = a.x;
	calc.y = a.y;
	return (calc);
}

void	ft_draw_line(t_map *map, t_point a, t_point b)
{
	int		i;
	t_calc	calc;

	if (b.x < 0 || b.x >= map->width)
		return ;
	if (b.y < 0 || b.y >= map->height)
		return ;
	if (a.x < 0 || a.x >= map->width)
		return ;
	if (a.y < 0 || a.y >= map->height)
		return ;
	calc = ft_init_calc(a, b);
	i = 0;
	while (i <= calc.steps)
	{
		draw_pixel(map, calc.x, calc.y,
			ft_set_color(a, b));
		calc.x += calc.xinc;
		calc.y += calc.yinc;
		i++;
	}
}
