/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:21:49 by andrew            #+#    #+#             */
/*   Updated: 2021/11/01 22:56:32 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '-')
			i++;
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_file(char *path, t_map	*map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error_file());
	map->nbline = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_check_line(line))
			return (ft_error_data());
		map->nbline++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}
