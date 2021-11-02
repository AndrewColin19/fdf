/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projec_iso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:41:46 by andrew            #+#    #+#             */
/*   Updated: 2021/11/02 16:30:15 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point	rotate_x(t_point p, double alpha)
{
	int	y;

	y = p.y;
	p.y = y * cos(alpha) + p.z * sin(alpha);
	p.z = -y * sin(alpha) + p.z * cos(alpha);
	return (p);
}

t_point	rotate_y(t_point p, double beta)
{
	int	x;

	x = p.x;
	p.x = x * cos(beta) + p.z * sin(beta);
	p.z = -x * sin(beta) + p.z * cos(beta);
	return (p);
}

t_point	rotate_z(t_point p, double gamma)
{
	int	x;
	int	y;

	x = p.x;
	y = p.y;
	p.x = x * cos(gamma) - y * sin(gamma);
	p.y = x * sin(gamma) + y * cos(gamma);
	return (p);
}

t_point	iso_proj(t_point p, t_map map)
{
	t_point	save;

	save.x = p.x;
	save.y = p.y;
	p.x = (save.x - save.y) + map.scale * cos(0.5);
	p.y = (save.x + save.y) + map.scale * sin(0.5) - p.z;
	return (p);
}
