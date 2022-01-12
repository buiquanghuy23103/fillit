/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/12 07:44:59 by hbui             ###   ########.fr       */
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
		trail_zero = ft_trailing0bit_count(tetrimino[i]);
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
	ft_left_scol(tetrimino);
}

void	ft_topleft(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left(tetrimino);
}

void	ft_one_down(int *tet)
{
	++tet[SROW];
	++tet[EROW];
}

void	ft_one_right(int *tet)
{
	++tet[SCOL];
	++tet[ECOL];
}

int	ft_move(int *tet, int *ofb, int full, int *sol)
{
	int row;

	row = tet[tet[MAXBIND]];
	if (tet[ECOL] == tet[SIZE] || ofb[tet[SROW] + tet[MAXBIND]] < tet[MAXBITS])
	{
		if (!(tet[EROW] ^ tet[SIZE]))
			return (0);
		ft_left_scol(tet);
		ft_one_down(tet);
		while ((tet[EROW] ^ tet[SIZE]) && (!(sol[tet[SROW]] ^ full)
			|| ofb[tet[SROW]] < tet[BITS0] || ofb[tet[SROW] + 1] < tet[BITS1]
			|| ft_max1bits(sol[tet[SROW] + tet[MAXBIND]] ^ full) < tet[MAXBITS]
			|| ft_max1bits(sol[tet[SROW] + 1] ^ full) < tet[BITS1]))
			ft_one_down(tet);
		return (1);
	}
	ft_one_right(tet);
	while (!(sol[tet[SROW] + tet[MAXBIND]] ^ row))
	{
		if (tet[ECOL] == tet[SIZE])
			return (0);
		ft_one_right(tet);
		row <<= 1;
	}
	return (1);
}
