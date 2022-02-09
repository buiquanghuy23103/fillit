/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/02/09 19:59:03 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top(t_tetr *tetrimino)
{
	tetrimino->srow = 0;
	tetrimino->erow = tetrimino->height;
}

void	ft_left_scol(t_tetr *tetrimino)
{
	tetrimino->scol = 0;
	tetrimino->ecol = tetrimino->width;
}

static void	ft_left(int *bin)
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

void	ft_topleft_scol(t_tetr *tetrimino)
{
	ft_top(tetrimino);
	ft_left_scol(tetrimino);
}

void	ft_topleft(t_tetr *tetrimino)
{
	ft_top(tetrimino);
	ft_left(tetrimino->bin);
	ft_left_scol(tetrimino);
}
