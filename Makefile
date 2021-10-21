# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 10:45:54 by gasselin          #+#    #+#              #
#    Updated: 2021/10/21 12:18:09 by gasselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

SRCS	= srcs/main.c srcs/error.c srcs/builtins/cd.c srcs/builtins/echo.c \
			srcs/builtins/env.c srcs/builtins/exit.c srcs/builtins/export.c \
			srcs/builtins/pwd.c srcs/builtins/unset.c srcs/builtins/ft_getenv.c 
			
OBJLST	= obj/main.o obj/cd.o obj/echo.o obj/env.o \
			obj/exit.o obj/export.o obj/pwd.o \
			obj/unset.o obj/ft_getenv.o obj/error.o

OBJS	= ${SRCS:.c=.o}

SRCPATH	= srcs
OBJPATH	= obj

INC		= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -I${INC}
RM		= rm -rf
MK		= mkdir -p
ECHO	= echo

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all :		${NAME}

${NAME} :	${OBJS}
			$(MAKE) bonus -C ./libft
			${CC} ${CFLAGS} -Llibft -lft -Llib -lreadline -lhistory -lcurses -fsanitize=address ${OBJS} -o ${NAME}
			@${ECHO} "\n\033[0;32mMinishell-1.0 Compiled!\n\033[0m"

clean :
			$(MAKE) clean -C ./libft
			${RM} ${OBJS}

fclean : clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME}

re : fclean all

build-repo :
			@${MK} ${OBJPATH}

.PHONY : all clean fclean re bonus