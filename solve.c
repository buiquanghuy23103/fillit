/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/09 15:14:23 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_move(int *tet, int *ofb, int full, int *sol, int size)
{
	if (tet[ECOL] == size || ofb[tet[SROW] + tet[MAXBIND]] < tet[MAXB])
	{
		if (!(tet[EROW] ^ size))
			return (0);
		ft_left_scol(tet);
		while (++tet[SROW] && ++tet[EROW] && ((tet[EROW] ^ size)
				&& (!(sol[tet[SROW]] ^ full)
					|| ofb[tet[SROW]] < tet[B0] || ofb[tet[SROW] + 1] < tet[B1]
					|| ft_max1bits(sol[tet[SROW] + tet[MAXBIND]] ^ full)
					< tet[MAXB]
					|| ft_max1bits(sol[tet[SROW] + 1] ^ full) < tet[B1])))
			;
		return (1);
	}
	while (++tet[SCOL] && ++tet[ECOL] && tet[ECOL] < size
		&& !ft_check_fit(sol + tet[SROW], tet))
		;
	return (1);
}

int	ft_solve(t_tetr *s, int count)
{
	int	i;
	int	size;
	int	full;
	int		sol[16];
	int		offbits[17];

	i = 0;
	size = 1;
	full = 1;
	ft_bzero(sol, sizeof(sol));
	ft_bzero(offbits, sizeof(offbits));
	while (i < count)
	{
		if (s->tmino[i][WIDTH] > size
			|| s->tmino[i][HEIGHT] > size)
			{
				ft_reset(s, offbits, &full, &size);
				continue ;
			}
		if (ft_check_fit(sol + s->tmino[i][SROW], s->tmino[i])
			&& ft_add(sol + s->tmino[i][SROW], s->tmino[i], offbits) && ++i > 0)
			continue ;
		while (!ft_move(s->tmino[i], offbits, full, sol, size)
			&& (i != 0 || !ft_reset(s, offbits, &full, &size)))
		{
			ft_topleft_scol(s->tmino[i]);
			ft_rm(sol + s->tmino[i - 1][SROW], s->tmino[i - 1], offbits);
			--i;
		}
	}
	return (size);
}
