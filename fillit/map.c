/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:48:09 by anurgali          #+#    #+#             */
/*   Updated: 2019/04/17 20:48:11 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			find_min_mapsize(t_tetr **all_read)
{
	int		i;
	int		totalhash;
	int		size;

	i = 0;
	while (all_read[i])
	{
		i++;
	}
	totalhash = i * 4;
	size = 2;
	while ((size * size) - totalhash < 0)
		size++;
	return (size);
}

char		**makemap(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	map[size] = NULL;
	while (i < size)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (j < size)
		{
			map[i][j++] = '.';
		}
		map[i++][j] = '\0';
	}
	return (map);
}
