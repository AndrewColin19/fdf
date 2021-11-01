/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:24:18 by acolin            #+#    #+#             */
/*   Updated: 2021/11/01 22:59:45 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_copy(char *out, char buf)
{
	char	*tmp;
	size_t	size;

	tmp = NULL;
	if (out == NULL)
		out = ft_strdup(&buf);
	else
	{
		size = ft_strlen(out);
		tmp = ft_strdup(out);
		free(out);
		out = malloc(sizeof(char) * size + 2);
		ft_strlcat(out, tmp, size + 1);
		ft_strlcat(out, &buf, size + 2);
		tmp = NULL;
	}
	if (tmp)
		free(tmp);
	return (out);
}

char	*get_next_line(int fd)
{
	char	*out;
	char	buf;

	out = NULL;
	if (fd == -1)
		return (NULL);
	while (read(fd, &buf, 1) > 0)
	{
		out = ft_copy(out, buf);
		if (buf == '\n')
			return (out);
	}
	return (out);
}
