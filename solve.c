/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/05 14:42:47 by jpikkuma         ###   ########.fr       */
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
			//ft_putnbr(i);
			//ft_putchar('\n');
		}
		else
		{
			ft_putnbr(storage->tmino[i][SIZE]);
			ft_putchar('\n');
			while (!ft_right(storage->tmino[i]) && !ft_down(storage->tmino[i]))
			{
				ft_topleft(storage->tmino[i]);
				if (i == 0)
				{
					ft_set_minsize(storage);
					ft_putnbr(storage->tmino[i][SIZE]);
					ft_putchar('\n');
				}
				else
				{
					ft_remove_piece(solution, storage->tmino[i - 1]);
					--i;
					ft_putnbr(storage->tmino[i][SIZE]);
					ft_putchar('\n');
				}
				ft_putnbr(storage->tmino[i][SIZE]);
				ft_putchar('\n');
			}
		}
	}
}
