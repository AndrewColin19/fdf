/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:57:37 by andrew            #+#    #+#             */
/*   Updated: 2021/11/07 18:50:11 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

int	ft_add_map(char *line, t_map *map, int index)
{
	int		i;
	int		size_tab;
	char	**tab;

	tab = ft_split(line, ' ');
	i = 0;
	size_tab = ft_tablen(tab);
	map->map[index] = malloc(sizeof(int *) * size_tab);
	while (tab[i])
	{
		map->map[index][i] = ft_atoi(tab[i]);
		i++;
	}
	map->nbcol = i;
	free_tab(tab, size_tab);
	return (1);
}

int	ft_parse_file(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error_file());
	map->map = malloc(sizeof(int **) * map->nbline);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (ft_add_map(line, map, i) == 0)
			return (0);
		if (line)
			free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}
