/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/06 12:37:51 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *solution, t_tetr *storage)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (!storage->tmino[storage->tcount - 1][ISFIT])
	{
		bt = 0;
		if (ft_check_fit(solution, storage->tmino[i]))
		{
			ft_place_piece(solution, storage->tmino[i]);
			storage->tmino[i][ISFIT] = 1;
			++i;
			continue ;
		}
		while ((!ft_right(storage->tmino[i]) && !ft_down(storage->tmino[i])))
		{
			if (storage->tmino[i][ISFIT])
				storage->tmino[i][ISFIT] = 0;
			if (i == 0)
			{
				ft_topleft(storage->tmino[i]);
				ft_set_minsize(storage);
				while (j < MAXTETRIMINOS)
				{
					ft_topleft(storage->tmino[j]);
					++j;
				}
				j = 0;
				break ;
			}
			else
			{
				ft_topleft(storage->tmino[i]);
				ft_remove_piece(solution, storage->tmino[i - 1]);
				i--;
			}
		}
	}
	/*if (!ft_check_fit(solution, storage->tmino[0]))
		ft_putstr("CHECKFIT WORKS");
	ft_remove_piece(solution, storage->tmino[0]);
	if (ft_check_fit(solution, storage->tmino[0]))
		ft_putstr("REMOVAL WORKS");
	ft_putchar('\n');
	ft_print_tetriminos(storage, 1);*/
}