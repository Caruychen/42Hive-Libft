# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:07:54 by cchen             #+#    #+#              #
#    Updated: 2021/11/05 13:06:06 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/
INCLUDES = includes/
FUNCTIONS = memset bzero memcpy memccpy memmove memchr memcmp strlen
OBJECTS = $(patsubst %, ft_%.o, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(patsubst  %, ft_%.c, $(FUNCTIONS)) -I.
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm $(NAME)

re: fclean all

prod:
	gcc -Wall -Wextra -Werror -c $(patsubst  %, $(SRCS)ft_%.c, $(FUNCTIONS)) -I$(INCLUDES)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

prod-re: fclean prod
