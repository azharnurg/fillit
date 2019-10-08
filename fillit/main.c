/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:45:12 by snechaev          #+#    #+#             */
/*   Updated: 2019/04/16 15:51:37 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_error(char *str)
{
	ft_putendl(str);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_tetr	*all_read[MAX_FIG];

	ft_memset(all_read, 0, sizeof(t_tetr *) * MAX_FIG);
	i = 1;
	if (argc != 2)
		return (ft_error("Usage: ./fillit User_File"));
	if ((fd = open(argv[i], O_RDONLY)) < 0)
		return (ft_error("error"));
	if (!(read_file(fd, all_read)))
	{
		ft_error("error");
		return (0);
	}
	ft_solve(all_read);
	return (0);
}
