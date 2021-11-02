/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:56:03 by acolin            #+#    #+#             */
/*   Updated: 2021/11/02 16:58:25 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_mwin
{
	void	*win;
	void	*mlx;
}	t_mwin;

typedef struct s_coor
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		z1;
	int		z2;
}	t_coor;

typedef struct s_calc
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e;
	int		e2;
}	t_calc;

typedef struct s_map
{
	int		**map;
	t_point	**tpoint;
	int		nbline;
	int		nbcol;
	int		scale;
	int		mult;
	int		divh;
	int		divw;
	int		height;
	int		width;
	t_mwin	mwin;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

t_coor	ft_set_coor(t_point old_point, t_point point);
void	ft_draw_line(t_point point1, t_point point2, t_mwin mwin);
char	*get_next_line(int fd);
int		ft_check_file(char *path, t_map	*map);
int		ft_parse_file(char *path, t_map	*map);
int		ft_draw_map(t_map map);
t_point	iso_proj(t_point p, t_map map);
t_point	set_point(int x, int y, int z);
int		ft_error_file(void);
int		ft_error_data(void);
int		ft_mouse_event(int button, int x, int y, void *param);
int		ft_key_event(int key_code, void *param);

#endif