/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:19:23 by opakhovs          #+#    #+#             */
/*   Updated: 2018/05/15 18:19:43 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_find_left(t_piece *mp)
{
	int		skip;
	int		row_c;

	skip = 0;
	row_c = -1;
	while (skip == 0 && mp->row > 0)
	{
		while (++row_c < mp->row)
			if (mp->piece[row_c][0] == '*')
				skip = 1;
		if (skip == 0 && ++(mp->cut_left) && mp->col--)
			while (--row_c > -1)
				mp->piece[row_c]++;
	}
}

void	ft_find_right(t_piece *mp)
{
	int		skip;
	int		row_c;
	int		col_c;

	skip = 0;
	row_c = -1;
	col_c = mp->col;
	while (skip == 0 && --col_c > 0)
	{
		while (++row_c < mp->row)
			if (mp->piece[row_c][col_c] == '*')
				skip = 1;
		if (skip == 0 && mp->col--)
			while (--row_c > -1)
				mp->piece[row_c][col_c] = '\0';
	}
}

void	ft_piece(t_piece *my_piece)
{
	char	**c;
	char	*map;

	my_piece->cut_top = 0;
	my_piece->cut_left = 0;
	get_next_line(0, &map);
	c = ft_strsplit(map, ' ');
	if (ft_strstr(map, "P"))
	{
		my_piece->row = ft_atoi(c[1]);
		my_piece->col = ft_atoi(c[2]);
	}
	my_piece->piece = (char**)malloc(sizeof(char*) * my_piece->row);
}

void	ft_new_piece(t_piece *mp)
{
	t_coord	count;
	int		skip;
	int		check;
	char	*tmp;

	count.x = 0;
	count.y = -1;
	skip = 0;
	check = 0;
	ft_piece(mp);
	while ((count.y += 1) < mp->row && get_next_line(0, &tmp))
	{
		if (ft_strchr(tmp, '*'))
		{
			mp->piece[count.x] = (char *)malloc(sizeof(char) * mp->col);
			check = 1;
			mp->piece[count.x++] = tmp;
		}
		else if ((++skip) && (check == 0))
			mp->cut_top++;
	}
	mp->row -= skip;
	ft_find_left(mp);
	ft_find_right(mp);
}

void	ft_board(t_board *my_board, int check)
{
	char	**splited;
	char	*coord;
	char	*map;
	int		i;

	i = -1;
	get_next_line(0, &coord);
	if (check == 1)
	{
		splited = ft_strsplit(coord, ' ');
		my_board->row = ft_atoi(splited[1]);
		my_board->col = ft_atoi(splited[2]);
	}
	my_board->board = (char**)malloc(sizeof(char*) * my_board->row);
	get_next_line(0, &map);
	while (++i < my_board->row)
	{
		my_board->board[i] = (char*)malloc(sizeof(char) * my_board->col);
		get_next_line(0, &map);
		my_board->board[i] = map + 4;
	}
}
