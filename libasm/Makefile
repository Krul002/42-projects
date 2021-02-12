# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 13:05:06 by cmalt             #+#    #+#              #
#    Updated: 2020/10/25 17:16:36 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = gcc

C_FLAGS = -Wall -Werror -Wextra

NAME = libasm.a

NASM = nasm

NA_FLAGS = -f macho64

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s \
		ft_strdup.s

OBJS = $(SRCS:.s=.o)

INCLUDE = ./

MAIN = main.c

MAIN_OBJ = $(MAIN:.c=.o)

all: $(NAME)

%.o:		%.s 
	$(NASM) $(NA_FLAGS) $<

%.o:		%.c
	$(CLANG) $(C_FLAGS) -c $(MAIN) -I $(INCLUDE)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $^
	ranlib $(NAME)

test: $(MAIN_OBJ) $(NAME)
	$(CLANG) $(C_FLAGS)  $^  -I $(INCLUDE) -o test

clean:
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

.PHONY: all clean fclean re