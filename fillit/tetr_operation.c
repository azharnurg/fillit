/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:03:29 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/01 15:08:24 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetr_place(char **map, t_util_v *uvar, t_tetr *curr)
{
	int	*y;
	int	*x;
	int	i;

	i = 0;
	y = curr->y;
	x = curr->x;
	while (i < 4)
	{
		uvar->new_row = uvar->row + y[i];
		uvar->new_col = uvar->col + x[i];
		map[uvar->new_row][uvar->new_col] = uvar->letter;
		i++;
	}
}

void	tetr_remove(char **map, t_util_v *uvar, t_tetr *curr)
{
	int	*y;
	int	*x;
	int i;

	i = 0;
	y = curr->y;
	x = curr->x;
	while (i < 4)
	{
		uvar->new_row = uvar->row + y[i];
		uvar->new_col = uvar->col + x[i];
		map[uvar->new_row][uvar->new_col] = '.';
		i++;
	}
}

int		can_place(t_board *b, t_tetr *t, t_loc pos)
{
	int	i;
	int	j;

	j = 0;
	if ((t->w + pos.x > b->w) || (t->h + pos.y > b->h))
		return (0);
	while (j < t->h)
	{
		i = 0;
		while (i < t->w)
		{
			if (ELEM(t, i, j) != '.' && ELEM(b, pos.x + i, pos.y + j) != '.')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		place_tetr_pat(t_board *b, t_tetr *t, t_loc pos, char symb)
{
	int i;
	int j;

	j = 0;
	if (!can_place(b, t, pos))
		return (0);
	while (j < t->h)
	{
		i = 0;
		while (i < t->w)
		{
			if (ELEM(t, i, j) != '.')
				ELEM(b, pos.x + i, pos.y + j) = symb;
			i++;
		}
		j++;
	}
	return (1);
}
