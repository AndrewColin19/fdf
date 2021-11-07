/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:34:54 by acolin            #+#    #+#             */
/*   Updated: 2021/11/07 18:43:41 by acolin           ###   ########.fr       */
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
	void	*img;
	int		*buffer;
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
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
}	t_calc;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	int		**map;
	t_point	**tpoint;
	t_point	start;
	t_point	centre;
	int		nbline;
	int		nbcol;
	int		scale;
	int		height;
	int		width;
	int		zoom;
	int		move;
	t_mwin	mwin;
}	t_map;

t_coor	ft_set_coor(t_point old_point, t_point point);
void	ft_draw_line(t_map *map, t_point a, t_point b);
char	*get_next_line(int fd);
int		ft_check_file(char *path, t_map	*map);
int		ft_parse_file(char *path, t_map	*map);
int		ft_draw_map(t_map *map);
int		free_tpoint(t_map *map, int ind);
t_point	iso_proj(t_point p);
int		ft_gen_point(t_map *map);
int		ft_error_file(void);
int		ft_error_data(char *line);
int		ft_error_parse(void);
int		ft_mouse_event(int button, int x, int y, void *param);
int		ft_key_event(int key_code, void *param);
int		ft_error_malloc(void);
void	clear_img(t_map *map);

#endif