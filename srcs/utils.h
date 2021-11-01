/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:56:03 by acolin            #+#    #+#             */
/*   Updated: 2021/11/01 23:05:06 by andrew           ###   ########.fr       */
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
# include "libft/libft.h"

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
	int	**map;
	int	nbline;
	int	nbcol;
	int	x;
	int	y;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int old_x;
	int old_y;
}	t_point;

t_coor	ft_set_coor(int x1, int y1, int x2, int y2);
void	ft_draw_line(t_coor coor, t_mwin mwin, int color);
char	*get_next_line(int fd);
int		ft_check_file(char *path, t_map	*map);
int		ft_parse_file(char *path, t_map	*map);
t_mwin	ft_init_window(int height, int width);
int		ft_draw_map(t_mwin mwin, t_map map, int color);
int		ft_draw_map2(t_mwin mwin, t_map map, int color);
t_point	ft_project(t_point p);
t_point	ft_set_point(int x, int y, int z);
int		ft_error_file(void);
int		ft_error_data(void);

#endif