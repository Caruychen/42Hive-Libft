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
BDIR = bonus/
INCLUDES = includes/
FUNCTIONS1 = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower
FUNCTIONS2 = memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
FUNCTIONS_BONUS = lstnew lstdelone lstdel iswhitespace memdelarray strdelarray
OBJECTS = $(patsubst %, ft_%.o, $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(patsubst  %, ft_%.c, $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS)) -I.
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

prod:
	gcc -Wall -Wextra -Werror -c $(patsubst  %, $(SRCS)$(P1)ft_%.c, $(FUNCTIONS1)) -c $(patsubst  %, $(SRCS)$(P2)ft_%.c, $(FUNCTIONS2)) -c $(patsubst  %, $(SRCS)$(BDIR)ft_%.c, $(FUNCTIONS_BONUS)) -I$(INCLUDES)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

prod-re: fclean prod
