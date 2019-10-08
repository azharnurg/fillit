/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:55:19 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/01 15:08:25 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	from_board_to_pattern(t_pattern *p, t_board *b)
{
	int	i;
	int	j;
	int	pos;

	j = 0;
	pos = 0;
	while (j < b->h)
	{
		i = 0;
		while (i < b->w)
		{
			p->s[pos] = ELEM(b, i, j);
			i++;
			pos++;
		}
		p->s[pos] = '\n';
		pos++;
		j++;
	}
}

int		fill_pattern(t_pattern *p, t_board *tmp, int type, int counter)
{
	t_loc	pos;
	int		i;

	i = counter;
	pos.x = 0;
	while (pos.x + g_t[type].w < 5)
	{
		pos.y = 0;
		while (pos.y + g_t[type].h < 5)
		{
			place_tetr_pat(tmp, g_t + type, pos, '#');
			from_board_to_pattern(p + i, tmp);
			p[i].ntet = type;
			clean_board(tmp, 4);
			i++;
			pos.y++;
		}
		pos.x++;
	}
	return (i);
}

int		create_pattern(t_pattern *p)
{
	t_board	*tmp;
	int		type;
	int		counter;

	type = 0;
	counter = 0;
	tmp = create_board(4);
	while (type < 19)
	{
		counter = fill_pattern(p, tmp, type, counter);
		type++;
	}
	free_board(tmp);
	return (1);
}

int		get_id(t_pattern *p, char *str)
{
	int i;

	i = 0;
	while (p[i].s[0])
	{
		if (ft_strncmp(p[i].s, str, 20) == 0)
		{
			return (p[i].ntet);
		}
		i++;
	}
	return (-1);
}

int		read_file(const int fd, t_tetr **all_read)
{
	t_pattern	p[19 * 16];
	char		buf[22];
	int			i;
	int			nread;

	create_pattern(p);
	i = 0;
	while (i < MAX_FIG)
	{
		nread = read(fd, buf, 21);
		buf[21] = '\0';
		if (get_id(p, buf) == -1)
			return (0);
		else
			all_read[i] = g_t + get_id(p, buf);
		if (nread == 20)
			return (1);
		i++;
	}
	if (i >= MAX_FIG)
		return (0);
	return (1);
}
