/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/09 21:34:05 by hbui             ###   ########.fr       */
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
	tetrimino[SCOL] = 0;
	tetrimino[ECOL] = tetrimino[WIDTH];
}
int countTrailingZero(int x)
{
	int count;
	
	count = 0;
	while ((x & 1) == 0)
	{
		x = x >> 1;
		count++;
	}
	return count;
}
void	ft_left(int *tetrimino)
{
	int	i;
	int	shift;
	int	trail_zero;

	ft_left_scol(tetrimino);
	i = -1;
	shift = 5;
	trail_zero = 0;
	while (tetrimino[++i])
	{
		trail_zero = countTrailingZero(tetrimino[i]);
		if (shift > trail_zero)
			shift = trail_zero;
	}
	i = -1;
	if (!shift)
		return ;
	while (tetrimino[++i])
		tetrimino[i] >>= shift;
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
