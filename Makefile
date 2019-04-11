# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/28 13:21:24 by jvisser        #+#    #+#                 #
#    Updated: 2019/04/04 12:22:48 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
HEADER = fdf.h
FLAGS = -Wall -Wextra -Werror
C_FILES = \
	main.c \
	init_pixels.c \
	rotate.c \
	print.c \
	validate.c \
	utils.c \
	key_press.c \
	key_press2.c \
	offset.c \
	init.c
O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $<

$(NAME): $(O_FILES)
	make -C minilibx_macos
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(O_FILES) -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L libft -lft

clean:
	make -C libft clean
	rm -f $(O_FILES)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean
	make -C minilibx_macos re
	make all
	