/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:46:51 by andrew            #+#    #+#             */
/*   Updated: 2021/11/01 23:31:06 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point	ft_set_point(int x, int y, int z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	ft_draw_ligne(t_mwin mwin, t_map map, t_point coor, int color)
{
	int		i;
	int		j;
	t_point	point;
	t_point	old_point;

	i = 0;
	while (i < map.nbline)
	{
		j = 0;
		while (j < map.nbcol)
		{
			if (i >= 0 && j > 0)
			{
				old_point = point;
				coor.x += 20;
				point = ft_project(ft_set_point(coor.x, coor.y, map.map[i][j]));
				ft_draw_line(ft_set_coor(old_point.x, old_point.y,
						point.x, point.y), mwin, color);
			}
			else
				point = ft_project(ft_set_point(coor.x, coor.y, map.map[i][j]));
			j++;
		}
		coor.x = 550;
		coor.y += 20;
		i++;
	}
}

void	ft_draw_col(t_mwin mwin, t_map map, t_point coor, int color)
{
	int		i;
	int		j;
	t_point	point;
	t_point	old_point;

	i = 0;
	while (i < map.nbcol)
	{
		j = 0;
		while (j < map.nbline)
		{
			if (i >= 0 && j > 0)
			{
				old_point = point;
				coor.y += 20;
				point = ft_project(ft_set_point(coor.x, coor.y, map.map[j][i]));
				ft_draw_line(ft_set_coor(old_point.x, old_point.y,
						point.x, point.y), mwin, color + map.map[j][i]);
			}
			else
				point = ft_project(ft_set_point(coor.x, coor.y, map.map[j][i]));
			j++;
		}
		coor.y = 250;
		coor.x += 20;
		i++;
	}
}

int	ft_draw_map(t_mwin mwin, t_map map, int color)
{
	t_point coor;

	coor = ft_set_point(550, 250, 0);
	ft_draw_ligne(mwin, map, coor, color);
	ft_draw_col(mwin, map, coor, color);
	return (1);
}
