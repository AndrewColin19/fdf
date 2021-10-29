/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:24:18 by acolin            #+#    #+#             */
/*   Updated: 2021/10/29 16:45:47 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*out;
	static char	buf;
	int			x;
	int			i;

	out = NULL;
	x = read(fd, buf, 1);
	while (x > 0)
	{
		if (buf == '\0')
			return (NULL);
		x = cpy_buf(&out, buf);
		if (x > 0)
			x = read(fd, buf, 1);
	}
	return (out);
}
