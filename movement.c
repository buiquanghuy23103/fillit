/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/10 17:14:57 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top(int *tetrimino)
{
	tetrimino[SROW] = 0;
	tetrimino[EROW] = tetrimino[HEIGHT];
}
void	ft_left_incr(int *tetrimino)
{
	while (*tetrimino)
		*tetrimino++ <<= 1;
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
	while (longest < max && ++shift > -1)
		longest = longest << 1;
	k = -1;
	while (++k < 4 && shift > 0)
		tetrimino[k] = tetrimino[k] << shift;
	tetrimino[SCOL] = 0;
	tetrimino[ECOL] = tetrimino[WIDTH];
}

void	ft_topleft_incr(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left_incr(tetrimino);
	//ft_left(tetrimino);
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

int ft_move(int *solution, int *tetrimino, int *offbits, int full)
{
	if (!(tetrimino[ECOL] ^ tetrimino[SIZE]))
	{
		if (!(tetrimino[EROW] ^ tetrimino[SIZE]))
			return (0);
		tetrimino[SCOL] = 0;
		tetrimino[ECOL] = tetrimino[WIDTH];
		tetrimino[SROW]++;
		tetrimino[EROW]++;
		while ((tetrimino[EROW] ^ tetrimino[SIZE])
		&& (!(solution[tetrimino[SROW]] ^ full) || offbits[tetrimino[SROW] + tetrimino[MAXBIND]] < tetrimino[MAXBITS]))
		{
			++tetrimino[SROW];
			++tetrimino[EROW];
		}
		return (1);
	}
	++tetrimino[SCOL];
	++tetrimino[ECOL];
	return (1);
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
