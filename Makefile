# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 22:53:06 by byan              #+#    #+#              #
#    Updated: 2022/08/06 18:14:23 by byan             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS_		= test.c
SRCS		= so_long.c \
			image.c \
			key.c \
			map.c \
			utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \

OBJS		= $(SRCS:%.c=%.o)
LIBC		= ar rc
FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		gcc $(FLAGS) -c -g $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus