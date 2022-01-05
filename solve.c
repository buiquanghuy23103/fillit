/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/05 15:35:47 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *solution, t_tetr *storage)
{
	int i;

	i = 0;
	while (i < storage->tcount)
	{
		ft_print_tetriminos(storage, i + 1);
		ft_putstr("\n");
		if (ft_check_fit(solution, storage->tmino[i]))
		{
			ft_place_piece(solution, storage->tmino[i]);
			++i;
		}
		else
		{
			while (!ft_right(storage->tmino[i]) && !ft_down(storage->tmino[i]))
			{
				ft_topleft(storage->tmino[i]);
				if (i == 0)
				{
					ft_set_minsize(storage);
				}
				else
				{
					ft_remove_piece(solution, storage->tmino[i - 1]);
					--i;
				}
			}
		}
	}
}
