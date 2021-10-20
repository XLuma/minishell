# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 10:45:54 by gasselin          #+#    #+#              #
#    Updated: 2021/10/19 13:49:51 by gasselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

SRCS	= srcs/main.c srcs/cd.c srcs/echo.c srcs/env.c \
			srcs/exit.c srcs/export.c srcs/pwd.c \
			srcs/unset.c srcs/ft_getenv.c srcs/error.c
OBJS	= $(patsubst $(SRCPATH)/%.c,$(OBJPATH)/%.o,$(SRCS))
SRCPATH	= srcs
OBJPATH	= obj
INC		= includes

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf
MK		= mkdir -p
ECHO	= echo

${OBJPATH}/%.o: ${SRCPATH}/%.c
					${CC} ${CFLAGS} -I. -I${INC}  -c $< -o $@

all :		build-repo ${NAME}

${NAME} :	${OBJS}
			$(MAKE) bonus -C ./libft
			${CC} ${CFLAGS} -Llibft -lft -Llib -lreadline -lhistory -lcurses -fsanitize=address ${OBJS} -o ${NAME}
			@${ECHO} "\n\033[0;32mMinishell-1.0 Compiled!\n\033[0m"

clean :
			$(MAKE) clean -C ./libft
			${RM} ${OBJPATH}

fclean : clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME}

re : fclean all

build-repo :
			@${MK} ${OBJPATH}

.PHONY : all clean fclean re bonus