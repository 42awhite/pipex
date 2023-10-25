# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 20:04:42 by ablanco-          #+#    #+#              #
#    Updated: 2023/10/25 20:25:05 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_bonus

SRC	=	main.c find_cmd.c child.c executer.c
SRC_B = main_bonus.c find_cmd.c child.c executer.c

OBJS    = ${SRC:.c=.o}

BONUS_OBJS = ${SRC_B:.c=.o}

LIB             = ./libft

CC              = gcc
CFLAGS  = -Wall -Wextra -Werror #-fsanitize=address

RM              = rm -f

all: ${NAME} libft

${NAME}: ${OBJS}
		make -C $(LIB)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LIB)/libft.a

${NAME_B}: ${BONUS_OBJS}
		make -C $(LIB)
		$(CC) $(BONUS_OBJS) $(CFLAGS) -o $(NAME_B) $(LIB)/libft.a

exe:
	./$(NAME)

exe_bonus:
	./$(NAME_B)

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	make -C $(LIB) clean

fclean: clean
	${RM} ${NAME} ${NAME_B}
	make -C $(LIB) fclean

re: fclean all

bonus: ${NAME_B} libft


.PHONY: clean exe fclean re all