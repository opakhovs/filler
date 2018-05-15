/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:20:47 by opakhovs          #+#    #+#             */
/*   Updated: 2018/05/15 18:20:49 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		distance(int xy[2], int xy1[2])
{
	int		i[2];

	i[0] = xy[0] - xy1[0];
	if (i[0] < 0)
		i[0] *= -1;
	i[1] = xy[1] - xy1[1];
	if (i[1] < 1)
		i[1] *= -1;
	return (i[0] + i[1]);
}

int		is_match(t_board map, t_piece piece, int y, int x)
{
	int		col;
	int		i;
	int		j;

	col = 0;
	i = -1;
	while (++i < piece.row && col < 2)
	{
		j = -1;
		while (++j < piece.col && col < 2)
			if (piece.piece[i][j] == '*' && (map.pl == map.board[i + y][j + x]
				|| map.pl - 32 == map.board[i + y][j + x]))
				col++;
			else if (piece.piece[i][j] == '*'
				&& map.board[i + y][j + x] != '.')
				return (0);
	}
	if (col == 1)
		return (1);
	return (0);
}

int		find_better_solution2(t_board map, t_piece piece, int goal[2])
{
	int		i[2];
	int		tmp;
	int		res;

	i[0] = -1;
	res = -1;
	while (++i[0] < map.row && (i[1] = -1))
		while (++i[1] < map.col)
			if (map.board[i[0]][i[1]] == map.op
				|| map.board[i[0]][i[1]] == map.op - 32)
			{
				tmp = distance(i, goal);
				if (res < 0 || res > tmp)
					res = tmp;
			}
	return (res);
}

int		find_better_solution(t_board map, t_piece piece, int xy[2])
{
	int		i[2];
	int		goal[2];
	int		tmp;
	int		res;

	i[0] = -1;
	res = -1;
	while (++i[0] < piece.row && (i[1] = -1))
		while (++i[1] < piece.col)
			if (piece.piece[i[0]][i[1]] == '*')
			{
				goal[0] = i[0] + xy[0];
				goal[1] = i[1] + xy[1];
				tmp = find_better_solution2(map, piece, goal);
				if (res < 0 || res > tmp)
					res = tmp;
			}
	return (res);
}

void	find_solution(t_board map, t_piece piece, t_coord *solution)
{
	int		xy[2];
	int		best_dist;
	int		tmp;

	solution->x = -500;
	solution->y = -500;
	xy[0] = -1;
	best_dist = -1;
	while (piece.row + ++xy[0] <= map.row)
	{
		xy[1] = -1;
		while (piece.col + ++xy[1] <= map.col)
			if (is_match(map, piece, xy[0], xy[1]) > 0)
			{
				tmp = find_better_solution(map, piece, xy);
				if (best_dist < 0 || tmp < best_dist)
				{
					best_dist = tmp;
					solution->x = xy[0];
					solution->y = xy[1];
				}
			}
	}
}
