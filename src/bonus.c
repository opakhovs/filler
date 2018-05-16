/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:42:24 by opakhovs          #+#    #+#             */
/*   Updated: 2018/05/16 14:42:26 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		printf_color(char check)
{
	char	esc;

	esc = 27;
	if (check == 'r' && write(1, &esc, 1))
		write(1, "[31m", 4);
	else if (check == 'g' && write(1, &esc, 1))
		write(1, "[32m", 4);
	else if (check == 'R' && write(1, &esc, 1))
		write(1, "[0m", 3);
	else if (check == 'y' && write(1, &esc, 1))
		write(1, "[33m", 4);
	return (1);
}

void	put_color(void)
{
	int		i;
	char	*line;

	while (get_next_line(0, &line) && ft_strstr(line, "Piece") == 0)
	{
		write(1, "\n", 1);
		i = 4;
		while (printf_color('R') && line[i])
		{
			if (line[i] == 'X' && printf_color('r'))
				write(1, &line[i], 1);
			else if (line[i] == 'O' && printf_color('g'))
				write(1, &line[i], 1);
			else if ((line[i] == 'o' || line[i] == 'x') && printf_color('y'))
				write(1, &line[i], 1);
			else
				write(1, &line[i], 1);
			i++;
		}
		ft_strdel(&line);
	}
	write(1, "\n", 1);
	if (ft_strstr(line, "Piece") != 0)
		write(1, line, ft_strlen(line));
}

void	who_won(int o, int x)
{
	write(1, "\n", 1);
	if (printf_color('R') && x > o && printf_color('y'))
		write(1, "Player 2 won!\n", 14);
	else if (printf_color('R') && x < o && printf_color('y'))
		write(1, "Player 1 won!\n", 14);
	else if (printf_color('R') && x == o && printf_color('y'))
		write(1, "Draw!\n", 6);
}

int		main(void)
{
	char	*ln;
	int		x;
	int		o;

	get_next_line(0, &ln);
	ft_strdel(&ln);
	while (get_next_line(0, &ln) && printf_color('R'))
	{
		if (ft_strstr(ln, "    ") != 0)
			put_color();
		else
		{
			write(1, "\n", 1);
			if (ft_strstr(ln, "== O") != 0 && printf_color('g'))
				write(1, ln, ft_strlen(ln)) && (o = ft_atoi(ln + 9));
			else if (ft_strstr(ln, "== X") != 0 && printf_color('r'))
				write(1, ln, ft_strlen(ln)) && (x = ft_atoi(ln + 9));
			else
				write(1, ln, ft_strlen(ln));
		}
	}
	who_won(o, x);
	return (1);
}
