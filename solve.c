/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/16 20:06:39 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_move(t_tetr *tet, int full, uint16_t *board, int size)
{
	if (tet->ecol == size)
	{
		if (tet->erow == size)
			return (0);
		ft_left_scol(tet);
		while (++(tet->srow) && ++(tet->erow) && tet->erow != size
				&& (board[tet->srow] == full
					|| ft_max1bits(board[tet->srow + tet->maxbind] ^ full) < tet->maxb
					|| ft_max1bits(board[tet->srow + 1] ^ full) < tet->b1))
			;
		return (1);
	}
	++(tet->scol);
	++(tet->ecol);
	return (1);
}

int	ft_solve(t_tetr *s, int count)
{
	int	i;
	int	size;
	int	full;
	uint16_t	sol[16];

	i = 0;
	size = 1;
	full = 1;
	ft_bzero(sol, sizeof(sol));
	while (i < count)
	{
		if (s[i].width > size || s[i].height > size)
		{
			ft_reset(s + 0, &full, &size);
			continue ;
		}
		if (!(*(uint64_t*)(sol + s[i].srow) & (s[i].bin64 << s[i].scol)))
		{
			ft_add(sol + s[i].srow, s + i);
			++i;
			continue ;
		}
		while (!ft_move(s + i, full, sol, size)
			&& (i != 0 || !ft_reset(s + 0, &full, &size)))
		{
			ft_topleft_scol(s + i--);
			ft_rm(sol + s[i].srow, s + i);
		}
	}
	return (size);
}
