# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:53:34 by fivieira          #+#    #+#              #
#    Updated: 2023/09/29 16:13:57 by fivieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = sources/so_long.c sources/map.c sources/graphics.c sources/errors.c sources/controls.c

GETNEXTLINE:= get_next_line/get_next_line.c

OBJS = ${SRC:.c=.o}

OBJS_GETNEXTLINE = ${GETNEXTLINE:.c=.o}

LIBRARY := -Lminilibx -lmlx -Ilmlx -lXext -lX11 -lm
MINILIBX := minilibx/

#INCLUDE = headers/ -I .

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Iheaders/

MAKE = make -C

FT_PRINTF_PATH = ft_printf

FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a

all:	${NAME} $(LIBRARY) $(MINILIBX)


$(NAME): ${OBJS} ${OBJS_GETNEXTLINE}
		$(MAKE) $(FT_PRINTF_PATH) 
		$(MAKE) $(MINILIBX)
		$(CC) $(CFLAGS) $(SRC) $(GETNEXTLINE) $(LIBRARY) -o $(NAME) $(FT_PRINTF) $(INCLUDE)

clean:
		${MAKE} ${FT_PRINTF_PATH} clean
		${MAKE} ${MINILIBX} clean
		${RM} ${OBJS} ${OBJS_GETNEXTLINE}


fclean: clean
		${MAKE} ${FT_PRINTF_PATH} fclean
		${MAKE} ${MINILIBX} fclean
		${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re