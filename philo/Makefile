# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 14:57:28 by beredzhe          #+#    #+#              #
#    Updated: 2024/04/17 11:49:50 by beredzhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc -pthread

CFLAGS	=	-Werror -Wextra -Wall

SRC		=	checks.c\
			helper.c\
			init.c\
			main.c\
			philo_utils.c\
			routine.c\
			thread.c\

all:	$(NAME)

$(NAME):	$(SRC)
	@echo "\033[33mCompiling..."
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "\033[32mCompilation done!\033[0m"

clean:
	@echo "\033[31mCleaning..."
	@rm -rf $(NAME)
	@echo "\033[32mClean done!\033[0m"
	
fclean:
	@echo "\033[31mFull cleaning..."
	@rm -rf $(NAME)
	@echo "\033[32mFull clean done!\033[0m"

re: fclean all
