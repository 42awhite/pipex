# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 20:04:42 by ablanco-          #+#    #+#              #
#    Updated: 2023/10/12 12:11:42 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC	=	main.c find_cmd.c child.c executer.c

OBJS    = ${SRC:.c=.o}
LIB             = ./libft

CC              = gcc
CFLAGS  = -Wall -Wextra -Werror -fsanitize=address

RM              = rm -f

all: ${NAME} libft

${NAME}:        ${OBJS}
		make -C $(LIB)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LIB)/libft.a

exe:
	./$(NAME)

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	make -C $(LIB) clean

fclean: clean
	${RM} ${NAME}
	make -C $(LIB) fclean

re: fclean all

.PHONY: clean exe fclean re all