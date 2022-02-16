/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/16 22:38:44 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	apply(t_tetr tetr, int p[16][16], int c, int size)
{
	int	j;
	int	k;

	k = 0;
	j = size - 1;
	while (k < tetr.height)
	{
		while (j >= 0)
		{
			if (ft_getbit(tetr.bin[k] << tetr.scol, j))
				p[tetr.srow + k][j] = c;
			--j;
		}
		j = size - 1;
		++k;
	}
}

void	print(t_tetr *t, int tcount, int size)
{
	int	board[16][16];
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			board[i][j] = '.';
	}
	i = -1;
	while (++i < tcount)
		apply(t[i], board, 'A' + i, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(board[i][j]);
		ft_putchar('\n');
	}
}
