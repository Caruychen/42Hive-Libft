# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 11:41:26 by cchen             #+#    #+#              #
#    Updated: 2021/11/05 12:49:05 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
UNITS = units/
INCLUDES = includes/
FUNCTIONS := $(shell cat test_files.txt)
PART1 = $(patsubst %, UNITS/p1/%.c, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror test_main.c $(PART1) -I$(INCLUDES) -I.. -L.. -lft -o $(NAME)

fclean:
	/bin/rm $(NAME)

re: fclean all

test-prod:
	gcc -Wall -Wextra -Werror test_main.c $(PART1) -I$(INCLUDES) -I../includes -L.. -lft -o $(NAME)
