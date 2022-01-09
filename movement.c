/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/09 18:06:22 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top(int *tetrimino)
{
	tetrimino[SROW] = 0;
	tetrimino[EROW] = tetrimino[HEIGHT];
}

void	ft_left_scol(int *tetrimino)
{
	int k;

	k = tetrimino[SCOL];
	tetrimino[SCOL] = 0;
	tetrimino[ECOL] = tetrimino[WIDTH];
}

void	ft_left(int *tetrimino)
{
	int	max;
	int	k;
	int	longest;
	int	shift;

	max = ft_setbit(0, tetrimino[SIZE]);
	longest = 0;
	k = 0;
	shift = -1;
	while (k < 4)
	{
		if (tetrimino[k] > longest)
			longest = tetrimino[k];
		k++;
	}
	while (!(longest % 2) && ++shift > -1)
		longest = longest >> 1;
	k = -1;
	while (++k < 4 && shift > 0)
		tetrimino[k] = tetrimino[k] >> shift;
	tetrimino[SCOL] = 0;
	tetrimino[ECOL] = tetrimino[WIDTH];
}

void	ft_topleft_scol(int *tetrimino)
{
	ft_top(tetrimino);
	//ft_left(tetrimino);
	ft_left_scol(tetrimino);
}

void	ft_topleft(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left(tetrimino);
}

int	ft_right(int *tetrimino)
{
	if (tetrimino[ECOL] == tetrimino[SIZE])
		return (0);
	++tetrimino[SCOL];
	++tetrimino[ECOL];
	return (1);
}

int	ft_down(int *solution, int *tetrimino, int *offbits, int full)
{
	if (!(tetrimino[EROW] ^ tetrimino[SIZE]))
		return (0);
	ft_left_scol(tetrimino);
	tetrimino[SROW]++;
	tetrimino[EROW]++;
	while ((!(solution[tetrimino[SROW]] ^ full) || offbits[tetrimino[SROW]] < tetrimino[BITS0])
	&& (tetrimino[EROW] ^ tetrimino[SIZE]))
	{
		++tetrimino[SROW];
		++tetrimino[EROW];
	}
	return (1);
}
