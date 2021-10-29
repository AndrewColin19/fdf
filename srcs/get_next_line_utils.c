/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:19:46 by acolin            #+#    #+#             */
/*   Updated: 2021/10/29 16:42:34 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	cpy_buf(char **s, char buf)
{
	char	*tmp;
	size_t	size_s;

	size_s = ft_strlen(s[0]);
	tmp = malloc(sizeof(char) * size_s + 1);
	ft_strncpy(tmp, s[0], size_s + 1);
	free(s[0]);
	s[0] = malloc(size_s + 2);
	ft_strncpy(s[0], tmp, size_s + 1);
	s[size_s + 1] = '\0';
	free(tmp);
}
