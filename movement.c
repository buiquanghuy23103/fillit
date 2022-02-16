/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/02/16 22:13:53 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	top(t_tetr *tetrimino)
{
	tetrimino->srow = 0;
	tetrimino->erow = tetrimino->height;
}

void	left_scol(t_tetr *tetrimino)
{
	tetrimino->scol = 0;
	tetrimino->ecol = tetrimino->width;
}

static void	reset_bin(int *bin)
{
	int	i;
	int	shift;
	int	trail_zero;

	i = -1;
	shift = 5;
	trail_zero = 0;
	while (bin[++i])
	{
		trail_zero = ft_trailing0bit_count(bin[i]);
		if (shift > trail_zero)
			shift = trail_zero;
	}
	i = -1;
	if (!shift)
		return ;
	while (bin[++i])
		bin[i] >>= shift;
}

void	topleft_scol(t_tetr *tetrimino)
{
	top(tetrimino);
	left_scol(tetrimino);
}

void	topleft(t_tetr *tetrimino)
{
	top(tetrimino);
	reset_bin(tetrimino->bin);
	left_scol(tetrimino);
}
