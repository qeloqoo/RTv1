# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 18:28:04 by mdubrovs          #+#    #+#              #
#    Updated: 2017/03/04 18:28:12 by mdubrovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
FLAGS = -Wall -Wextra -Werror -g
FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit
SRCS = main.c \
		raytrace.c \
		prim_funcs.c \
		list_funcs.c \
		draw_funcs.c \
		vector_ops.c \
		vector_ops2.c \
		quat_ops.c \
		quat_ops2.c \
		file_read.c \
		file_read2.c \
		var_math.c \
		light.c \
		plane.c \
		sphere.c \
		cylinder.c \
		cone.c \
		color.c \
		controls.c
HEADERS = rtv1.h
BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) libft/libft.a minilibx/libmlx.a

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
