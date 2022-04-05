# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asibille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 11:53:37 by asibille          #+#    #+#              #
#    Updated: 2022/01/11 13:34:32 by asibille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c ft_memcpy.c ft_memset.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_tolower.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c ft_memmove.c ft_strchr.c ft_strncmp.c ft_strrchr.c ft_toupper.c ft_strlcpy.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	ar r ${NAME} ${OBJS}
	
all: ${NAME}

bonus: all ${OBJSB}
	ar r ${NAME} ${OBJSB}

clean: 
	rm -rf ${OBJS} ${OBJSB}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
