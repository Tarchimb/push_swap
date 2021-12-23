# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 08:55:58 by tarchimb          #+#    #+#              #
#    Updated: 2021/12/23 12:07:27 by tarchimb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/operations/ft_push.c		\
				srcs/operations/ft_swap.c		\
				srcs/operations/ft_rotate.c		\
				srcs/operations/ft_rev_rotate.c	\
				srcs/parsing/ft_create_stack.c	\
				srcs/parsing/ft_get_index.c		\
				srcs/algo/little.c				\
				srcs/algo/medium.c				\
				srcs/algo/big.c					\
				srcs/algo/ft_control.c			\
				push_swap.c						\

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	includes/push_swap.h			\
				libft/includes/libft.h			\

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

EXEC		=	push_swap

NAME		=	libpush_swap.a

LIBS 		= 	libft/libft.a					\
				libpush_swap.a					\


RM			=	rm -f

all:		libft ${EXEC}

%.o:		%.c ${INCLUDES}
			${CC} ${CFLAGS} -I ./includes -c $< -o $@


libft:		${INCLUDES}
			make -C ./libft


$(EXEC):	push_swap.c ${LIBS}
			${CC} ${CFLAGS} ${LIBS} push_swap.c -o ${EXEC}

${NAME}:	${OBJS} ${INCLUDES}
			ar rcs ${NAME} ${OBJS}


clean:
			${RM} ${OBJS}
			make clean -C ./libft


fclean:		clean
			make fclean -C ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re libft
