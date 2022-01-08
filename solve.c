/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/08 03:29:21 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *solution, t_tetr *storage)
{
	int i;

	i = 0;
	while (i < storage->tcount)
	{
		if (ft_check_fit(solution + storage->tmino[i][SROW], storage->tmino[i]))
		{
			ft_place_piece(solution + storage->tmino[i][SROW], storage->tmino[i]);
			++i;
			continue ;
		}
		while ((!ft_right(storage->tmino[i]) && !ft_down(storage->tmino[i])))
		{
			if (i == 0)
			{
				ft_set_minsize(storage);
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
