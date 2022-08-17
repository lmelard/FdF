# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 14:53:02 by lmelard           #+#    #+#              #
#    Updated: 2022/05/25 10:59:42 by lmelard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./src/draw_line/big_slope.c \
		./src/draw_line/draw_line.c \
		./src/draw_line/draw_map.c \
		./src/draw_line/my_pixel_put.c \
		./src/draw_line/small_slope.c \
		./src/draw_line/straight_lines.c \
		./src/get_next_line/get_next_line_utils.c\
		./src/get_next_line/get_next_line.c \
		./src/isometric_projection/isometric.c \
		./src/read_file/atoi.c \
		./src/read_file/del_struct.c \
		./src/read_file/init_struct.c \
		./src/read_file/map_size.c \
		./src/read_file/read_file.c \
		./src/read_file/split.c \
		./src/quit_window/quit.c \
		./src/main.c

OBJ = ${SRC:.c=.o}

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

LIBFLAGS = -lXext -lX11 -lm -lz

.c.o:
	${CC} ${CFLAGS} -I includes -I mlx_linux -g3 -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
	@echo "Compiling the minilibx..."
	@make -C mlx_linux
	@echo "Compiling the FdF part..."
	${CC} ${CFLAGS} ${OBJ} -lmlx -L mlx_linux -I mlx_linux ${LIBFLAGS} -o ${NAME}
	@echo "---->FdF is ready to be used - USAGE: ./fdf [path/to/map] <-----"

all: ${NAME}

clean:
	@echo "Removing minilibx's objects..."
	@make clean -C mlx_linux
	@echo "Removing fdf's objects..."
	${RM} ${OBJ}

fclean: clean
	@echo "Removing fdf.."
	${RM} ${NAME}
	@echo "Cleaning done!"

re: fclean all

.PHONY: all re clean fclean
