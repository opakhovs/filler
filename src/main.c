/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:00:07 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/15 17:00:08 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_player(t_board *my_board)
{
	char			*map;

	get_next_line(0, &map);
	map = ft_strstr(map, "p");
	map++;
	my_board->player = ft_atoi(map);
	my_board->op = 'o';
	my_board->pl = 'o';
	if (my_board->player == 1)
		my_board->op = 'x';
	else
		my_board->pl = 'x';
}

int		main(void)
{
	int		i;
	t_board	my_board;
	t_piece	my_piece;
	t_coord	solution;

	i = 1;
	ft_player(&my_board);
	while (1)
	{
		ft_board(&my_board, i);
		ft_new_piece(&my_piece);
		find_solution(my_board, my_piece, &solution);
		if ((i = 2) && solution.x == -500)
		{
			ft_putstr("0 0\n");
			break ;
		}
		(my_piece.cut_top != 0) ? (solution.x -= my_piece.cut_top) : 0;
		(my_piece.cut_left != 0) ? (solution.y -= my_piece.cut_left) : 0;
		ft_putnbr(solution.x);
		write(1, " ", 1);
		ft_putnbr(solution.y);
		write(1, "\n", 1);
	}
	return (1);
}
