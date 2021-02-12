# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 07:17:49 by cmalt             #+#    #+#              #
#    Updated: 2021/01/19 10:59:02 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	serialization

CLANG =	clang++ -Wall -Werror -Wextra

SRC =	main.cpp \
		Data.cpp

OBJ =	$(SRC:.cpp=.o)

HEAD =	.

all: $(NAME)

%.o: %.cpp
	$(CLANG) -I $(HEAD) -c $< -o $@

$(NAME): $(OBJ)
	$(CLANG) $^ -I $(HEAD) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all