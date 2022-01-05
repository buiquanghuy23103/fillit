/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/05 17:03:47 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printsol(int *sol)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		ft_putnbr(sol[i]);
		ft_putchar('\n');
		i++;
	}
}
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
				}
				else
				{
					ft_printsol(solution);
					ft_remove_piece(&solution, storage->tmino[i - 1]);
					ft_putstr("Remove piece\n");
					ft_printsol(solution);
					ft_putstr("========\n");
					--i;
				}
			}
		}
	}
}

