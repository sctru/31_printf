# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchan <tchan@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 21:10:43 by tchan             #+#    #+#              #
#    Updated: 2017/05/15 21:10:44 by tchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
INC = -I ./include

MAIN = test.c

FILES = ft_printf.c error_check.c  struct_stuff.c \
print_int.c print_s.c print_p.c print_o.c print_x.c print_u.c print_c.c \
ft_base_numlength.c ft_putui_base.c libft_import.c libft_import2.c

OBJ = $(addprefix build/, $(FILES:.c=.o))
SRC = $(FILES)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) crs $@ $^
	echo "Creating $(NAME)"

build/%.o: src/%.c | build
	@echo "Doing things to $@"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

build:
	mkdir build

clean:
	@rm -rf build
	@echo "clean successful"

fclean: clean
	@echo "Removing $(NAME)"
	rm -f $(NAME)

test:
	make re
	$(CC) $(NAME) $(MAIN) $(INC)
	./a.out

re: fclean all
