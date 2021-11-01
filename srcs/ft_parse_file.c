/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:57:37 by andrew            #+#    #+#             */
/*   Updated: 2021/11/01 22:57:40 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_tablen(char **tab)
{
	size_t	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

int	ft_add_map(char **tab, t_map *map, int index)
{
	int		i;
	size_t	size;

	size = ft_tablen(tab);
	map->nbcol = size;
	map->map[index] = malloc(sizeof(int) * size);
	if (!map->map[index])
		return (0);
	i = 0;
	while (tab[i])
	{
		map->map[index][i] = ft_atoi(tab[i]);
		i++;
	}
	return (1);
}

int	ft_parse_file(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	map->map = malloc(sizeof(int *) * map->nbline + 1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (!ft_add_map(ft_split(line, ' '), map, i++))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
