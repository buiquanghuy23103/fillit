/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/09 10:31:41 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *solution, t_tetr *storage)
{
	int i;
	int	full;

	i = 0;
	full = ft_setbit(0, storage->tmino[0][SIZE]) - 1;
	while (i < storage->tcount)
	{
//		ft_print_tetriminos(storage, i + 1);ft_putchar('\n');
		if (ft_check_fit(solution + storage->tmino[i][SROW], storage->tmino[i]))
		{
			ft_place_piece(solution + storage->tmino[i][SROW], storage->tmino[i]);
			++i;
			continue ;
		}
		while ((!ft_right(storage->tmino[i]) && !ft_down(solution, storage->tmino[i], full)))
		{
			if (i == 0)
			{
				ft_topleft_scol(storage->tmino[i]);
				ft_set_minsize(storage);
				full = (full << 1) + 1;
				while (i < storage->tcount)
					ft_topleft_incr(storage->tmino[i++]);
				i = 0;
				break ;
			}
			else
			{
				ft_topleft_scol(storage->tmino[i]);
				ft_remove_piece(solution + storage->tmino[i - 1][SROW], storage->tmino[i - 1]);
				--i;
			}
		}
	}
}
