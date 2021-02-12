# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 09:40:14 by cmalt             #+#    #+#              #
#    Updated: 2020/07/15 09:40:16 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

INCLUDE = -I ./

SRC = ft_printf.c error_find.c flags_width_accuracy_mod.c print_args1.c print_args2.c utils_functions.c utils_functions2.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus: all

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
