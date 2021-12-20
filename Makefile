# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 12:47:55 by cchen             #+#    #+#              #
#    Updated: 2021/12/20 12:53:27 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/
P1 = p1/
P2 = p2/
BDIR = bonus/
VECDIR = vector/
INCLUDES = includes/
FUNCTIONS1 = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii isprint toupper tolower
FUNCTIONS2 = memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd
FUNCTIONS_BONUS = lstnew lstdelone lstdel lstadd lstiter lstmap iswhitespace memdelarray strdelarray isupper islower
FUNCTIONS_VECTOR = vecnew vecfree
FUNCTIONS= $(FUNCTIONS1) $(FUNCTIONS2) $(FUNCTIONS_BONUS) $(FUNCTIONS_VECTOR)
OBJECTS = $(patsubst %, ft_%.o, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(patsubst  %, ft_%.c, $(FUNCTIONS)) -I.
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

prod:
	gcc -Wall -Wextra -Werror -c $(patsubst  %, $(SRCS)$(P1)ft_%.c, $(FUNCTIONS1)) -c $(patsubst  %, $(SRCS)$(P2)ft_%.c, $(FUNCTIONS2)) -c $(patsubst  %, $(SRCS)$(BDIR)ft_%.c, $(FUNCTIONS_BONUS)) -c $(patsubst  %, $(SRCS)$(VECDIR)ft_%.c, $(FUNCTIONS_VECTOR)) -I$(INCLUDES)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

prod-re: fclean prod
