/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:21:49 by andrew            #+#    #+#             */
/*   Updated: 2021/11/07 18:30:21 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_ishexa(char c)
{
	if (!ft_isdigit(c) && !(c >= 65 && c <= 70) && !(c >= 97 && c <= 102))
		return (0);
	return (1);
}

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
		else if (line[i] == ',' || line[i] == 'x')
			i++;
		else if (ft_isdigit(line[i]))
			i++;
		else if (ft_ishexa(line[i]))
			i++;
		else
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
	line = get_next_line(fd);
	while (line)
	{
		if (ft_check_line(line))
		{
			map->nbline++;
			free(line);
			line = get_next_line(fd);
		}
		else
			return (ft_error_data(line));
	}
	free(line);
	close(fd);
	return (1);
}
