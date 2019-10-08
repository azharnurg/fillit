# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurgali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 21:22:40 by anurgali          #+#    #+#              #
#    Updated: 2019/04/17 21:27:07 by anurgali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

SRCS	= main.c \
		  board_utilits.c \
		  map.c \
		  read_file.c \
		  solve.c \
		  tetr_operation.c \
		  tetrimino.c \

OBJ =		${SRCS:.c=.o}

INCLUDE	=	-I ./libft/ -L ./libft -lft

all: $(NAME)

$(OBJ): $(SRCS)
		@$(CC) $(FLAG) -c $*.c

$(NAME): $(OBJ)
		@make all -C libft
		@$(CC) $(FLAG) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
		@make clean -C libft
		@/bin/rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean

