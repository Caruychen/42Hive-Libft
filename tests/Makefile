# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 11:41:26 by cchen             #+#    #+#              #
#    Updated: 2021/11/12 12:39:27 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
UNITS = units/
INCLUDES = includes/
FUNCTIONS := $(shell cat test_files.txt)
PARTS = $(patsubst %, $(UNITS)/%.c, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror  test_main.c $(PARTS) -I$(INCLUDES) -I.. -L.. -lft -o $(NAME)

fclean:
	/bin/rm $(NAME)

re: fclean all

test-prod:
	gcc -Wall -Wextra -Werror test_main.c $(PARTS) -I$(INCLUDES) -I../includes -L.. -lft -o $(NAME)
