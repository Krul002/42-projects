# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 19:39:18 by cmalt             #+#    #+#              #
#    Updated: 2021/01/07 01:14:27 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		replace

SRC =		main.cpp \
			Replace.cpp

OBJ =		$(SRC:.cpp=.o)

CLANG =		clang++ -Wall -Wextra -Werror

INCLUDE =	./

all: $(NAME)

%.o: %.cpp
	$(CLANG) -c $< -o $@

$(NAME): $(OBJ)
	$(CLANG) $^ -I $(INCLUDE) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)
    
re: fclean all

.PHONY: all clean fclean re