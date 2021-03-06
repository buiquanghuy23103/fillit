/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/26 22:09:37 by hbui             ###   ########.fr       */
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

static void	ft_left(int *tetrimino)
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
