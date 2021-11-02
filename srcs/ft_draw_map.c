/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:46:51 by andrew            #+#    #+#             */
/*   Updated: 2021/11/02 21:13:23 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_point_x(t_point	*point, t_point start)
{
	
}

void	set_point_y(t_point	*point, t_point start)
{
	
}

void	draw(t_point start, t_map map)
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
				ft_draw_line(map.tpoint[i][j], map.tpoint[i + 1][j], map.mwin);
			if (j + 1 < map.nbline)
				ft_draw_line(map.tpoint[i][j], map.tpoint[i][j + 1], map.mwin);
		}
	}
}

int	ft_draw_map(t_map map)
{
	t_point	start;

	start.x = (map.width / map.divw);
	start.y = (-map.height / map.divh);
	draw(start, map);
	return (1);
}
