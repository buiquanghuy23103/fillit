/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/16 17:25:14 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_fit(uint16_t *board, uint64_t bin64, int scol)
{
	uint64_t	board64;
	uint64_t	tetr64;

	board64 = *(uint64_t*)board;
	tetr64 = bin64 << scol;
	return !(board64 & tetr64);
}

static int	ft_move(t_tetr *tet, int *ofb, int full, uint16_t *board, int size)
{
	if (tet->ecol == size || ofb[tet->srow + tet->maxbind] < tet->maxb)
	{
		if (tet->erow == size)
			return (0);
		ft_left_scol(tet);
		while (++(tet->srow) && ++(tet->erow) && tet->erow != size
				&& (board[tet->srow] == full
					|| ofb[tet->srow] < tet->b0 || ofb[tet->srow + 1] < tet->b1
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
	int		offbits[17];

	i = 0;
	size = 1;
	full = 1;
	ft_bzero(sol, sizeof(sol));
	ft_bzero(offbits, sizeof(offbits));
	while (i < count)
	{
		if (s[i].width > size || s[i].height > size)
		{
			ft_reset(s + 0, offbits, &full, &size);
			continue ;
		}
		if (ft_check_fit(sol + s[i].srow, s[i].bin64, s[i].scol))
		{
			ft_add(sol + s[i].srow, s + i, offbits);
			++i;
			continue ;
		}
		while (!ft_move(s + i, offbits, full, sol, size)
			&& (i != 0 || !ft_reset(s + 0, offbits, &full, &size)))
		{
			ft_topleft_scol(s + i--);
			ft_rm(sol + s[i].srow, s + i, offbits);
		}
	}
	return (size);
}
