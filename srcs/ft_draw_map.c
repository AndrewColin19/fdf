/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:46:51 by andrew            #+#    #+#             */
/*   Updated: 2021/11/02 16:42:13 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point	set_point(int x, int y, int z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	draw(t_map map, t_point st)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map.nbcol)
	{
		j = -1;
		while (++j < map.nbline)
		{
			if (i + 1 < map.nbcol)
				ft_draw_line()
			if (j + 1 < map.nbline)
		}
}

int	ft_draw_map(t_map map)
{
	t_point	start;

	start = set_point((map.width / map.divw), (-map.height / map.divh), 0);
	ft_draw_ligne(map, start);
	ft_draw_col(map, start);
	return (1);
}
