# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asibille <asibille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 18:22:28 by asibille          #+#    #+#              #
#    Updated: 2022/03/29 07:03:46 by asibille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = input_to_mat_utils.c exit.c fdf.c ft_axis.c ft_base.c ft_fill_param.c ft_linkall.c  ft_sum_cord_mat.c ft_utils1.c input_to_mat.c keyevent.c keyevent_utils.c

OBJS = ${SRCS:.c=.o}

NAME = fdf

MLXFLAGS = -L minilibx  -lmlx -framework OpenGL -framework AppKit 

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	make -C libft
	make -C minilibx
	mv minilibx/libmlx.dylib .
	gcc ${MLXFLAGS} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}
	
all: ${NAME}

clean:
	make clean -C libft
	make clean -C minilibx
	rm -rf ${OBJS} 

fclean: clean
	make fclean -C libft
	rm -rf libmlx.dylib
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re