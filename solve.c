/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/05 14:22:33 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *solution, t_tetr *storage)
{
	int i;

	i = 0;
	while (i < storage->tcount)
	{

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
					break ;
				}
				ft_remove_piece(solution, storage->tmino[i - 1]);
				--i;
			}
		}
	}
}
