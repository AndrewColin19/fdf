/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:56:03 by acolin            #+#    #+#             */
/*   Updated: 2021/10/28 16:15:24 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

char	*ft_itoa(int n);

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mwin 
{
	void *win;
	void *mlx;
}	t_mwin;

typedef struct	s_coor 
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}	t_coor;

#endif