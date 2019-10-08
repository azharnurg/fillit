/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:45:20 by anurgali          #+#    #+#             */
/*   Updated: 2019/04/17 20:45:33 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				checkp(char **map, t_util_v *uvar, t_tetr *curr)
{
	int			i;
	int			length;

	i = 0;
	length = 0;
	uvar->count = 0;
	while (map[0][length])
		length++;
	while (i < 4)
	{
		uvar->new_row = uvar->row + curr->y[i];
		uvar->new_col = uvar->col + curr->x[i];
		if (uvar->new_row < 0 || uvar->new_col < 0 || uvar->new_row >= length
			| uvar->new_col >= length)
			break ;
		if (map[uvar->new_row][uvar->new_col] == '.')
			uvar->count++;
		i++;
	}
	if (uvar->count == 4)
		return (1);
	return (0);
}

void			set_up(int row, int col, int tet_num, t_util_v *uvar)
{
	uvar->row = row;
	uvar->col = col;
	uvar->tetr_num = tet_num;
	uvar->letter = 'A' + tet_num;
}

int				r_back(char **map, t_tetr **all_read, int tet_n, t_util_v *uvar)
{
	int			row;
	int			col;

	if (all_read[tet_n] == NULL)
		return (1);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			set_up(row, col, tet_n, uvar);
			if (map[row][col] == '.' && checkp(map, uvar, all_read[tet_n]))
			{
				tetr_place(map, uvar, all_read[tet_n]);
				if (r_back(map, all_read, (tet_n + 1), uvar))
					return (1);
				set_up(row, col, tet_n, uvar);
				tetr_remove(map, uvar, all_read[tet_n]);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int				ft_solve(t_tetr **all_read)
{
	int			mapsize;
	char		**map;
	t_util_v	*uvar;

	uvar = (t_util_v *)malloc(sizeof(t_util_v));
	mapsize = find_min_mapsize(all_read);
	map = makemap(mapsize);
	while (!r_back(map, all_read, 0, uvar))
	{
		mapsize++;
		map = makemap(mapsize);
	}
	print_map(map);
	return (1);
}
