/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:46:51 by andrew            #+#    #+#             */
/*   Updated: 2021/11/02 14:04:57 by acolin           ###   ########.fr       */
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

void	ft_draw_ligne(t_map map, t_point st)
{
	int		i;
	int		j;
	t_point	point;
	t_point	old_point;

	i = -1;
	while (++i < map.nbline)
	{
		j = -1;
		while (++j < map.nbcol)
		{
			if (i >= 0 && j > 0)
			{
				old_point = point;
				st.x += map.scale;
				point = ft_project(set_point(st.x, st.y, map.map[i][j]));
				ft_draw_line(ft_set_coor(old_point, point), map.mwin);
			}
			else
				point = ft_project(set_point(st.x, st.y, map.map[i][j]));
		}
		st.x = map.width / map.divw;
		st.y += map.scale;
	}
}

void	ft_draw_col(t_map map, t_point st)
{
	int		i;
	int		j;
	t_point	point;
	t_point	old_point;

	i = -1;
	while (++i < map.nbcol)
	{
		j = -1;
		while (++j < map.nbline)
		{
			if (i >= 0 && j > 0)
			{
				old_point = point;
				st.y += map.scale;
				point = ft_project(set_point(st.x, st.y, map.map[j][i]));
				ft_draw_line(ft_set_coor(old_point, point), map.mwin);
			}
			else
				point = ft_project(set_point(st.x, st.y, map.map[j][i]));
		}
		st.y = -map.height / map.divh;
		st.x += map.scale;
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
