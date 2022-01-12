/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/12 09:58:46 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *sol, t_tetr *s, int *offbits, int *full)
{
	int	i;

	i = 0;
	while (i < s->tcount)
	{
		if (ft_check_fit(sol + s->tmino[i][SROW], s->tmino[i]))
		{
			ft_add(sol + s->tmino[i][SROW], s->tmino[i], offbits);
			++i;
			continue ;
		}
		while (!ft_move(s->tmino[i], offbits, *full, sol))
		{
			if (i == 0)
			{
				ft_reset_map(s, offbits, full);
				break ;
			}
			else
			{
				ft_topleft_scol(s->tmino[i]);
				ft_rm(sol + s->tmino[i - 1][SROW], s->tmino[i - 1], offbits);
				--i;
			}
		}
	}
}
