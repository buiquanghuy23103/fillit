/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/11 22:19:30 by hbui             ###   ########.fr       */
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

int maxConsecutiveOnes(int x)
{
    int count = 0;

    while (x!=0)
    {
        x = (x & (x << 1));

        count++;
    }

    return count;
}

int	ft_move(int *tetrimino, int *offbits, int full, int *solution)
{
	int row;

	row = tetrimino[tetrimino[MAXBIND]];
	if (tetrimino[ECOL] == tetrimino[SIZE]
	|| offbits[tetrimino[SROW] + tetrimino[MAXBIND]] < tetrimino[MAXBITS])
	{
		if (!(tetrimino[EROW] ^ tetrimino[SIZE]))
			return (0);
		ft_left_scol(tetrimino);
		tetrimino[SROW]++;
		tetrimino[EROW]++;
		while (
			(tetrimino[EROW] ^ tetrimino[SIZE])
			&& (
				!(solution[tetrimino[SROW]] ^ full)
					|| offbits[tetrimino[SROW] + tetrimino[MAXBIND]] < tetrimino[MAXBITS]
					|| maxConsecutiveOnes(solution[tetrimino[SROW] + tetrimino[MAXBIND]] ^ full) < tetrimino[MAXBITS]
					|| maxConsecutiveOnes(solution[tetrimino[SROW]] ^ full) < tetrimino[BITS0]
					|| maxConsecutiveOnes(solution[tetrimino[SROW] + 1] ^ full) < tetrimino[BITS1]
				)
			)
		{
			++tetrimino[SROW];
			++tetrimino[EROW];
		}
		return (1);
	}
	++tetrimino[SCOL];
	++tetrimino[ECOL];
	while (!(solution[tetrimino[SROW] + tetrimino[MAXBIND]] ^ row))
	{
		if (tetrimino[ECOL] == tetrimino[SIZE])
			return (0);
		++tetrimino[SCOL];
		++tetrimino[ECOL];
		row <<= 1;
	}
	return (1);
}

int	ft_right(int *tetrimino, int *offbits, int full, int *solution)
{
	int	size;
	(void)full;
	int row;

	row = tetrimino[MAXBIND];
	size = tetrimino[SIZE];
	if (tetrimino[ECOL] == size || offbits[tetrimino[SROW] + tetrimino[MAXBIND]] < tetrimino[MAXBITS])
		return (0);
	++tetrimino[SCOL];
	++tetrimino[ECOL];
	while (!(solution[tetrimino[SROW] + tetrimino[MAXBIND]] ^ row))
	{
		if (tetrimino[ECOL] == size)
			break ;
		++tetrimino[SCOL];
		++tetrimino[ECOL];
		row >>= 1;
	}
	return (1);
}

int	ft_down(int *solution, int *tetrimino, int *offbits, int full)
{
	if (!(tetrimino[EROW] ^ tetrimino[SIZE]))
		return (0);
	tetrimino[SCOL] = 0;
	tetrimino[ECOL] = tetrimino[WIDTH];
	tetrimino[SROW]++;
	tetrimino[EROW]++;
	while ((!(solution[tetrimino[SROW]] ^ full) || offbits[tetrimino[SROW] + tetrimino[MAXBIND]] < tetrimino[MAXBITS])
	&& (tetrimino[EROW] ^ tetrimino[SIZE]))
	{
		++tetrimino[SROW];
		++tetrimino[EROW];
	}
	return (1);
}
