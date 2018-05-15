# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 17:06:02 by opakhovs          #+#    #+#              #
#    Updated: 2018/04/20 16:08:42 by opakhovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = opakhovs.filler

FLAGS = -Wall -Werror -Wextra

GNL = gnl/get_next_line.c

FILLER =  src/main.c src/finder.c src/reader.c

LIBFT = ./libft/libft.a

COMPILED = $(FILLER:.c=.o) $(GNL:.c=.o)

all: $(NAME)

$(NAME): $(COMPILED) $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(COMPILED) $(LIBFT)

$(LIBFT): liball

liball:
	@make -C ./libft

clean:
	@make clean -C ./libft
	@/bin/rm -f $(COMPILED)

fclean: clean
	@make fclean -C ./libft
	@/bin/rm  -f $(NAME)

re: fclean all
