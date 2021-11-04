# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 11:41:26 by cchen             #+#    #+#              #
#    Updated: 2021/11/04 11:02:31 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
UNITS = units/
INCLUDES = includes/
FUNCTIONS := $(shell cat test_files.txt)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror test_main.c $(patsubst %, UNITS/%.c, $(FUNCTIONS)) -I$(INCLUDES) -I.. -L.. -lft -o $(NAME)

fclean:
	/bin/rm $(NAME)

re: fclean all

test-prod:
	gcc -Wall -Wextra -Werror test_main.c $(patsubst %, UNITS/%.c, $(FUNCTIONS)) -I$(INCLUDES) -I../includes -L.. -lft -o $(NAME)
