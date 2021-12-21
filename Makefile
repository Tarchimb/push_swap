# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 08:55:58 by tarchimb          #+#    #+#              #
#    Updated: 2021/12/21 11:30:09 by tarchimb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/operations/ft_push.c		\
				srcs/operations/ft_swap.c		\
				srcs/operations/ft_rotate.c		\
				srcs/operations/ft_rev_rotate.c	\
				srcs/parsing/ft_create_pile.c	\
				srcs/algorithm/ft_small_sort.c	\
				srcs/utils/ft_get_index.c		\
				srcs/algorithm/ft_medium_sort.c	\

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	Includes/push_swap.h		\
				libft/libft.h				\

LIBINCLUDES	=	-IIncludes

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror -g #-fsanitize=address

NAME		=	./push_swap

LIBS 		= 	Libs/libft.a				\


RM			=	rm -f

all:		${NAME}

%.o:		%.c ${INCLUDES}
			${CC} ${CFLAGS} ${LIBINCLUDES} -c $< -o $@


lib:
			make -C ./Libft


$(NAME):	${OBJS} ${INCLUDES} lib
			${CC} ${CFLAGS} ${LIBS} ${SRCS} push_swap.c -o ${NAME}


clean:
			@${RM} ${OBJS} ${OBJSBONUS}
			make clean -C ./libft


fclean:		clean
			make fclean -C ./libft
			@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
