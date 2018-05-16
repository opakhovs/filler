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

COLOR = src/bonus.c

LIBFT = ./libft/libft.a

COMPILED = $(FILLER:.c=.o) $(GNL:.c=.o)

COLOR_COM = $(COLOR:.c=.o) $(GNL:.c=.o)

all: $(NAME)

$(NAME): $(COMPILED) $(LIBFT) $(COLOR_COM)
	@gcc $(FLAGS) -o $(NAME) $(COMPILED) $(LIBFT)
	@gcc $(FLAGS) -o colors $(COLOR_COM) $(LIBFT)

$(LIBFT): liball

liball:
	@make -C ./libft

clean:
	@make clean -C ./libft
	@/bin/rm -f $(COMPILED) $(COLOR_COM)

fclean: clean
	@make fclean -C ./libft
	@/bin/rm  -f $(NAME) colors

re: fclean all
