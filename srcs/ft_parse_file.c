/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:57:37 by andrew            #+#    #+#             */
/*   Updated: 2021/11/04 17:19:19 by acolin           ###   ########.fr       */
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

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
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
	char	**tab;

	tab = ft_split(line, ' ');
	i = 0;
	map->map[index] = (int *) malloc(sizeof(int *) * ft_tablen(tab));
	while (tab[i])
	{
		map->map[index][i] = ft_atoi(tab[i]);
		i++;
	}
	map->nbcol = i;
	free_tab(tab);
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
	map->map = (int **) malloc(sizeof(int **) * map->nbline);
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
