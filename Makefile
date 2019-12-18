# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 17:16:51 by tmyrcell          #+#    #+#              #
#    Updated: 2019/12/12 15:20:48 by tmyrcell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./src/*.c
SRCO = ./src/*.o
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/

all: $(NAME)

$(NAME):

	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRC) -L $(LIBFT) -lft

clean:
	rm  -f $(SRCO)
	make -C $(LIBFT) clean

fclean: clean
	rm -f  $(NAME)
	make -C $(LIBFT) fclean

re:	fclean all

.PHONY: all clean fclean re
