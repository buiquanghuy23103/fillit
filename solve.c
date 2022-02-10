/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/10 15:45:02 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_fit(int *dst, int *bin, int scol)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((bin[i] << scol) & *dst)
			return (0);
		i++;
		dst++;
	}
	return (1);
}

static int	ft_move(t_tetr *tet, int *ofb, int full, int *sol, int size)
{
	if (tet->ecol == size || ofb[tet->srow + tet->maxbind] < tet->maxb)
	{
		if (tet->erow == size)
			return (0);
		ft_left_scol(tet);
		while (++(tet->srow) && ++(tet->erow) && tet->erow != size
				&& (sol[tet->srow] == full
					|| ofb[tet->srow] < tet->b0 || ofb[tet->srow + 1] < tet->b1
					|| ft_max1bits(sol[tet->srow + tet->maxbind] ^ full) < tet->maxb
					|| ft_max1bits(sol[tet->srow + 1] ^ full) < tet->b1))
			;
		return (1);
	}
	while (++(tet->scol) && ++(tet->ecol) && tet->ecol < size
		&& !ft_check_fit(sol + tet->srow, tet->bin, tet->scol))
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
		if (s[i].width > size || s[i].height > size)
		{
			ft_reset(s + 0, offbits, &full, &size);
			continue ;
		}
		if (ft_check_fit(sol + s[i].srow, s[i].bin, s[i].scol)
			&& ft_add(sol + s[i].srow, s + i, offbits) && ++i > 0)
			continue ;
		while (!ft_move(s + i, offbits, full, sol, size)
			&& (i != 0 || !ft_reset(s + 0, offbits, &full, &size)))
		{
			ft_topleft_scol(s + i--);
			ft_rm(sol + s[i].srow, s + i, offbits);
		}
	}
	return (size);
}
