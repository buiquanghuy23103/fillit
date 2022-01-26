/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/26 20:35:37 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_move(int *tet, int *ofb, int full, int *sol)
{
	if (tet[ECOL] == tet[SIZE] || ofb[tet[SROW] + tet[MAXBIND]] < tet[MAXB])
	{
		if (!(tet[EROW] ^ tet[SIZE]))
			return (0);
		ft_left_scol(tet);
		while (++tet[SROW] && ++tet[EROW] && ((tet[EROW] ^ tet[SIZE])
				&& (!(sol[tet[SROW]] ^ full)
					|| ofb[tet[SROW]] < tet[B0] || ofb[tet[SROW] + 1] < tet[B1]
					|| ft_max1bits(sol[tet[SROW] + tet[MAXBIND]] ^ full)
					< tet[MAXB]
					|| ft_max1bits(sol[tet[SROW] + 1] ^ full) < tet[B1])))
			;
		return (1);
	}
	while (++tet[SCOL] && ++tet[ECOL] && tet[ECOL] < tet[SIZE]
		&& !ft_check_fit(sol + tet[SROW], tet))
		;
	return (1);
}

void	ft_solve(int *sol, t_tetr *s, int *offbits, int *full)
{
	int	i;

	i = 0;
	while (i < s->tcount)
	{
		if (s->tmino[i][WIDTH] > s->tmino[i][SIZE]
			|| s->tmino[i][HEIGHT] > s->tmino[i][SIZE])
			ft_reset(s, offbits, full);
		if (ft_check_fit(sol + s->tmino[i][SROW], s->tmino[i])
			&& ft_add(sol + s->tmino[i][SROW], s->tmino[i], offbits) && ++i > 0)
			continue ;
		while (!ft_move(s->tmino[i], offbits, *full, sol)
			&& (i != 0 || !ft_reset(s, offbits, full)))
		{
			ft_topleft_scol(s->tmino[i]);
			ft_rm(sol + s->tmino[i - 1][SROW], s->tmino[i - 1], offbits);
			--i;
		}
	}
}
