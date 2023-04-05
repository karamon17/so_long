# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 11:11:54 by gkhaishb          #+#    #+#              #
#    Updated: 2023/04/03 11:11:56 by gkhaishb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

HEADER = so_long.h

HEADER_GNL = get_next_line.h

FLAGS = -Wall -Wextra -Werror

LIBS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c $(HEADER) $(HEADER_GNL)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(HEADER) $(HEADER_GNL) $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
