# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2021/11/04 18:00:34 by msierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

SRCS		=	./includes/ft_atoi.c				\
		  		./includes/ft_strlen.c				\
				./includes/ft_substr.c				\
				./includes/ft_lstnew_bonus.c		\
		  		./includes/ft_lstadd_front_bonus.c	\
 		  		./includes/ft_lstsize_bonus.c		\
		  		./includes/ft_lstlast_bonus.c		\
 				./includes/ft_lstadd_back_bonus.c	\
				./sources/ft_errors.c				\
				./sources/ft_errors2.c				\
				./sources/ft_logic.c				\
				./sources/ft_logic2.c				\
				./sources/ft_logic3.c				\
				./sources/ft_movements1.c			\
				./sources/ft_movements2.c			\
				./sources/ft_movements3.c			\
				./sources/ft_parseint.c				\
				./sources/ft_sort_into_array.c		\
				./sources/push_swap.c				\

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS 	= -Wall -Werror -Wextra

all	:		$(NAME)

$(NAME)	:	$(OBJS) 
			$(CC) $(OBJS) -o $(NAME) -fsanitize=address

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:	
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
