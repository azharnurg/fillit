/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:00:37 by snechaev          #+#    #+#             */
/*   Updated: 2019/04/16 16:07:21 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_tetr
{
	char			*s;
	int				h;
	int				w;
	int				y[4];
	int				x[4];
}					t_tetr;
typedef struct		s_loc
{
	int				x;
	int				y;
}					t_loc;
typedef struct		s_board
{
	char			*s;
	int				h;
	int				w;
}					t_board;
typedef struct		s_pattern
{
	char			s[21];
	int				ntet;
}					t_pattern;

typedef struct		s_util_v
{
	int				row;
	int				col;
	int				curr_row;
	int				curr_col;
	int				new_row;
	int				new_col;
	int				count;
	int				tetr_num;
	char			letter;
}					t_util_v;

extern t_tetr	g_t[19];
# define MAX_FIG 26
# define ELEM(board, x, y) (board)->s[(y) * ((board)->w) + (x)]

void				from_board_to_pattern(t_pattern *p, t_board *b);
int					create_pattern(t_pattern *p);
int					fill_pattern(t_pattern *p, t_board *tmp, int type,\
									int counter);
int					get_id(t_pattern *p, char *str);
int					read_file(const int fd, t_tetr **all_read);
t_board				*create_board(int sz);
void				free_board(t_board *b);
int					can_place(t_board *b, t_tetr *t, t_loc pos);
int					place_tetr_pat(t_board *b, t_tetr *t, t_loc pos, char symb);
void				clean_board(t_board *b, int sz);
int					find_min_mapsize(t_tetr **all_read);
char				**makemap(int size);
int					ft_solve(t_tetr **all_read);
int					checkp(char **map, t_util_v *uvar, t_tetr *curr);
void				tetr_place (char **map, t_util_v *uvar, t_tetr *curr);
void				tetr_remove (char **map, t_util_v *uvar, t_tetr *curr);
int					r_back(char **map, t_tetr **all_read,\
									int tet_num, t_util_v *uvar);
void				print_board(t_board *b);
void				print_map(char **map);
void				print_tetri(t_tetr **all_read);
void				set_up(int row, int col, int tet_num, t_util_v *uvar);
int					ft_error(char *str);

#endif
