# **************************************************************************** # #                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:07:54 by cchen             #+#    #+#              #
#    Updated: 2021/11/07 15:29:32 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/
P1 = p1/
P2 = p2/
INCLUDES = includes/
FUNCTIONS1 = memset bzero memcpy memccpy memmove memchr memcmp strlen
FUNCTIONS2 = putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd
OBJECTS = $(patsubst %, ft_%.o, $(FUNCTIONS1) $(FUNCTIONS2))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(patsubst  %, ft_%.c, $(FUNCTIONS1) $(FUNCTIONS2)) -I.
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm $(NAME)

re: fclean all

prod:
	gcc -Wall -Wextra -Werror -c $(patsubst  %, $(SRCS)$(P1)ft_%.c, $(FUNCTIONS1)) -c $(patsubst  %, $(SRCS)$(P2)ft_%.c, $(FUNCTIONS2)) -I$(INCLUDES)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

prod-re: fclean prod
