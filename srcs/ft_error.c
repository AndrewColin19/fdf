/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:50:13 by andrew            #+#    #+#             */
/*   Updated: 2021/11/04 17:50:17 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_error_data(void)
{
	ft_putendl_fd("data error", 1);
	return (0);
}

int	ft_error_file(void)
{
	ft_putendl_fd("file error", 1);
	return (0);
}

int	ft_error_parse(void)
{
	ft_putendl_fd("parse error", 1);
	return (0);
}

int	ft_error_malloc(void)
{
	ft_putendl_fd("memory error", 1);
	return (0);
}
