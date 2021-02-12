# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/03 14:03:17 by cmalt             #+#    #+#              #
#    Updated: 2021/01/05 12:10:09 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CLANG = clang++ -Wall -Werror -Wextra

SRC =	phonebook.cpp \
		Contact.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CLANG) -c $< -o $@

$(NAME): $(OBJ)
	$(CLANG) $^ -I ./ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all