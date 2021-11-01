/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:50:12 by andrew            #+#    #+#             */
/*   Updated: 2021/11/01 22:58:14 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mwin	ft_init_window(int height, int width)
{
	t_mwin	mwin;

	mwin.mlx = mlx_init();
	mwin.win = mlx_new_window(mwin.mlx, width, height, "fdf");
	return (mwin);
}
