/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:50:13 by andrew            #+#    #+#             */
/*   Updated: 2021/11/01 22:54:44 by andrew           ###   ########.fr       */
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
