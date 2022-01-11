/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/12 00:06:12 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *solution, t_tetr *storage, int *offbits, int *full)
{
	int	i;

	i = 0;
	while (i < storage->tcount)
	{
		if (ft_check_fit(solution + storage->tmino[i][SROW], storage->tmino[i]))
		{
			ft_place_piece(solution + storage->tmino[i][SROW], storage->tmino[i], offbits);
			++i;
			continue ;
		}
		while (!ft_move(storage->tmino[i], offbits, *full, solution))
		{
			if (i == 0)
			{
				ft_reset_map(storage, offbits, full);
				break ;
			}
			else
			{
				ft_topleft_scol(storage->tmino[i]);
				ft_remove_piece(solution + storage->tmino[i - 1][SROW], storage->tmino[i - 1], offbits);
				--i;
			}
		}
	}
}
