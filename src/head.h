/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:00:17 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/15 17:00:18 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>

typedef	struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef	struct	s_board
{
	int			col;
	int			row;
	int			player;
	char		op;
	char		pl;
	char		**board;
}				t_board;

typedef	struct	s_piece
{
	int			col;
	int			row;
	int			cut_top;
	int			cut_left;
	char		**piece;
}				t_piece;

void			find_solution(t_board map, t_piece piece, t_coord *solution);
void			ft_board(t_board *my_board, int check);
void			ft_new_piece(t_piece *mp);
void			ft_piece(t_piece *my_piece);

#endif
